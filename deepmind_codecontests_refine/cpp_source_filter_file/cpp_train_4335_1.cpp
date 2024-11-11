#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
long long n, m, i, j, mod, fac[100005], inv[100005], g[100005][18], l, r, t,
    ans;
vector<long long> all;
long long qp(long long x, long long y) {
  long long z = 1;
  while (y) {
    if (y & 1) z = z * x % mod;
    x = x * x % mod;
    y /= 2;
  }
  return z;
}
long long phi(long long x) {
  long long s = x, i;
  for (i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      s = s / i * (i - 1);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    s = s / x * (x - 1);
  }
  return s;
}
long long c(long long n, long long m) {
  if (m > n) return 0;
  long long s = fac[n] * inv[m] % mod * inv[n - m] % mod, i;
  for (i = 0; i < all.size(); i++) {
    s = s * qp(all[i], g[n][i] - g[m][i] - g[n - m][i]) % mod;
  }
  return s;
}
int main() {
  read(n);
  read(mod);
  read(l);
  read(r);
  t = mod;
  for (i = 2; i * i <= t; i++) {
    if (t % i == 0) {
      all.push_back(i);
      while (t % i == 0) {
        t /= i;
      }
    }
  }
  if (t > 1) {
    all.push_back(t);
  }
  long long pm = phi(mod);
  fac[0] = inv[0] = 1;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    long long x = i;
    for (j = 0; j < all.size(); j++) {
      g[i][j] = g[i - 1][j];
      while (x % all[j] == 0) {
        x /= all[j];
        g[i][j]++;
      }
    }
    fac[i] = fac[i - 1] * x % mod;
    inv[i] = qp(fac[i], pm - 1);
  }
  for ((i) = (0); (i) <= (n); (i)++) {
    long long m = n - i;
    ans +=
        c(n, i) * (c(m, (m + l + 1) / 2) - c(m, (m + min(r, m)) / 2 + 1)) % mod;
  }
  cout << (ans + mod) % mod;
  return 0;
}
