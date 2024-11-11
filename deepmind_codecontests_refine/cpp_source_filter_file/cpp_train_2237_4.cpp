#include <bits/stdc++.h>
using namespace std;
char s[21][21];
pair<string, int> c[10005];
vector<string> v;
int n, m, x, y, k = 0;
void f(int x1, int y1, int x2, int y2) {
  string r = "", d = "";
  for (int i = x1; i < x2; i++)
    for (int j = y1; j < y2; j++) r += s[i][j];
  for (int i = x2 - 1; i >= x1; i--)
    for (int j = y2 - 1; j >= y1; j--) d += s[i][j];
  if (d < r) r = d;
  if (x2 - x1 != y2 - y1) {
    c[k++] = make_pair(r, x);
    for (int i = 0; i < x * y; i++) r[i] = 'a';
  }
  int j;
  for (d = "", j = y1; j < y2; j++) {
    for (int i = x2 - 1; i >= x1; i--) {
      d += s[i][j];
    }
  }
  if (d < r) r = d;
  for (d = "", j = y2 - 1; j >= y1; j--) {
    for (int i = x1; i < x2; i++) {
      d += s[i][j];
    }
  }
  if (d < r) r = d;
  c[k++] = make_pair(r, y);
}
int main() {
  int ansx = 1 << 15, ansy = 1 << 15, ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) cin >> s[i];
  for (x = 1; x <= n; x++)
    if (n % x == 0) {
      for (int y = 1; y <= m; y++) {
        if (m % y == 0) {
          for (int a = k = 0; a * x < n; a++) {
            for (int b = 0; b * y < m; b++) {
              f(a * x, b * y, (a + 1) * x, (b + 1) * y);
            }
          }
          sort(c, c + k);
          bool q = true;
          for (int o = 1; o < k; o++) {
            if (c[o] == c[o - 1]) {
              q = false;
              break;
            }
          }
          if (q && (++ans == 1 || x * y < ansx * ansy)) {
            ansx = x;
            ansy = y;
          }
        }
      }
    }
  printf("%d\n%d %d", ans, ansx, ansy);
}
