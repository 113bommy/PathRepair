#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
const int N = 1e6 + 5;
int read() {
  int s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * f;
}
int n, m;
int s0[N], s1[N], s2[N], f[N], P[N];
int mod(int x) { return x >= Mod ? x - Mod : x; }
void FWT(int n) {
  for (int j = 1; j < n; j *= 10) {
    for (int i = n - 1; i >= 0; i--) {
      if ((i / j) % 10) {
        s0[i - j] = mod(s0[i - j] + s0[i]);
        s1[i - j] = mod(s1[i - j] + s1[i]);
        s2[i - j] = mod(s2[i - j] + s2[i]);
      }
    }
  }
}
void IFWT(int n) {
  for (int j = 1; j < n; j *= 10) {
    for (int i = 0; i < n; i++) {
      if ((i / j) % 10) {
        f[i - j] = mod(f[i - j] - f[i] + Mod);
      }
    }
  }
}
int main() {
  n = read();
  P[0] = 1;
  for (int i = 1; i < N; i++) P[i] = mod(P[i - 1] << 1);
  for (int i = 1; i <= n; i++) {
    int x = read();
    s0[x] = mod(s0[x] + 1);
    s1[x] = mod(s1[x] + x);
    s2[x] = mod(s2[x] + 1ll * x * x % Mod);
  }
  FWT(1e5);
  for (int i = 0; i < N; i++) {
    if (!s0[i]) continue;
    if (s0[i] == 1)
      f[i] = s2[i];
    else
      f[i] = 1ll * P[s0[i] - 2] * mod(1ll * s1[i] * s1[i] % Mod + s2[i]) % Mod;
  }
  IFWT(1e5);
  long long Ans = 0;
  for (int i = 0; i < N; i++) Ans ^= 1ll * i * f[i];
  printf("%lld", Ans);
  return 0;
}
