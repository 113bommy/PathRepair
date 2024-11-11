#include <bits/stdc++.h>
using namespace std;
const int INF = (1LL << 31) - 1;
const long long int LINF = (1LL << 62) - 1;
const int NMAX = 100000 + 5;
const int MMAX = 100000 + 5;
const int KMAX = 100000 + 5;
const int PMAX = 100000 + 5;
const int LMAX = 100000 + 5;
const int VMAX = 100000 + 5;
int N, M;
int L[NMAX];
int R[NMAX];
int X[NMAX];
int A[NMAX];
int P[NMAX][32];
int AI[4 * NMAX];
void build(int nod, int lo, int hi) {
  if (lo == hi) {
    AI[nod] = A[lo];
    return;
  }
  int mi = (lo + hi) / 2;
  build(2 * nod, lo, mi);
  build(2 * nod + 1, mi + 1, hi);
  AI[nod] = AI[2 * nod] & AI[2 * nod + 1];
}
int query(int nod, int lo, int hi, int L, int R) {
  if (L <= lo && hi <= R) return AI[nod];
  if (R < lo || hi < L) return ((1 << 30) - 1);
  int mi = (lo + hi) / 2;
  return (query(2 * nod, lo, mi, L, R) & query(2 * nod + 1, mi + 1, hi, L, R));
}
int main() {
  int i, j, l, r, x, ok;
  scanf("%d%d", &N, &M);
  for (i = 1; i <= M; i++) {
    scanf("%d%d%d", &l, &r, &x);
    L[i] = l;
    R[i] = r;
    X[i] = x;
    for (j = 0; j <= 30; j++)
      if (x & (1 << j)) {
        P[l][j] = 1;
        P[r + 1][j] = -1;
      }
  }
  for (j = 0; j <= 30; j++) {
    ok = 0;
    for (i = 1; i <= N; i++) {
      ok += P[i][j];
      if (ok > 0) A[i] |= (1 << j);
    }
  }
  build(1, 1, N);
  ok = 1;
  for (i = 1; i <= M; i++)
    if (query(1, 1, N, L[i], R[i]) != X[i]) ok = 0;
  if (ok) {
    printf("YES\n");
    for (i = 1; i <= N; i++) printf("%d ", A[i]);
  } else
    printf("NO\n");
  return 0;
}
