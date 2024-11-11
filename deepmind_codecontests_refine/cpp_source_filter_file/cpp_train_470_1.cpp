#include <bits/stdc++.h>
using namespace std;
const int N = 10, M = 1010;
int i, j, k, n, m, ch, ff, ans;
int z[N], fg[N];
vector<int> t, A[N][M];
struct cc {
  int x, y;
} a[N], b[M];
void R(int &x) {
  ff = x = 0;
  ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') ff = 1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (ff) x = -x;
}
int Js(const int &x) {
  if (x == 0) return 0;
  if (x > 0) return 1;
  return -1;
}
int ab(const int &x) {
  if (x < 0) return -x;
  return x;
}
bool check(const cc &a, const cc &b, const cc &c) {
  int x1 = b.x - a.x, y1 = b.y - a.y, x2 = c.x - a.x, y2 = c.y - a.y;
  if (Js(x1) != Js(x2) || Js(y1) != Js(y2)) return 0;
  if (ab(x1) < ab(x2) || ab(y1) < ab(y2)) return 0;
  return (long long)x1 * y2 == (long long)x2 * y1;
}
bool work(vector<int> t, int x) {
  if (t.size() > x) return 0;
  if (t.size() == 0) return 1;
  int i, j, k;
  for (i = 1; i <= n; i++)
    if (!z[i]) {
      z[i] = 1;
      vector<int> tt = t;
      k = tt[0];
      tt[0] = tt[tt.size() - 1];
      tt.pop_back();
      vector<int> a;
      for (j = 0; j < A[i][k].size(); j++)
        if (!fg[A[i][k][j]]) {
          tt.push_back(A[i][k][j]);
          a.push_back(A[i][k][j]);
          fg[A[i][k][j]] = 1;
        }
      if (work(tt, x - 1)) return 1;
      for (j = 0; j < a.size(); j++) fg[a[j]] = 0;
      z[i] = 0;
    }
  return 0;
}
int main() {
  R(n);
  R(m);
  for (i = 1; i <= n; i++) R(a[i].x), R(a[i].y);
  for (i = 1; i <= m; i++) R(b[i].x), R(b[i].y);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      for (k = 1; k <= m; k++)
        if (j != k && check(a[i], b[j], b[k])) {
          A[i][j].push_back(k);
          if (A[i][j].size() > n) break;
        }
  t.push_back(0);
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= m; j++) fg[j] = 0;
    for (j = 1; j <= n; j++) z[j] = 0;
    t[0] = i;
    fg[i] = 1;
    if (work(t, n)) ans++;
  }
  printf("%d\n", ans);
}
