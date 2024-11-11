#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int result = 1;
  while (b > 0) {
    int lastbit = (b & 1);
    if (lastbit) {
      result = (result * a);
    }
    a = (a * a);
    b = b >> 1;
  }
  return result;
}
long long int power2(long long int a, long long int b, long long int p) {
  long long int result = 1;
  while (b > 0) {
    int lastbit = (b & 1);
    if (lastbit) {
      result = (result * a) % p;
    }
    a = (a * a) % p;
    b = b >> 1;
  }
  return result % p;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<long long int> SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  vector<long long int> v;
  for (int p = 2; p <= n; p++)
    if (prime[p]) v.push_back(p);
  return v;
}
void shortest(map<int, vector<pair<int, long long int>>> m, int src, int n,
              long long int *dist) {
  bool visited[n];
  set<pair<long long int, int>> s;
  for (int i = 0; i <= n; i++) {
    dist[i] = -1;
    visited[i] = false;
  }
  s.insert(make_pair(0ll, src));
  dist[src] = 0;
  while (!s.empty()) {
    auto t = s.begin();
    long long int dis = (*t).first;
    int u = (*t).second;
    s.erase(t);
    if (visited[u]) {
      continue;
    }
    visited[u] = true;
    for (auto tt : m[u]) {
      int v = tt.first;
      long long int w = tt.second;
      if (!visited[v]) {
        if (dist[v] != -1 && dist[v] > dis + w) {
          s.erase(make_pair(dist[v], v));
          dist[v] = dis + w;
          s.insert(make_pair(dist[v], v));
        } else if (dist[v] == -1) {
          dist[v] = dis + w;
          s.insert(make_pair(dist[v], v));
        }
      }
    }
  }
}
int fun(int *a, int n, int x, int val) {
  int prefix_sum[2 * n + 1];
  for (int i = 0; i <= 2 * n; i++) {
    prefix_sum[i] = -1;
  }
  int sum = 0;
  int max_length = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      sum -= 1;
    } else if (a[i] == val) {
      sum += 1;
    } else if (max_length == 0) {
      max_length = 1;
    }
    if (sum == 0) max_length = i + 1;
    if (prefix_sum[sum + n] != (-1)) {
      max_length = max(max_length, i - prefix_sum[sum + n]);
    } else {
      prefix_sum[sum + n] = i;
    }
  }
  return max_length;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int ttttt = 1;
  for (int tttt = 1; tttt <= ttttt; tttt++) {
    int n;
    cin >> n;
    map<int, int> m;
    int a[n];
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      int d;
      cin >> d;
      a[i] = d;
      m[d]++;
    }
    for (auto i : m) {
      v.push_back(make_pair(i.second, i.first));
    }
    sort((v).rbegin(), (v).rend());
    int ans = 0;
    int s = v.size();
    for (int i = 1; i < (s - 1) && i <= 100; i++) {
      int t = fun(a, n, v[i].second, v[0].second);
      ans = max(ans, t);
    }
    cout << ans;
    cout << endl;
    cout << endl;
  }
  return 0;
}
