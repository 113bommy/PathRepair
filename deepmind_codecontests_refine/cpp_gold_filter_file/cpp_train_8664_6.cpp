#include <bits/stdc++.h>
using namespace std;
void solve(long long tc) {
  long long n, m;
  cin >> n >> m;
  vector<long long> v(m);
  vector<long long> ans(m);
  long long s = 0;
  for (long long i = 0; i < m; i++) cin >> v[i], s += v[i];
  if (s < n) {
    cout << "-1\n";
    return;
  }
  ans[m - 1] = n - v[m - 1] + 1;
  long long req = s - n, i, cur = n - v[m - 1];
  bool f = 1;
  for (i = m - 2; i >= 0; i--) {
    if (cur <= 0) {
      f = 0;
      break;
    }
    if (req == 0) {
      ans[i] = cur + 1 - v[i];
      cur = ans[i] - 1;
      continue;
    }
    if (n - v[i] + 1 < cur) {
      if (v[i + 1] > req) {
        ans[i] = cur - (v[i] - req - 1);
        req = 0;
        cur = ans[i] - 1;
      } else {
        req -= (n - cur);
        ans[i] = n - v[i] + 1;
        cur = ans[i] - 1;
      }
    } else {
      if (req < v[i] - 1) {
        ans[i] = cur - (v[i] - req - 1);
        req = 0;
        cur = ans[i] - 1;
      } else {
        req -= (v[i] - 1);
        ans[i] = cur;
        cur = ans[i] - 1;
      }
    }
  }
  if (!f)
    cout << -1;
  else {
    for (long long i = 0; i < m; i++) cout << ans[i] << " ";
  }
}
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cerr.tie(NULL);
  cout.precision(20);
  long long t = 1;
  long long ctr = 0;
  while (t--) {
    solve(ctr + 1);
    ctr++;
  }
}
