#include <bits/stdc++.h>
using namespace std;
int ts, kk = 1;
template <class T>
inline T _sq(T a) {
  return a * a;
}
template <class T, class X>
inline T _pow(T a, X y) {
  T z = 1;
  for (int i = 1; i <= y; i++) {
    z *= a;
  }
  return z;
}
template <class T>
inline T _gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  if (!b) return a;
  return _gcd(b, a % b);
}
template <class T>
inline T _lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / _gcd(a, b)) * b;
}
template <class T>
inline T _extended(T a, T b, T &x, T &y) {
  a = _abs(a);
  b = _abs(b);
  T g, x1, y1;
  if (!b) {
    x = 1;
    y = 0;
    g = a;
    return g;
  }
  g = _extended(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
template <class T, class X>
inline T togglebit(T a, X i) {
  T t = 1;
  return (a ^ (t << i));
}
template <class T, class X, class Y>
inline T _bigmod(T n, X m, Y mod) {
  unsigned long long ret = 1, a = n % mod;
  while (m) {
    if (m & 1) ret = (ret * a) % mod;
    m >>= 1;
    a = (a * a) % mod;
  }
  ret %= mod;
  return (T)ret;
}
template <class T, class Y>
inline T _modinv(T n, Y mod) {
  return _bigmod(n, mod - 2, mod);
}
char g[55][55];
int dir[2];
int x[30], lx, ly, n;
void dfs(int px, int py, int num, char ch) {
  g[px][py] = ch;
  x[num]--;
  if (x[num] == 0 && num + 1 == n) return;
  int one;
  if (px % 2 == 0) {
    py += dir[0];
    one = dir[0];
  } else {
    py += dir[1];
    one = dir[1];
  }
  if (py == ly) {
    px++;
    py = ly - 1;
  } else if (py == -1) {
    px++;
    py = 0;
  }
  if (g[px][py] == '.') {
    py -= one;
    if (py == -1)
      py = 0;
    else if (py == ly)
      py = ly - 1;
    px++;
  }
  if (x[num] == 0)
    dfs(px, py, num + 1, ch + 1);
  else
    dfs(px, py, num, ch);
}
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d >> n;
  for (int i = 0; i <= n - 1; i++) {
    cin >> x[i];
  }
  if ((d % 2 == 0 && b >= d) || (b % 2 == 1 && b <= d)) {
    dir[0] = +1, dir[1] = -1;
  } else {
    dir[0] = -1, dir[1] = +1;
  }
  for (int i = 0; i <= max(b, d) - 1; i++) {
    for (int j = 0; j <= a + c - 1; j++) {
      g[i][j] = '.';
    }
  }
  for (int i = 0; i <= b - 1; i++) {
    for (int j = 0; j <= a - 1; j++) {
      g[i][j] = '#';
    }
  }
  for (int i = 0; i <= d - 1; i++) {
    for (int j = a; j <= a + c - 1; j++) {
      g[i][j] = '#';
    }
  }
  lx = max(b, d);
  ly = a + c;
  if (dir[0] == 1)
    dfs(0, 0, 0, 'a');
  else
    dfs(0, ly - 1, 0, 'a');
  puts("YES");
  for (int i = 0; i <= lx - 1; i++) {
    for (int j = 0; j <= ly - 1; j++) {
      printf("%c", g[i][j]);
    }
    puts("");
  }
  return 0;
}
