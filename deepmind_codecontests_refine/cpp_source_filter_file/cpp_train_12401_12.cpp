#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 3;
long long n, c, cnt[N];
vector<long long> v[N];
long long slv(vector<long long> u) {
  long long prv = 0, res = 0;
  for (long long i = (long long)(0); i <= (long long)(u.size() - 1); i++) {
    prv = max(prv, 0ll) + u[i];
    res = max(res, prv);
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> c;
  for (long long i = (long long)(1); i <= (long long)(n); i++) {
    long long x;
    cin >> x;
    if (x == c)
      cnt[i]++;
    else
      v[x].push_back(i);
  }
  for (long long i = (long long)(1); i <= (long long)(N - 1); i++)
    cnt[i] += cnt[i - 1];
  long long ans = cnt[N - 1];
  for (long long i = (long long)(1); i <= (long long)(N - 1); i++) {
    if (v[i].size() <= 1) continue;
    vector<long long> u;
    u.push_back(1);
    for (long long j = (long long)(1); j <= (long long)(v[i].size() - 1); j++) {
      u.push_back(cnt[v[i][j - 1] - 1] - cnt[v[i][j]]);
      u.push_back(1);
    }
    ans = max(ans, cnt[N - 1] + slv(u));
  }
  cout << ans;
}
