#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
ll modpow(ll b, ll p) {
  if (p == 0)
    return 1;
  else if (p == 1)
    return b;
  ll res = 1;
  while (p > 0) {
    if (p & 1) res = res * b % 1000000007;
    b = b * b % 1000000007;
    p >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  string p;
  cin >> p;
  vector<int> y(m);
  for (int i = 0; i < m; i++) cin >> y[i], y[i]--;
  int lp = p.size();
  vector<int> z(lp);
  int x = 0;
  for (int i = 1; i < lp; i++) {
    z[i] = min(z[i - x], max(0, x + z[x] - i));
    while (i + z[i] < n && p[z[i]] == p[i + z[i]]) z[i]++;
    if (i + z[i] > x + z[x]) x = i;
  }
  int ans = m == 0 ? n : y[0];
  if (m > 0) {
    for (int i = 1; i < m; i++) {
      int prev = y[i - 1], now = y[i];
      if (prev + lp - 1 >= now) {
        if (z[now - prev] != prev + lp - now) {
          cout << "0\n";
          return 0;
        }
      } else
        ans += now - (prev + lp);
    }
    ans += n - (y.back() + lp);
  }
  cout << modpow(26, ans) << "\n";
}
