#include <bits/stdc++.h>
using namespace std;
inline int Read() {
  char c = getchar();
  int num = 0;
  while ('0' > c || c > '9') c = getchar();
  while ('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
  return (num);
}
long long t;
int C[33554442], A[33554442], n, m, s, ans;
inline int Pow(int x, long long y) {
  int rs = 1;
  for (; y; y /= 2, x = x * 1ll * x % 1051131)
    if (y & 1) rs = rs * 1ll * x % 1051131;
  return (rs);
}
inline void Work(int n, int p, int q) {
  if (n == 1) {
    int x = (p + q) % 1051131;
    A[1] = A[1] * 1ll * Pow(x, t) % 1051131;
    return;
  }
  int md = n / 2;
  int nm = p * 1ll * md % 1051131 - p - q;
  if (nm < 0) nm += 1051131;
  nm = Pow(1051131 - nm, t);
  for (int i = 1; i <= md; i++)
    C[i + md] = (A[i] - A[i + md] + 1051131) % 1051131;
  for (int i = 1; i <= md; i++) C[i + md] = C[i + md] * 1ll * nm % 1051131;
  for (int i = 1; i <= md; i++) A[i] = (A[i] + A[i + md]) % 1051131;
  Work(md, p * 2ll % 1051131,
       ((p * 1ll * md % 1051131 - p + q) % 1051131 + 1051131) % 1051131);
  for (int i = 1; i <= md; i++) {
    int x = A[i] % 1051131;
    A[i] = (x + C[i + md]) * 1ll * 525566 % 1051131;
    A[i + md] = (x - C[i + md] + 1051131) * 1ll * 525566 % 1051131;
  }
}
int main() {
  m = Read(), scanf("%I64d", &t), s = Read();
  for (int i = 1; i <= s; i++) A[i] = Read();
  for (int i = s + 1; i <= (1 << m); i++)
    A[i] = (101ll * A[i - s] + 10007) % 1051131;
  Work(1 << m, 1, 0);
  for (int i = 1; i <= (1 << m); i++) ans ^= A[i];
  printf("%d\n", ans);
}
