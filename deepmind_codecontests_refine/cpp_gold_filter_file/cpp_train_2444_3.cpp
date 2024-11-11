#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433832795;
long long int inp() {
  long long int n = 0, s = 1;
  char c;
  for (c = getchar(); c < 48 || c > 58; c = getchar())
    if (c == '-') s = -1;
  for (; c > 47 && c < 59; c = getchar()) n = n * 10 + c - 48;
  return n * s;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    gcd(b, a % b);
}
long long int square(long long int n) { return n * n; }
long long int bigmod(long long int b, long long int p, long long int m) {
  if (p == 0)
    return 1;
  else if (p % 2 == 0)
    return square(bigmod(b, p / 2, m)) % m;
  else
    return ((b % m) * bigmod(b, p - 1, m)) % m;
}
long long mulmod(long long a, long long b, long long c) {
  long long x = 0, y = a % c;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x + y) % c;
    }
    y = (y * 2) % c;
    b /= 2;
  }
  return x % c;
}
long long int vis[55][55], n, m;
char ch[55][55];
long long int fun(long long int i, long long int j, char z, char d) {
  long long int p = 0;
  vis[i][j] = 1;
  if ((j + 1) < m && vis[i][j + 1] == 0 && ch[i][j + 1] == z && d != 'l') {
    p = fun(i, j + 1, z, 'r');
  } else if ((j + 1) < m && vis[i][j + 1] == 1 && ch[i][j + 1] == z &&
             d != 'l') {
    return 1;
  }
  if ((i + 1) < n && vis[i + 1][j] == 0 && ch[i + 1][j] == z && d != 'u') {
    p = fun(i + 1, j, z, 'd');
  } else if ((i + 1) < n && vis[i + 1][j] == 1 && ch[i + 1][j] == z &&
             d != 'u') {
    return 1;
  }
  if ((j - 1) >= 0 && vis[i][j - 1] == 0 && ch[i][j - 1] == z && d != 'r') {
    p = fun(i, j - 1, z, 'l');
  } else if ((j - 1) >= 0 && vis[i][j - 1] == 1 && ch[i][j - 1] == z &&
             d != 'r') {
    return 1;
  }
  if ((i - 1) >= 0 && vis[i - 1][j] == 0 && ch[i - 1][j] == z && d != 'd') {
    p = fun(i - 1, j, z, 'u');
  } else if ((i - 1) >= 0 && vis[i - 1][j] == 1 && ch[i - 1][j] == z &&
             d != 'd') {
    return 1;
  }
  return p;
}
int main() {
  long long int t, ans = 0, i, j, k;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) cin >> ch[i][j];
  }
  long long int f = 0;
  for (k = 0; k < 25; k++) {
    f = 0;
    for (i = 0; i < n; i++) {
      f = 0;
      for (j = 0; j < m; j++) {
        if (ch[i][j] == (char)('A' + k) && vis[i][j] != 1 &&
            fun(i, j, (char)('A' + k), 'a')) {
          cout << "Yes\n";
          f = 1;
          break;
        }
      }
      if (f == 1) break;
    }
    if (f == 1) {
      break;
    }
  }
  if (f == 0) cout << "No\n";
  return 0;
}
