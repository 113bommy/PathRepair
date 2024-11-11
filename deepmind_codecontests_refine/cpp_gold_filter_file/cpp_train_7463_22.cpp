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
const long long MAXN = 1e6 + 11;
long long N, A[MAXN], B[MAXN], L;
bool calc(long long x) {
  long long l = 1, r = 1, Minn = INT_MAX;
  for (long long i = 1; i <= 2 * N; i++) {
    while (l <= 4 * N && B[l] < A[i] - x) ++l;
    while (r <= 4 * N && B[r] <= A[i] + x) ++r;
    --r;
    if (l > r) return 0;
    if (i - r > Minn) return 0;
    Minn = min(Minn, i - l);
  }
  return 1;
}
signed main() {
  N = read(), L = read();
  for (long long i = 1; i <= N; i++) A[i] = read() + L;
  for (long long i = 1; i <= N; i++) A[i + N] = A[i] + L;
  sort(A + 1, A + 2 * N + 1);
  for (long long i = 1; i <= N; i++)
    B[i] = read(), B[i + N] = B[i] + L, B[i + 2 * N] = B[i] + 2 * L,
    B[i + 3 * N] = B[i] + 3 * L;
  sort(B + 1, B + 4 * N + 1);
  long long l = 0, r = (L / 2), res = (L / 2) + 1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (calc(mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld\n", res);
  return 0;
}
