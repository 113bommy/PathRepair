#include <bits/stdc++.h>
using namespace std;
const int N = 404, M = 250005;
int n, m, s, f, c, r, S[M], F[M], C[M], R[M], P[M], A[N], D[N];
long long Mx;
inline bool Solve(long long md) {
  int rr = r;
  long long nw = md, use;
  for (int i = s + 1; i <= f; i++) {
    use = (long long)D[i] * c;
    if (use > md) return 0;
    if (use > nw) {
      nw = md;
      rr--;
    }
    nw -= use;
  }
  return (rr >= 0);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]), D[i] = A[i] - A[i - 1];
  long long le = 0, ri = 1e18 + 10, md;
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d%d", &S[i], &F[i], &C[i], &R[i]), P[i] = i;
  srand(time(0));
  random_shuffle(P + 1, P + n + 1);
  for (int i = 1; i <= m; i++) {
    s = S[P[i]];
    f = F[P[i]];
    c = C[P[i]];
    r = R[P[i]];
    if (Solve(le)) continue;
    ri = 1e18 + 10;
    while (ri - le > 1) {
      md = (le + ri) >> 1;
      if (Solve(md))
        ri = md;
      else
        le = md;
    }
  }
  printf("%lld\n", le + 1);
  return (0);
}
