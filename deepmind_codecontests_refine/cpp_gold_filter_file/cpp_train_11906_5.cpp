#include <bits/stdc++.h>
using namespace std;
int n, m, Q;
bool ans[600005];
char a[505][505];
struct node {
  int x1, y1, x2, y2, id;
} q[600005], tq[600005];
bitset<505> f[505][505], g[505][505];
void solve(int l, int r, int L, int R) {
  if (L > R) return;
  int o = (l + r) >> 1;
  for (int i = n; i >= 1; i--) {
    f[i][o] = 0;
    if (a[i][o] == '.') f[i][o][i] = 1, f[i][o] |= f[i + 1][o];
  }
  for (int i = 1; i <= n; i++) {
    g[i][o] = 0;
    if (a[i][o] == '.') g[i][o][i] = 1, g[i][o] |= g[i - 1][o];
  }
  for (int i = n; i >= 1; i--)
    for (int j = o - 1; j >= l; j--) {
      if (a[i][j] == '.')
        f[i][j] = f[i + 1][j] | f[i][j + 1];
      else
        f[i][j] = 0;
    }
  for (int i = 1; i <= n; i++)
    for (int j = o + 1; j <= r; j++) {
      if (a[i][j] == '.')
        g[i][j] = g[i - 1][j] | g[i][j - 1];
      else
        g[i][j] = 0;
    }
  int ql = L, qr = R;
  for (int i = L; i <= R; i++)
    if (q[i].y2 < o)
      tq[ql++] = q[i];
    else if (q[i].y1 > o)
      tq[qr--] = q[i];
    else
      ans[q[i].id] = (f[q[i].x1][q[i].y1] & g[q[i].x2][q[i].y2]).any();
  for (int i = L; i <= R; i++) q[i] = tq[i];
  solve(l, o - 1, L, ql - 1), solve(o + 1, r, qr + 1, R);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++)
    scanf("%d%d%d%d", &q[i].x1, &q[i].y1, &q[i].x2, &q[i].y2), q[i].id = i;
  solve(1, m, 1, Q);
  for (int i = 1; i <= Q; i++) puts(ans[i] ? "Yes" : "No");
}
