#include <bits/stdc++.h>
using namespace std;
long long exp(long long x, long long y, long long p) {
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x % p) % p;
    x = (x * x) % p;
    y /= 2;
  }
  return res;
}
long long expm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x % ((long long)1e9 + 7)) % ((long long)1e9 + 7);
    x = (x * x) % ((long long)1e9 + 7);
    y /= 2;
  }
  return res;
}
long long add(long long x, long long y) {
  x += y;
  if (x >= ((long long)1e9 + 7)) return x - ((long long)1e9 + 7);
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) return x + ((long long)1e9 + 7);
  return x;
}
long long mult(long long x, long long y) {
  return (x * y) % ((long long)1e9 + 7);
}
long long rev(long long x) { return expm(x, ((long long)1e9 + 7) - 2); }
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long m = max(3 * a / 10, a - a / 250 * c);
  long long v = max(3 * b / 10, b - b / 250 * d);
  if (m > v)
    cout << "Misha";
  else if (m == v)
    cout << "Tie";
  else {
    cout << "Vasya";
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  { solve(); }
  return 0;
}
