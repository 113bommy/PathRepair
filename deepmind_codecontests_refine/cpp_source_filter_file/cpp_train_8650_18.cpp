#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline int read(T& x) {
  x = 0;
  char c = getchar(), f = 1;
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    if (c == -1) return -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  c *= f;
  return 1;
}
template <typename T, typename... Args>
inline int read(T& x, Args&... args) {
  return read(x) + read(args...);
}
template <typename T>
inline int write(T x) {
  if (x < 0) return putchar('-') & write((~x) + 1);
  if (x / 10) return write(x / 10) & putchar(x % 10 | 48);
  return putchar(x | 48);
}
template <typename T>
inline int write(T x, char c) {
  return write(x) + putchar(c);
}
inline long long ksc(long long a, long long b, long long mod) {
  long long ans = 0;
  a %= mod, b %= mod;
  while (b) {
    if (b & 1) ans = (ans + a) % mod;
    a <<= 1, b >>= 1, a %= mod;
  }
  return ans;
}
inline long long ksm(long long a, long long b, long long mod) {
  long long ans = 1;
  a %= mod;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return ans;
}
int n;
bool dp[105][10005][2];
int cnt[105];
signed main() {
  read(n);
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    read(x);
    cnt[x]++;
    for (int j = i; j >= 0; j--)
      for (int k = 0; k <= 10000; k++) {
        if (dp[j][k][0]) {
          dp[j + 1][k + x][0] = 1;
          if ((k + x) % (j + 1) == 0 && x * j != k) dp[j + 1][k + x][1] = 1;
        }
      }
  }
  int ans = 0, tot = 0;
  for (int i = 1; i <= 100; i++) {
    tot += !!cnt[i];
    for (int j = 1; j <= cnt[i]; j++) {
      if (dp[j][i * j][1]) continue;
      ans = max(ans, j);
    }
  }
  write(tot <= 2 ? n : ans, '\n');
}
