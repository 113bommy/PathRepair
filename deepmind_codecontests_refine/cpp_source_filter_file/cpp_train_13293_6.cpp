#include <bits/stdc++.h>
using namespace std;
pair<pair<long long int, long long int>, int> queries[10000];
bitset<32000000> bs;
vector<int> primes;
long long int dist[100000];
priority_queue<pair<long long int, int> > H;
int ans[10000];
int main() {
  int i;
  int t;
  long long int n, k;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
    scanf("%I64d %I64d", &n, &k), queries[i] = make_pair(make_pair(k, n), i);
  sort(queries, queries + t);
  int j;
  bs.set();
  bs[0] = bs[1] = 0;
  for (i = 2; i < 32000000; i++) {
    if (bs[i]) {
      if (i < 6000) {
        for (j = i * i; j < 32000000; j += i) bs[j] = 0;
      }
      primes.push_back(i);
    }
  }
  vector<long long int> f;
  for (i = 0; i < t; i++) {
    k = queries[i].first.first, n = queries[i].first.second;
    if ((i == 0) || (k != queries[i - 1].first.first)) {
      int e = sqrt(k) + 1e-6;
      f.clear();
      for (j = 0; primes[j] <= e; j++) {
        if ((k % primes[j]) == 0) {
          f.push_back(primes[j]);
          while ((k % primes[j]) == 0) k /= primes[j];
        }
      }
      if (k > 1) f.push_back(k);
      if (f.size() > 2) {
        fill(dist, dist + f[0], -1);
        dist[0] = 0;
        H.push(make_pair(0, 0));
        while (!H.empty()) {
          int u = H.top().second;
          int d = -H.top().first;
          H.pop();
          if (d > dist[u]) continue;
          for (j = 1; j < f.size(); j++) {
            int v = (u + f[j]) % f[0];
            if ((dist[v] == -1) || (dist[u] + f[j] < dist[v])) {
              dist[v] = dist[u] + f[j];
              H.push(make_pair(-dist[v], v));
            }
          }
        }
      }
    }
    if (f.size() == 0)
      ans[queries[i].second] = 0;
    else if (f.size() == 1)
      ans[queries[i].second] = ((n % f[0]) == 0);
    else if (f.size() == 2) {
      int e = f[1] - 2;
      long long int b = f[0], r = 1;
      while (e > 0) {
        if (e & 1) r *= b, r %= f[1];
        e >>= 1;
        b *= b, b %= f[1];
      }
      ans[queries[i].second] = (n >= r * f[0]);
    } else
      ans[queries[i].second] = (dist[n % f[0]] != -1) && (dist[n % f[0]] <= n);
  }
  for (i = 0; i < t; i++) printf(ans[i] ? "YES\n" : "NO\n");
  return 0;
}
