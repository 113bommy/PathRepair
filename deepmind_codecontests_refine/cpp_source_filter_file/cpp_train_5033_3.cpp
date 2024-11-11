#include <bits/stdc++.h>
const int INF = 5;
const int N = 1510;
const int M = 3010;
using namespace std;
int n;
long long stx, sty;
int sz[N], ans[N];
int edge[M], lst[N], nxt[M], t = 0;
struct nn {
  long long x, y;
  int id;
} a[N];
int cmp(nn A, nn B) {
  return (A.y - sty) * (B.x - stx) < (B.y - sty) * (A.x - stx);
}
int init_cmp(nn A, nn B) {
  if (A.x == B.x) return A.y < B.y;
  return A.x < B.x;
}
void ADD(int x, int y) {
  edge[++t] = y;
  nxt[t] = lst[x];
  lst[x] = t;
}
void READ() {
  int u, v;
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d%d", &u, &v);
    ADD(u, v);
    ADD(v, u);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &a[i].x, &a[i].y);
    a[i].id = i;
  }
}
void SEARCH(int x, int fa) {
  sz[x] = 1;
  for (int r = lst[x]; r; r = nxt[r]) {
    if (edge[r] == fa) continue;
    SEARCH(edge[r], x);
    sz[x] += sz[edge[r]];
  }
}
void SOLVE(int l, int r, int pos, int fa) {
  sort(a + l, a + r + 1, init_cmp);
  ans[a[l].id] = pos;
  stx = a[pos].x;
  sty = a[pos].y;
  if (l + 1 != r) sort(a + l + 1, a + r + 1, cmp);
  for (int r = lst[pos]; r; r = nxt[r]) {
    if (edge[r] == fa) continue;
    SOLVE(l + 1, l + sz[edge[r]], edge[r], pos);
    l += sz[edge[r]];
  }
}
int main() {
  READ();
  SEARCH(1, 0);
  SOLVE(1, n, 1, 0);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
