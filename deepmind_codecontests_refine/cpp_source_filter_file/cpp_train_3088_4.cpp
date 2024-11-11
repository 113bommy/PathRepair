#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
inline void judge() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
const int mod = 1e9 + 9;
const int maxn = 1000005;
int a, b, n, k;
char str[maxn];
int s[maxn];
inline int powmod(int a, int b) {
  int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
  }
  return res;
}
int main() {
  read(n);
  read(a);
  read(b);
  read(k);
  scanf("%s", str + 1);
  for (int i = (0); i <= (k - 1); i++) s[i] = (str[i + 1] == '+') ? 1 : -1;
  int p = 0, x = 0;
  for (int i = (0); i <= (k - 1); i++) {
    p = (p + 1ll * powmod(a, n - i) * powmod(b, i) * s[i] % mod + mod) % mod;
  }
  x = 1ll * powmod(b, k) * powmod(powmod(a, mod - 2), k) % mod;
  int res = 0, m = (n + 1) / k - 1;
  if (x == 1) {
    res = 1ll * res * p % mod;
  } else {
    res = (1ll * powmod(x, m + 1) * p - p + mod) % mod;
    res = 1ll * res * powmod(x - 1, mod - 2) % mod;
    res = (res + mod) % mod;
  }
  cout << res << endl;
  return 0;
}
