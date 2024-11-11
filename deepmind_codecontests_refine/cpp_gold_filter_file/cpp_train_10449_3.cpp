#include <bits/stdc++.h>
using namespace std;
struct seg {
  int l, r, s;
} t[100005 * 20];
struct bg {
  int x, y;
  bool operator<(const bg &B) const { return y < B.y; }
} a[100005], b[100005];
int N, S, tot, bg[9], q[9], sx[100005], sy[100005], rt[100005], X[100005],
    p[100005];
bool c[9];
void ins(int q, int &p, int L, int R, int x) {
  if (!p) p = ++tot;
  if (L == R) {
    t[p].s = t[q].s + 1;
    return;
  }
  if (x <= ((L + R) >> 1))
    ins(t[q].l, t[p].l, L, ((L + R) >> 1), x), t[p].r = t[q].r;
  else
    ins(t[q].r, t[p].r, ((L + R) >> 1) + 1, R, x), t[p].l = t[q].l;
  t[p].s = t[t[p].l].s + t[t[p].r].s;
}
int query(int q, int &p, int L, int R, int r) {
  if (R <= r) return t[p].s;
  if (r <= ((L + R) >> 1))
    return query(t[q].l, t[p].l, L, ((L + R) >> 1), r);
  else
    return t[t[p].l].s + query(t[q].r, t[p].r, ((L + R) >> 1) + 1, R, r);
}
void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d%d", &a[i].x, &a[i].y), b[i].x = i, b[i].y = a[i].x;
  for (int i = 0; i < 9; i++) scanf("%d", &bg[i]);
  sort(b + 1, b + N + 1);
  for (int i = 1; i <= N; i++) {
    if (i == 1 || b[i].y != b[i - 1].y) X[++S] = b[i].y;
    a[b[i].x].x = S, sx[S]++;
  }
  for (int i = 1; i <= S; i++) sx[i] += sx[i - 1];
  sort(a + 1, a + N + 1);
  for (int i = 1; i <= N; i++)
    ins(rt[i - 1], rt[i], 1, S, a[i].x), sy[i] = sy[i - 1] + 1;
  for (int i = N; i; i--) p[i] = a[i].y == a[i + 1].y ? p[i + 1] : i;
}
void check() {
  int A = q[0] + q[3] + q[6], B = N - q[2] - q[5] - q[8],
      C = q[0] + q[1] + q[2], D = N - q[6] - q[7] - q[8], l, r, d = p[C],
      u = p[D];
  l = lower_bound(sx + 1, sx + S + 1, A) - sx,
  r = lower_bound(sx + 1, sx + S + 1, B) - sx;
  if ((query(0, rt[d], 1, S, l)) == q[0] &&
      (query(0, rt[d], 1, S, r)) == q[0] + q[1] &&
      (query(0, rt[u], 1, S, l)) == q[0] + q[3] &&
      (query(0, rt[u], 1, S, r)) == q[0] + q[1] + q[3] + q[4] && sx[l] == A &&
      sx[r] == B && (query(0, rt[d], 1, S, S)) == C &&
      (query(0, rt[u], 1, S, S)) == D)
    printf("%lf %lf\n%lf %lf\n", X[l] + 0.5, X[r] + 0.5, a[d].y + 0.5,
           a[u].y + 0.5),
        exit(0);
}
void dfs(int t) {
  if (t == 9) {
    check();
    return;
  }
  for (int i = 0; i < 9; i++)
    if (!c[i]) c[i] = 1, q[t] = bg[i], dfs(t + 1), c[i] = 0;
}
int main() {
  init();
  dfs(0);
  puts("-1");
  return 0;
}
