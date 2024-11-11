#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, INF = 0x3f3f3f3f;
int n, st[N], top, dp1[N], dp2[N], st1[N], st2[N], top1, top2, L, R, mid;
double x[N], d[N], v1[N], v2[N], ans = INF;
int main() {
  scanf("%d", &n);
  for (register int i = 0; i <= n + 1; ++i) scanf("%lf", &x[i]);
  d[0] = d[n + 1] = INF;
  for (register int i = 1; i <= n; ++i) scanf("%lf", &d[i]);
  for (register int i = 1; i <= n; ++i) {
    while (top && x[i] > x[dp1[st[top]]] + d[st[top]] * 2) --top;
    dp1[i] = st[top];
    while (top && x[dp1[i]] + d[i] * 2 >= x[dp1[st[top]]] + d[st[top]] * 2)
      --top;
    st[++top] = i;
  }
  st[top = 0] = n + 1;
  for (register int i = n; i >= 1; --i) {
    while (top && x[i] < x[dp2[st[top]]] - d[st[top]] * 2) --top;
    dp2[i] = st[top];
    while (top && x[dp2[i]] - d[i] * 2 <= x[dp2[st[top]]] - d[st[top]] * 2)
      --top;
    st[++top] = i;
  }
  for (register int i = 1; i <= n; ++i) v1[i] = x[dp1[i]] + d[i] * 2 - x[i];
  for (register int i = 1; i <= n; ++i) v2[i] = x[i] - x[dp2[i]] + d[i] * 2;
  ans = min(ans, x[n + 1]);
  for (register int i = 1; i <= n; ++i) {
    if (x[dp2[i]] - x[dp1[i]] <= d[i] * 2 || x[i] + v1[i] >= x[n + 1] ||
        x[i] <= v2[i]) {
      printf("0\n");
      return 0;
    }
    ans = min(ans, x[dp2[i]] - x[dp1[i]]);
    if (v1[i] > 0) st1[++top1] = i, ans = min(ans, x[n + 1] - x[i]);
    if (v2[i] > 0) st2[++top2] = i, ans = min(ans, x[i]);
  }
  st[top = 0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (v2[i] > 0) {
      L = 0, R = top;
      while (L < R) {
        mid = L + R + 1 >> 1;
        if (x[st[mid]] + v1[st[mid]] < x[i] - v2[i])
          R = mid - 1;
        else
          L = mid;
      }
      ans = min(ans, x[i] - x[st[L]]);
    }
    if (v1[i] > 0) {
      while (top && x[i] + v1[i] >= x[st[top]] + v1[st[top]]) --top;
      st[top++] = i;
    }
  }
  printf("%lf\n", ans * 0.5);
  return 0;
}
