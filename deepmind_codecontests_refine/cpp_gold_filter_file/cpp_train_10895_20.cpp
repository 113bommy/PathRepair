#include <bits/stdc++.h>
using namespace std;
long long arr[200005], ans[200005];
map<long long, long long> memo;
vector<pair<long long, long long> > V[200005];
vector<long long> t;
int main() {
  long long n, q;
  scanf("%lld %lld", &n, &q);
  for (long long i = 1; i <= n; i++) scanf("%lld", &arr[i]);
  for (long long i = 1; i <= q; i++) {
    long long pos, val;
    scanf("%lld %lld", &pos, &val);
    V[pos].push_back(make_pair(i, val));
  }
  t.push_back(0);
  memo[0] = 1;
  long long f = 1;
  for (long long i = 1; i <= n; i++) {
    long long val = arr[i];
    if (memo[val]) {
      f = (f * 2) % 1000000007;
    } else {
      vector<long long> toadd;
      for (long long j = 0; j < t.size(); j++) {
        toadd.push_back(t[j] ^ val);
      }
      for (long long j = 0; j < toadd.size(); j++) {
        t.push_back(toadd[j]);
        memo[toadd[j]] = 1;
      }
    }
    for (long long j = 0; j < V[i].size(); j++) {
      long long pos = V[i][j].first;
      long long val = V[i][j].second;
      if (memo[val])
        ans[pos] = f;
      else
        ans[pos] = 0;
    }
  }
  for (long long i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}
