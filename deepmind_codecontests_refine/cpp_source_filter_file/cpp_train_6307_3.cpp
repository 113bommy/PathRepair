#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T mod_v(T num) {
  if (num >= 0)
    return num % 1000000007;
  else
    return (num % 1000000007 + 1000000007) % 1000000007;
}
template <class T>
inline T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
template <class T>
T fast_pow(T n, T p) {
  if (p == 0) return 1;
  if (p % 2) {
    T g = mod_v(mod_v(n) * mod_v(fast_pow(n, p - 1)));
    return g;
  } else {
    T g = fast_pow(n, p / 2);
    g = mod_v(mod_v(g) * mod_v(g));
    return g;
  }
}
template <class T>
inline T modInverse(T n) {
  return fast_pow(n, 1000000007 - 2);
}
bool equalTo(double a, double b) {
  if (fabs(a - b) <= 1e-9)
    return true;
  else
    return false;
}
bool notEqual(double a, double b) {
  if (fabs(a - b) > 1e-9)
    return true;
  else
    return false;
}
bool lessThan(double a, double b) {
  if (a + 1e-9 < b)
    return true;
  else
    return false;
}
bool lessThanEqual(double a, double b) {
  if (a < b + 1e-9)
    return true;
  else
    return false;
}
bool greaterThan(double a, double b) {
  if (a > b + 1e-9)
    return true;
  else
    return false;
}
bool greaterThanEqual(double a, double b) {
  if (a + 1e-9 > b)
    return true;
  else
    return false;
}
template <class T>
inline int in(register T &num) {
  register char c = 0;
  num = 0;
  bool n = false;
  while (c < 33) c = getchar();
  while (c > 33) {
    if (c == '-')
      n = true;
    else
      num = num * 10 + c - '0';
    c = getchar();
  }
  num = n ? -num : num;
  return 1;
}
template <class T>
T modS(T a, T b) {
  if (a >= 0) return a % b;
  return ((a % b) + b) % b;
}
template <class T>
T extended_euclid(T a, T b, T &x, T &y) {
  T xx = y = 0;
  T yy = x = 1;
  while (b) {
    T q = a / b;
    T t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}
template <class T>
T mod_inverse(T a, T n) {
  T x, y;
  T d = extended_euclid(a, n, x, y);
  if (d > 1) return -1;
  return modS(x, n);
}
int k[2];
int n;
int dp[2][7007];
int s[2][7007];
enum { rick, morty };
enum { draw, lose, win };
int status[2][7007];
int killed[2][7007];
queue<pair<pair<int, int>, int> > Q;
int main() {
  scanf("%d", &n);
  scanf("%d", &k[0]);
  for (int i = 0; i < k[0]; i++) {
    scanf("%d", &s[0][i]);
  }
  scanf("%d", &k[1]);
  for (int i = 0; i < k[1]; i++) {
    scanf("%d", &s[1][i]);
  }
  Q.push(make_pair(make_pair(rick, lose), 0));
  Q.push(make_pair(make_pair(morty, lose), 0));
  pair<pair<int, int>, int> u, v;
  int cur, next, pos, nextpos;
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    cur = u.first.first;
    next = 1 ^ cur;
    pos = u.second;
    if (status[cur][pos] != draw) continue;
    if (u.first.second == lose) {
      status[cur][pos] = lose;
      for (int i = 0; i < k[next]; i++) {
        nextpos = (n - s[next][i] + pos) % n;
        Q.push(make_pair(make_pair(next, win), nextpos));
      }
    } else {
      status[cur][pos] = win;
      for (int i = 0; i < k[next]; i++) {
        nextpos = (n - s[next][i] + pos) % n;
        killed[next][nextpos]++;
        if (killed[next][nextpos] == k[next])
          Q.push(make_pair(make_pair(next, lose), nextpos));
      }
    }
  }
  for (int p = 0; p < 2; p++) {
    for (int j = 2; j <= n; j++) {
      if (j > 2) printf(" ");
      if (status[p][j] == draw)
        printf("Loop");
      else if (status[p][j] == lose)
        printf("Lose");
      else
        printf("Win");
    }
    printf("\n");
  }
  return 0;
}
