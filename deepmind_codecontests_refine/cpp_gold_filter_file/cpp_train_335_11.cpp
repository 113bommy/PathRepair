#include <bits/stdc++.h>
const int N = 2e6 + 5;
const int Mod = 1e9 + 7;
int T, n;
long long f[N];
template <typename T>
inline void read(T &a) {
  a = 0;
  int f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    a = a * 10 + c - '0';
    c = getchar();
  }
  a *= f;
}
int main() {
  f[1] = 0, f[2] = 0, f[3] = 4, f[4] = 4, f[5] = 12;
  for (int i = 6; i < N; i++) {
    f[i] = 2 * f[i - 2] + f[i - 1];
    f[i] += (i % 3 == 0) ? 4 : 0;
    f[i] %= Mod;
  }
  read(T);
  while (T--) {
    read(n);
    printf("%lld\n", f[n]);
  }
  return 0;
}
