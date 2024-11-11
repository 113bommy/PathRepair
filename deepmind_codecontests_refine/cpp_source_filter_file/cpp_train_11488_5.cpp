#include <bits/stdc++.h>
using namespace std;
struct str {
  int a, b, c;
  void in() { cin >> a >> b >> c; }
} a[19][109];
struct pp {
  int x, y;
  void f(int _x, int _y) {
    x = _x;
    y = _y;
  }
} b[109];
bool cmp(pp a, pp b) { return (a.x < b.x); }
string w[109];
int n, m, x, y, i, j, kk, k, l, r, q, s, ans;
int main() {
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) {
    cin >> w[i];
    for (j = 0; j < n; j++) a[i][j].in();
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i != j) {
        for (l = 0; l < m; l++) b[l].f(a[j][l].b - a[i][l].a, l);
        sort(b, b + m, cmp);
        s = 0;
        kk = k;
        for (l = m - 1; l >= 0; l--) {
          y = b[l].y;
          x = b[l].x;
          if (x <= 0) break;
          q = min(a[i][y].c, kk);
          s += q * x;
          kk -= q;
          if (kk == 0) break;
        }
        ans = max(ans, s);
      }
    }
  }
  cout << ans;
}
