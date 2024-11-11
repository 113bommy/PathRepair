#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
struct Edg {
  int lst, ed;
} e[N << 1];
int ne = 0, nte[N];
int tot = 0, top = 0, dfn[N], low[N], sta[N];
int d[N], a[N];
long long s[N];
int rd() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x;
}
void NewEdg(int u, int v) {
  ne++;
  e[ne].lst = nte[u];
  e[ne].ed = v;
  nte[u] = ne;
}
void dfs(int x) {
  dfn[x] = low[x] = ++tot;
  sta[++top] = x;
  for (int i = nte[x]; i; i = e[i].lst)
    if (!dfn[e[i].ed]) {
      dfs(e[i].ed);
      low[x] = min(low[x], low[e[i].ed]);
      if (low[e[i].ed] >= dfn[x]) {
        int L = x, R = x, siz = 1;
        while (sta[top + 1] != e[i].ed) {
          R = max(R, sta[top]);
          L = min(L, sta[top]);
          top--, siz++;
        }
        if (siz > 2) d[L] = min(d[L], R);
      }
    } else
      low[x] = min(low[x], dfn[e[i].ed]);
}
int main() {
  int n = rd(), m = rd();
  for (int i = 1; i <= m; i++) {
    int x = rd(), y = rd();
    NewEdg(x, y), NewEdg(y, x);
  }
  for (int i = 1; i <= n; i++) d[i] = n + 1;
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) dfs(i);
  a[n] = 1;
  for (int i = n - 1; i >= 1; i--) a[i] = min(d[i] - i, a[i + 1] + 1);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  int q = rd();
  for (int i = 1; i <= q; i++) {
    int L = rd(), R = rd();
    int l = L, r = R + 1;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (mid + a[mid] - 1 > R)
        r = mid;
      else
        l = mid;
    }
    printf("%lld\n", s[l] - s[L - 1] + (long long)(1 + R - l) * (R - l) / 2);
  }
  return 0;
}
