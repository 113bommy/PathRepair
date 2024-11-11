#include <bits/stdc++.h>
using namespace std;
const long long MAXV = 1000000000000000000LL;
const int MAXSZ = 5000010;
struct numbers {
  int N, base[16], cnt[16], tot;
  long long val[MAXSZ];
  void dfs(int d, long long v) {
    if (d == N + 1) {
      val[tot++] = v;
      return;
    }
    for (long long x = 1; (double)v * x <= MAXV;) {
      dfs(d + 1, v * x);
      if ((double)x * base[d] > MAXV) break;
      x *= base[d];
    }
  }
} A[2];
inline long long nlte(long long X) {
  long long ret = 0;
  int p0, p1 = 0;
  for (p0 = A[0].tot - 1; p0 >= 0; p0--)
    if (A[0].val[p0] <= X) {
      while (((p1 + 1) < A[1].tot) && (A[1].val[p1 + 1] <= X / A[0].val[p0]))
        p1++;
      ret += p1 + 1;
    }
  return ret;
}
int N;
long long K;
int main() {
  int i;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) scanf("%d", &A[i & 1].base[++A[i & 1].N]);
  scanf("%I64d", &K);
  A[0].dfs(1, 1), sort(A[0].val, A[0].val + A[0].tot);
  A[1].dfs(1, 1), sort(A[1].val, A[1].val + A[1].tot);
  long long L = 0, R = MAXV, M;
  while (R - L > 1) {
    M = (L + R) >> 1;
    if (nlte(M) >= K)
      R = M;
    else
      L = M;
  }
  printf("%I64d", R);
}
