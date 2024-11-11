#include <bits/stdc++.h>
using namespace std;
const int ooU = 2147483647;
const long long ooT = 9223372036854775807;
template <class _TYPE_>
_TYPE_ smin(_TYPE_ &a, _TYPE_ b) {
  return a = min(a, b);
}
template <class _TYPE_>
_TYPE_ smax(_TYPE_ &a, _TYPE_ b) {
  return a = max(a, b);
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long read() {
  long long d = 0, f = 1;
  char c = ' ';
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; d = d * 10 + c - 48, c = getchar())
    ;
  return d * f;
}
int n, a[1001], b[1001];
int inside(int a, int b, int c, int i, int j) {
  if (b > c) swap(b, c);
  return (b < a || b == a && j > i) && (a < c || a == c && i > j);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read() + a[i];
  int s1 = 0, s2 = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int x = inside(a[j], a[i], b[i], j, i);
      int y = inside(b[i], a[j], b[j], i, j);
      int z = x + y;
      if (z == 2)
        s1 += 2;
      else
        s2 += z;
    }
  cout << s1 + s2 / 2 << endl;
}
