#include <bits/stdc++.h>
using namespace std;
string s, w;
int a[200001], l = 0, r, c, check[200001], n, m, ans = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> w;
  n = s.size();
  m = w.size();
  for (int i = 1; i <= n; i++) cin >> a[i];
  r = n;
  s = " " + s;
  w = " " + w;
  while (l <= r) {
    c = (l + r) / 2;
    int t = 1;
    memset(check, 0, sizeof(check));
    for (int i = 1; i <= c; i++) check[a[i]] = 1;
    for (int i = 1; i <= n; i++)
      if (!check[i] && t < m && s[i] == w[t]) t++;
    if (t == m) {
      ans = max(ans, c);
      l = c + 1;
    } else
      r = c - 1;
  }
  cout << ans;
  return 0;
}
