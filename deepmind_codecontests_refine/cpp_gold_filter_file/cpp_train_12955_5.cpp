#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, N = 10010, S = (1 << 24) - 1;
template <class T>
inline bool chkmin(T &A, T B) {
  return B < A ? A = B, 1 : 0;
}
template <class T>
inline bool chkmax(T &A, T B) {
  return A < B ? A = B, 1 : 0;
}
long long P[20];
int Solve(long long first, int d) {
  if (first == 0) return 0;
  if (d == 0) return INF;
  for (register int i = (0), i_end = (10); i <= i_end; ++i)
    if (P[d] * i == first) return i * d;
  for (register int i = (1), i_end = (10); i <= i_end; ++i)
    if (P[d] * i > first) {
      int res = INF;
      chkmin(res, i * d + Solve(P[d] * i - first, d - 1));
      chkmin(res, (i - 1) * d + Solve(first - P[d] * (i - 1), d - 1));
      return res;
    }
  assert(0);
  return 0;
}
int main() {
  for (register int i = (1), i_end = (17); i <= i_end; ++i)
    P[i] = P[i - 1] * 10 + 1;
  long long n;
  scanf("%lld", &n);
  printf("%d\n", Solve(n, 16));
  return 0;
}
