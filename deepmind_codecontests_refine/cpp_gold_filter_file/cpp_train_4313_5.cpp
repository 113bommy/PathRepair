#include <bits/stdc++.h>
using namespace std;
int n, a[300005], pre[300005], nxt[300005], c[300005], p0[100], p1[100];
bool cmp(const int &u, const int &v) { return a[u] < a[v]; }
double ans = 0, pw[100];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), pre[i] = i - 1, nxt[i] = i + 1, c[i] = i;
  nxt[n + 1] = n + 1, pre[n + 1] = n, nxt[0] = 1;
  sort(c + 1, c + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    int u = c[i], l = 0;
    p0[0] = p1[0] = u;
    pw[0] = 0.5 * a[u] / n / n;
    for (; pw[l] > 1e-18;) ++l, pw[l] = pw[l - 1] * 0.5;
    for (int j = 1; j <= l; j++) p0[j] = pre[p0[j - 1]], p1[j] = nxt[p1[j - 1]];
    for (int j = 0; j < l; j++)
      for (int k = 0; k < l - j; k++)
        ans += pw[j + k] * (p1[k + 1] - p1[k]) * (p0[j] - p0[j + 1]);
    nxt[pre[u]] = nxt[u], pre[nxt[u]] = pre[u];
  }
  printf("%.6lf\n", ans);
}
