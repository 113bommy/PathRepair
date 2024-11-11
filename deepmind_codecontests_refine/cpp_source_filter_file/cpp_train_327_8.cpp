#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int p1[200005], p2[200005], c1, c2, u, d, l, r;
void init() {
  c1 = 0, c2 = 0;
  n = s.length();
  s = "*" + s;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'W') {
      p1[c1 + 1] = p1[c1] + 1;
      c1++;
    } else if (s[i] == 'S') {
      p1[c1 + 1] = p1[c1] - 1;
      c1++;
    } else if (s[i] == 'A') {
      p2[c2 + 1] = p2[c2] + 1;
      c2++;
    } else {
      p2[c2 + 1] = p2[c2] - 1;
      c2++;
    }
  }
  u = *max_element(p1, p1 + c1 + 1);
  d = *min_element(p1, p1 + c1 + 1);
  l = *max_element(p2, p2 + c2 + 1);
  r = *min_element(p2, p2 + c2 + 1);
}
long long ans;
void slove() {
  ans = 1ll * (u - d + 1) * (l - r + 1);
  int a, b, x, y;
  for (int i = 0; i <= c1; i++) {
    if (p1[i] == u) a = i;
    if (p1[c1 - i] == d) b = c1 - i;
    if (p1[i] == d) x = i;
    if (p1[c1 - i] == u) y = c1 - i;
  }
  if (a - 1 > b || x - 1 > y) ans = min(ans, 1ll * (l - r + 1) * (u - d));
  for (int i = 0; i <= c2; i++) {
    if (p2[i] == l) a = i;
    if (p2[c2 - i] == r) b = c2 - i;
    if (p2[i] == r) x = i;
    if (p2[c2 - i] == l) y = c2 - i;
  }
  if (a - 1 > b || x - 1 > y) ans = min(ans, 1ll * (l - r) * (u - d + 1));
}
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> s;
    init();
    slove();
    cout << ans << endl;
  }
}
