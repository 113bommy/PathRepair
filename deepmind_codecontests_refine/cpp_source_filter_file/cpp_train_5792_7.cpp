#include <bits/stdc++.h>
using namespace std;
const int N = 100500;
const long long inf = 1e17;
int n, m, mx[N], cost;
int ap[N], bp[N], cp[N], rk[N], ans;
long long sa[N << 2];
long long T[N << 2], D[N];
bool cmp(int A, int B) {
  return (cp[A] < cp[B] || (cp[A] == cp[B] && bp[A] < bp[B]));
}
void down(int ro) {
  if (D[ro] != 0) {
    D[ro << 1] += D[ro];
    T[ro << 1] += D[ro];
    D[ro << 1 | 1] += D[ro];
    T[ro << 1 | 1] += D[ro];
    D[ro] = 0;
  }
}
void update(int ro, int L, int R, int li, int ri, int val) {
  if (li > R || ri < L) return;
  if (li <= L && R <= ri) {
    D[ro] += val;
    T[ro] += val;
    return;
  }
  int Mid = (L + R) >> 1;
  down(ro);
  update(ro << 1, L, Mid, li, ri, val);
  update(ro << 1 | 1, Mid + 1, R, li, ri, val);
  T[ro] = ((T[ro << 1] < T[ro << 1 | 1]) ? (T[ro << 1]) : (T[ro << 1 | 1]));
}
long long query(int ro, int L, int R, int li, int ri) {
  if (li > R || ri < L) return inf;
  if (li <= L && R <= ri) return T[ro];
  int Mid = (L + R) >> 1;
  down(ro);
  long long x1 = query(ro << 1, L, Mid, li, ri);
  long long x2 = query(ro << 1 | 1, Mid + 1, R, li, ri);
  return ((x1 < x2) ? (x1) : (x2));
}
void build(int ro, int L, int R) {
  D[ro] = 0;
  if (L == R) {
    T[ro] = sa[L];
    return;
  }
  int Mid = (L + R) >> 1;
  build(ro << 1, L, Mid);
  build(ro << 1 | 1, Mid + 1, R);
  T[ro] = ((T[ro << 1] < T[ro << 1 | 1]) ? (T[ro << 1]) : (T[ro << 1 | 1]));
}
int two(int x) {
  int L = 0, R = n, Mid;
  while (L + 1 < R) {
    Mid = (L + R) >> 1;
    if (mx[Mid] >= x)
      L = Mid;
    else
      R = Mid;
  }
  if (mx[R] >= x) L = R;
  return L;
}
int main() {
  scanf("%d%d", &n, &m);
  ans = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &ap[i]), sa[i] = sa[i - 1] + ap[i];
  for (int i = n + 1; i <= (n << 1); i++) sa[i] = inf;
  for (int i = 1; i <= m; i++) scanf("%d", &bp[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &cp[i]), rk[i] = i;
  sort(rk + 1, rk + 1 + m, cmp);
  for (int i = n; i >= 1; i--)
    mx[i] = ((mx[i + 1] > ap[i]) ? (mx[i + 1]) : (ap[i]));
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int u = rk[i], yc = two(bp[u]);
    if (yc == 0) continue;
    long long yu = query(1, 1, n, yc, n);
    if (yu >= cp[u]) {
      ans++;
      update(1, 1, n, yc, n, -cp[u]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
