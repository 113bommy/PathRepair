#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m;
bool ma[600][600];
char ch[600];
bitset<600> f[600][600], g[600][600];
struct data {
  int x1, y1, x2, y2;
  int id;
} op[610000], t[610000];
int ans[1000000];
void solve(int l, int r, int ll, int rr) {
  if (ll > rr || l > r) return;
  int mid = (l + r) >> 1;
  for (int i = l; i <= r; i++)
    for (int j = 1; j <= m; j++) f[i][j] = g[i][j] = 0;
  for (int i = m; i; i--)
    if (ma[mid][i]) f[mid][i][i] = 1, f[mid][i] |= f[mid][i + 1];
  for (int i = 1; i <= m; i++)
    if (ma[mid][i]) g[mid][i][i] = 1, g[mid][i] |= g[mid][i - 1];
  for (int i = mid - 1; i >= l; i--)
    for (int j = m; j; j--)
      if (ma[i][j]) f[i][j] = f[i][j + 1] | f[i + 1][j];
  for (int i = mid + 1; i <= r; i++)
    for (int j = 1; j <= m; j++)
      if (ma[i][j]) g[i][j] = g[i][j - 1] | g[i - 1][j];
  int cnt1 = ll, cnt2 = rr;
  for (int i = ll; i <= rr; i++) {
    if (op[i].x2 < mid)
      t[cnt1++] = op[i];
    else if (op[i].x1 > mid)
      t[cnt2--] = op[i];
    else
      ans[op[i].id] = (f[op[i].x1][op[i].y1] & g[op[i].x2][op[i].y2]).count();
  }
  for (int i = ll; i < cnt1; i++) op[i] = t[i];
  for (int i = cnt2 + 1; i <= rr; i++) op[i] = t[i];
  solve(l, mid - 1, ll, cnt1 - 1);
  solve(mid + 1, r, cnt2 + 1, rr);
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch + 1);
    for (int j = 1; j <= m; j++) ma[i][j] = (ch[j] == '.');
  }
  int q = read();
  for (int i = 1; i <= q; i++)
    op[i].x1 = read(), op[i].y1 = read(), op[i].x2 = read(), op[i].y2 = read(),
    op[i].id = i;
  solve(1, n, 1, q);
  for (int i = 1; i <= q; i++) printf(ans[i] ? "Yes\n" : "No\n");
  return 0;
}
