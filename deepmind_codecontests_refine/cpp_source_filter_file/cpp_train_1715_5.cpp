#include <bits/stdc++.h>
using namespace std;
int n, num[1000005], L[1000005], R[1000005], ans[1000005], b[1000005], q;
int read() {
  char c = getchar();
  int ans = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9')
    ans = (ans << 1) + (ans << 3) + (c ^ 48), c = getchar();
  return ans;
}
struct node {
  int L, R, id;
  bool operator<(const node b) const { return L > b.L; }
} S[1000005], Q[1000005];
void pushdown(int rt) {
  if (!num[rt]) num[rt << 1] = num[rt << 1 | 1] = 0;
  return;
}
void build_tree(int L, int R, int rt) {
  if (L == R) {
    num[rt] = b[L + 1] - b[L];
    return;
  }
  int mid = (L + R) >> 1;
  build_tree(L, mid, rt << 1);
  build_tree(mid + 1, R, rt << 1 | 1);
  num[rt] = num[rt << 1] + num[rt << 1 | 1];
  return;
}
int query(int L, int R, int l, int r, int rt) {
  if (l <= L && R <= r) return num[rt];
  if (l > R || L > r) return 0;
  int mid = (L + R) >> 1;
  pushdown(rt);
  return query(L, mid, l, r, rt << 1) + query(mid + 1, R, l, r, rt << 1 | 1);
}
void modify(int L, int R, int l, int r, int rt) {
  if (l <= L && R <= r) {
    num[rt] = 0;
    return;
  }
  int mid = (L + R) >> 1;
  pushdown(rt);
  if (mid >= l) modify(L, mid, l, r, rt << 1);
  if (mid < r) modify(mid + 1, R, l, r, rt << 1 | 1);
  num[rt] = num[rt << 1] + num[rt << 1 | 1];
  return;
}
int main() {
  n = read();
  for (register int i = 1; i <= n; i++)
    S[i].L = read(), S[i].R = S[i].L + read(), b[++b[0]] = S[i].L,
    b[++b[0]] = S[i].R;
  sort(b + 1, b + 1 + b[0]);
  b[0] = unique(b + 1, b + 1 + b[0]) - (b + 1);
  for (register int i = 1; i <= n; i++)
    S[i].L = lower_bound(b + 1, b + 1 + b[0], S[i].L) - b,
    S[i].R = lower_bound(b + 1, b + 1 + b[0], S[i].R) - (b + 1);
  q = read();
  for (register int i = 1; i <= q; i++)
    Q[i].L = read(), Q[i].R = read(), Q[i].id = i;
  sort(Q + 1, Q + 1 + q);
  int now = n;
  build_tree(1, b[0] - 1, 1);
  for (register int i = q; i >= 1; i--) {
    while (now >= Q[i].L) modify(1, b[0] - 1, S[now].L, S[now].R, 1), now--;
    ans[Q[i].id] = query(1, b[0] - 1, S[Q[i].L].L, S[Q[i].R].L - 1, 1);
  }
  for (register int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
