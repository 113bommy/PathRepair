#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, sgn = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') sgn = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
  return x * sgn;
}
const int N = 1e5 + 10;
int a[N], d[N], n, top, stk[N], f[N], g[N], tr[N], tot;
vector<int> val;
void add(int x, int y) {
  x = lower_bound(val.begin(), val.end(), x) - val.begin() + 1;
  for (; x > 0; x -= x & -x) tr[x] = max(tr[x], y);
}
int query(int x, int y = -1) {
  x = lower_bound(val.begin(), val.end(), x) - val.begin() + 1;
  for (; x <= tot; x += x & -x) y = max(tr[x], y);
  return y;
}
int main() {
  n = read();
  for (int i = 0; i <= n + 1; i++) a[i] = read();
  for (int i = 1; i <= n; i++) d[i] = read();
  stk[top = 0] = 0;
  for (int i = 1; i <= n; i++) {
    while (top && a[i] - a[f[stk[top]]] > 2 * d[stk[top]]) top--;
    f[i] = stk[top];
    while (top && 2 * d[stk[top]] + a[f[stk[top]]] < 2 * d[i] + a[f[i]]) top--;
    stk[++top] = i;
  }
  stk[top = 0] = n + 1;
  for (int i = n; i >= 1; i--) {
    while (top && a[g[stk[top]]] - a[i] > 2 * d[stk[top]]) top--;
    g[i] = stk[top];
    while (top && a[g[stk[top]]] - 2 * d[stk[top]] > a[g[i]] - 2 * d[i]) top--;
    stk[++top] = i;
  }
  int ans = a[n + 1];
  for (int i = 1; i <= n; i++)
    if (a[g[i]] - a[f[i]] <= 2 * d[i]) return puts("0"), 0;
  for (int i = 1; i <= n; i++) ans = min(ans, a[g[i]] - a[f[i]]);
  for (int i = 1; i <= n; i++) val.push_back(a[f[i]] + 2 * d[i]);
  sort(val.begin(), val.end());
  val.resize(tot = unique(val.begin(), val.end()) - val.begin() - 1);
  memset(tr, -1, sizeof(tr));
  for (int i = 1; i <= n; i++) {
    if (a[g[i]] - a[i] < 2 * d[i]) {
      int t = query(a[g[i]] - 2 * d[i]);
      if (~t) ans = min(ans, a[i] - t);
    }
    if (a[i] - a[f[i]] < 2 * d[i]) add(a[f[i]] + 2 * d[i], a[i]);
  }
  for (int i = 1; i <= n; i++)
    if (f[i] == 0 && a[g[i]] - a[i] < 2 * d[i]) ans = min(ans, a[i]);
  for (int i = 1; i <= n; i++)
    if (g[i] == n + 1 && a[i] - a[f[i]] < 2 * d[i])
      ans = min(ans, a[n + 1] - a[i]);
  printf("%.1lf\n", ans * 0.5);
  return 0;
}
