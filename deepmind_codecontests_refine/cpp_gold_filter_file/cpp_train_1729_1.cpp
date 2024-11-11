#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int INF = 0x7f7f7f7f;
int N, A[MAXN], V[MAXN];
long long K;
inline int up(int x, int y) {
  int r = x / y;
  if (r * y != x) r++;
  return r;
}
int main() {
  int i, d, maxv = 0;
  long long cur, val, lim, AnsD = 1;
  scanf("%d%I64d", &N, &K);
  lim = K;
  for (i = 1; i <= N; i++)
    scanf("%d", &A[i]), lim += A[i], maxv = max(maxv, A[i]);
  cur = N;
  long long L = maxv, R = maxv + K + 1, M;
  while (R - L > 1) {
    M = (L + R) >> 1;
    if (M * cur <= lim)
      L = M;
    else
      R = M;
  }
  if (L * cur <= lim)
    AnsD = L;
  else {
    for (d = maxv; d >= 1;) {
      int prev = 1;
      for (i = 1; i <= N; i++)
        V[i] = up(A[i], up(A[i], d)), prev = max(prev, V[i]);
      int L = prev, R = d + 1, M;
      while (R - L > 1) {
        M = (L + R) >> 1;
        if (M * cur <= lim)
          L = M;
        else
          R = M;
      }
      if (L * cur <= lim) {
        AnsD = L;
        break;
      }
      if (d != 1)
        for (i = 1; i <= N; i++)
          if (V[i] == prev) cur = cur - up(A[i], d) + up(A[i], prev - 1);
      d = prev - 1;
    }
  }
  printf("%I64d", AnsD);
}
