#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long n, K, A, B, C;
struct mat {
  long long a[16][16];
} st, now, I;
mat operator*(mat x, mat y) {
  mat ret;
  for (long long i = 0; i <= 15; i++)
    for (long long j = 0; j <= 15; j++) {
      ret.a[i][j] = 0;
      for (long long k = 0; k <= C; k++)
        ret.a[i][j] =
            (ret.a[i][j] + x.a[i][k] * y.a[k][j] % 1000000007) % 1000000007;
    }
  return ret;
}
mat qm(mat x, long long b) {
  mat ret = I;
  while (b) {
    if (b & 1) ret = ret * x;
    x = x * x;
    b >>= 1;
  }
  return ret;
}
void init() {
  for (long long i = 0; i <= 15; i++) I.a[i][i] = 1;
}
void work(long long C) {
  for (long long i = 0; i <= 15; i++)
    for (long long j = 0; j <= 15; j++) st.a[i][j] = 0;
  for (long long i = 0; i <= C; i++) {
    if (i + 1 <= C) st.a[i + 1][i] = 1;
    if (i) st.a[i - 1][i] = 1;
    st.a[i][i] = 1;
  }
}
long long ans[16], tmp[16];
int main() {
  n = read(), K = read();
  ans[0] = 1;
  init();
  for (long long i = 1; i <= n; i++) {
    A = read(), B = read(), C = read();
    B = min(B, K);
    for (long long j = C + 1; j <= 15; j++) ans[j] = 0;
    work(C);
    now = qm(st, B - A);
    for (long long j = 0; j <= 15; j++) {
      tmp[j] = 0;
      for (long long k = 0; k <= 15; k++)
        tmp[j] = (tmp[j] + (ans[k] * now.a[k][j] % 1000000007)) % 1000000007;
    }
    for (long long j = 0; j <= 15; j++) ans[j] = tmp[j];
  }
  printf("%lld\n", ans[0]);
}
