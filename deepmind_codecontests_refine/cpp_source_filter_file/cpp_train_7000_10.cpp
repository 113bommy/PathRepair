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
const long long MAXN = 5e5 + 11;
long long N, A[MAXN], X, S[MAXN], res;
void solve() {
  long long L = 0, R = N + 1;
  for (long long i = 1; i <= (N + 1) / 2; i++) {
    long long l = res + 1, r = N;
    if (l > r) return;
    long long Res = -1;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (S[mid] > S[i - 1])
        Res = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    if (res == -1) return;
    L = max(L, res - i + 1), R = min(R, Res - i + 1);
    long long Len = N - i;
    if (L <= N - i + 1 && N - i + 1 <= R) {
      printf("%lld\n", N - i + 1);
      exit(0);
    }
  }
  if (L <= R) {
    printf("%lld\n", L);
    exit(0);
  }
  return;
}
signed main() {
  N = read();
  for (long long i = 1; i <= (N + 1) / 2; i++) A[i] = read();
  res = N - (N + 1) / 2;
  X = read();
  for (long long i = (N + 1) / 2 + 1; i <= N; i++) A[i] = X;
  for (long long i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
  long long k = (X <= 0) ? res + 1 : N;
  bool ff = 1;
  for (long long i = 1; i + k - 1 <= N; i++) ff &= (S[i + k - 1] > S[i - 1]);
  if (ff)
    printf("%lld\n", k);
  else {
    if (X < 0) solve();
    printf("-1\n");
    return 0;
  }
}
