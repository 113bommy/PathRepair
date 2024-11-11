#include <bits/stdc++.h>
const double eps = 1e-8;
const int mod = 8 * 9 * 7 * 11 * 13 * 5;
const int maxn = 205;
const double pi = acos(-1.0);
const int INF = 0x7f7f7f7f;
const double inf = 1e50;
template <class T>
inline T minx(T a, T b) {
  return (a == -1 || b < a) ? b : a;
}
template <class T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
inline T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <class T>
inline T getbit(T n) {
  return n ? (1 + getbit(n & (n - 1))) : 0;
}
template <class T>
inline T lowbit(T n) {
  return n & (-n);
}
using namespace std;
long long dp[mod + 2];
long long a, b, k, c, y = 0, l, i, t;
int main() {
  cin >> a >> b >> k;
  while (a > b) {
    l = 1;
    for (i = 2; i <= k; i++) {
      t = a % i;
      if ((t > l) && (a - t) >= b) l = t;
    }
    y++, a -= l;
    if (dp[a % mod]) {
      c = y - dp[a % mod];
      y += c * ((a - b) / mod);
      a -= ((a - b) / mod) * mod;
    }
    dp[a % mod] = y;
  }
  cout << y << endl;
  return 0;
}
