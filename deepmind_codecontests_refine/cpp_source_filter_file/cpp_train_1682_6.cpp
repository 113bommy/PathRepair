#include <bits/stdc++.h>
const long long INF = 0x3f3f3f3f;
const int _INF = 0x80000000;
long long gcd(long long a, long long b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
long long lcd(long long a, long long b) { return a * b / gcd(a, b); }
inline long long read() {
  char ch = getchar();
  long long x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
using namespace std;
int main() {
  int n, m;
  long long x;
  int flag = 0;
  long long minn = 1e18;
  cin >> n >> m;
  getchar();
  long long a = read(), b = read();
  long long gcdx = abs(a - b);
  long long last = b;
  minn = minn > a ? a : minn > b ? b : minn > a ? a : minn;
  for (int i = 0; i < n - 2; i++) {
    a = read();
    minn = minn > n ? n : minn;
    gcdx = gcd(abs(a - last), gcdx);
    last = a;
  }
  x = gcdx;
  for (int i = 0; i < m; i++) {
    long long y;
    y = read();
    if (x % y == 0) flag = i + 1;
  }
  if (flag == 0)
    printf("NO\n");
  else {
    printf("YES\n");
    cout << minn << ' ' << flag << endl;
  }
}
