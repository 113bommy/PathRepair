#include <bits/stdc++.h>
using namespace std;
int n, c, d, b[100005], p[100005], t[100005], q[100005], ans, cm, dm, m, u, v;
bool cmp(int x, int y) { return p[x] < p[y]; }
int main() {
  cin >> n >> c >> d;
  for (int i = 1; i <= n; i++) {
    cin >> b[i] >> p[i];
    char ch = getchar();
    while (ch != 'C' && ch != 'D') ch = getchar();
    t[i] = ch == 'C' ? 1 : 2;
  }
  for (int i = 1; i <= n; i++) {
    if (t[i] == 1 && p[i] <= c) cm = max(cm, b[i]);
    if (t[i] == 2 && p[i] <= d) dm = max(dm, b[i]);
  }
  if (cm && dm) ans = cm + dm;
  for (int i = 1; i <= n; i++)
    if (t[i] == 1) q[++m] = i;
  sort(q + 1, q + m + 1, cmp);
  for (int i = m, j = 1; i; i--) {
    for (; j <= m && p[q[i]] + p[q[j]] <= c; ++j)
      if (b[q[j]] > b[u]) {
        v = u;
        u = q[j];
      } else if (b[q[j]] > b[v])
        v = q[j];
    if (!u) continue;
    if (u != q[i])
      ans = max(ans, b[q[i]] + p[u]);
    else if (v)
      ans = max(ans, b[q[i]] + p[v]);
  }
  m = 0;
  for (int i = 1; i <= n; i++)
    if (t[i] == 2) q[++m] = i;
  sort(q + 1, q + m + 1, cmp);
  u = 0;
  v = 0;
  for (int i = m, j = 1; i; i--) {
    for (; j <= m && p[q[i]] + p[q[j]] <= d; j++)
      if (b[q[j]] > b[u]) {
        v = u;
        u = q[j];
      } else if (b[q[j]] > b[v])
        v = q[j];
    if (!u) continue;
    if (u != q[i])
      ans = max(ans, b[q[i]] + p[u]);
    else if (v)
      ans = max(ans, b[q[i]] + p[v]);
  }
  cout << ans;
  return 0;
}
