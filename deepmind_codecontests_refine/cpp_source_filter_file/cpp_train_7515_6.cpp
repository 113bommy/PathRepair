#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e18;
template <typename T>
inline void read(T &x) {
  x = 0;
  T fg = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fg = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x = fg * x;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x), read(args...);
}
template <typename T>
inline void write(T x) {
  int len = 0;
  char c[21];
  if (x < 0) putchar('-'), x = -x;
  do {
    ++len;
    c[len] = x % 10 + '0';
  } while (x /= 10);
  for (int i = len; i >= 1; i--) putchar(c[i]);
}
template <typename T, typename... Args>
inline void write(T x, Args... args) {
  write(x), write(args...);
}
int prime[100000 + 1];
void getPrime() {
  for (int i = 2; i <= 100000; i++) {
    if (!prime[i]) prime[++prime[0]] = i;
    for (int j = 1; j <= prime[0] && (long long)i * prime[j] <= 100000; j++) {
      prime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int n;
long long a[1000005];
long long f[1000005];
long long solve(long long fac) {
  if (fac == 1) return INF;
  long long res = 0, cnta = 0;
  for (int i = 1; i <= n; i++) {
    res += min(cnta, fac - cnta);
    cnta += a[i];
    cnta %= fac;
  }
  return res;
}
int main() {
  getPrime();
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    read(a[i]);
    sum += a[i];
  }
  long long ans = INF;
  for (int i = 1; i <= prime[0] && prime[i] <= sum; i++)
    if (sum % prime[i] == 0) {
      ans = min(ans, solve(prime[i]));
      while (sum % prime[i] == 0) {
        sum /= prime[i];
      }
    }
  ans = min(ans, solve(sum));
  if (ans == INF) ans = -1;
  cout << ans << '\n';
  return 0;
}
