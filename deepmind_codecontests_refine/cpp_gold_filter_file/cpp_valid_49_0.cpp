#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0, f = 1;
  char ch;
  while (ch = getchar(), ch < '0' || ch > '9')
    if (ch == '-') f = -1;
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return res * f;
}
const int N = 14, M = 4782969, P = 1e9 + 7;
inline int qpow(int a, int b) {
  int ans = 1, base = a;
  while (b) {
    if (b & 1) ans = 1ll * ans * base % P;
    base = 1ll * base * base % P;
    b >>= 1;
  }
  return ans;
}
int rev[1 << N], cnt[1 << N], n, A, a[N];
int F[1 << N], G[1 << N], v[N][1 << N];
inline int get(int S, int T) {
  if (!S) return 1;
  if (G[S]) return G[S];
  return G[S] = 1ll * get(S & (S - 1), T) * v[rev[S & -S]][T] % P;
}
int main() {
  n = read(), A = (1 << n) - 1;
  for (int i = 0; i < n; ++i) a[i] = read(), rev[1 << i] = i;
  for (int i = 0; i < n; ++i) {
    v[i][0] = 1;
    for (int S = 1; S < (1 << n); ++S)
      v[i][S] = 1ll * v[i][S & (S - 1)] * a[i] % P *
                qpow((a[rev[S & -S]] + a[i]) % P, P - 2) % P;
  }
  for (int S = 1; S < (1 << n); ++S) {
    int tmp = 0;
    cnt[S] = cnt[S >> 1] + (S & 1);
    for (int T = (S - 1) & S; T; T = (T - 1) & S)
      (tmp += 1ll * F[T] * get(S ^ T, A ^ S) % P) %= P;
    F[S] = (get(S, A ^ S) - tmp + P) % P;
    for (int T = S; T; T = (T - 1) & S) G[T] = 0;
  }
  int res = 0;
  for (int S = 1; S < (1 << n); ++S) (res += 1ll * F[S] * cnt[S] % P) %= P;
  printf("%d", res);
  return 0;
}
