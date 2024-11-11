#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
const long long MAXN = 1e5 + 11;
long long N, p, A[MAXN], ps, Q, ste[MAXN], nex[MAXN];
long long Get(long long x) {
  long long Ans = x;
  for (long long i = 2; i * i <= x; i++) {
    if ((x % i)) continue;
    while ((x % i) == 0) x /= i;
    Ans /= i, Ans *= (i - 1);
  }
  if (x != 1) Ans /= x, Ans *= (x - 1);
  return Ans;
}
bool FF;
long long ksm(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a, ans %= mod;
    a *= a, a %= mod;
    b >>= 1;
  }
  return ans;
}
bool pd(long long l, long long r, long long Limit) {
  if (A[l] == 1) return (1 < Limit);
  long long L = l, R = min(r, nex[l] - 1), Up = A[R];
  if (Up >= Limit) return 0;
  for (long long i = R - 1; i >= L; i--) {
    long long res = A[i], cnt = Up;
    long long s1 = ksm(res, cnt, Limit), s2 = ksm(res, cnt, Limit + 1),
              s3 = ksm(res, cnt, Limit + 2);
    if (s1 != s2 || s2 != s3 || s1 != s3) return 0;
    Up = s1;
  }
  return 1;
}
long long solve(long long l, long long r, long long step) {
  if (A[l] == 1) return A[l] % ste[step];
  if (l == r) return A[l] % ste[step];
  if (ste[step] == 1) return 0;
  bool f = pd(l + 1, r, ste[step + 1]);
  if (!f)
    return ksm(A[l], solve(l + 1, r, step + 1) + ste[step + 1], ste[step]);
  return ksm(A[l], solve(l + 1, r, step + 1), ste[step]);
}
signed main() {
  N = read(), p = read();
  for (long long i = 1; i <= N; i++) A[i] = read();
  ste[1] = p;
  for (long long i = 2; ste[i - 1] != 1; i++) ste[i] = Get(ste[i - 1]);
  ps = N + 1;
  for (long long i = N; i >= 1; i--) {
    nex[i] = ps;
    if (A[i] == 1) ps = i;
  }
  Q = read();
  while (Q--) {
    long long l = read(), r = read();
    printf("%lld\n", solve(l, r, 1));
  }
}
