#include <bits/stdc++.h>
using namespace std;
template <class T>
T __sqr(const T x) {
  return x * x;
}
template <class T, class X>
inline T __pow(T a, X y) {
  T z = 1;
  for (int i = 1; i <= y; i++) {
    z *= a;
  }
  return z;
}
template <class T>
inline T __gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  if (!b) return a;
  return __gcd(b, a % b);
}
template <class T>
inline T __lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / _gcd(a, b)) * b;
}
inline bool ispow2(int x) { return (x != 0 && (x & (x - 1)) == 0); }
template <class T>
void UpdateMin(T &x, T y) {
  if (y < x) {
    x = y;
  }
}
template <class T>
void UpdateMax(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
template <class T, class X>
int getbit(T s, X i) {
  return (s >> i) & 1;
}
template <class T, class X>
T onbit(T s, X i) {
  return s | (T(1) << i);
}
template <class T, class X>
T offbit(T s, X i) {
  return s & (~(T(1) << i));
}
inline int read() {
  int res = 0;
  int neg;
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9' || ch == '-') {
      if (ch == '-')
        neg = -1;
      else
        neg = 1, res = ch - '0';
      break;
    }
  }
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9')
      res *= 10, res += ch - '0';
    else
      break;
  }
  return res * neg;
}
long long n, k, a[50];
double dp[55][55][210];
double go(int x, int y, int k) {
  if (k == 0) return (x > y);
  double &ret = dp[x][y][k];
  if (!(ret == ret)) {
    ret = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        int a = x;
        int b = y;
        if (i <= a && a <= j) {
          a = j - (a - i);
        }
        if (i <= b && b <= j) {
          b = j - (b - i);
        }
        ret += go(a, b, k - 1);
      }
    }
    ret /= (n * (n + 1)) / 2.0;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, -1, sizeof dp);
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] < a[j]) {
        ans += go(i, j, k);
      } else {
        ans += (1 - go(i, j, k));
      }
    }
  }
  cout << setprecision(15) << fixed << ans << endl;
  return 0;
}
