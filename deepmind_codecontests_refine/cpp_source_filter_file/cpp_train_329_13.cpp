#include <bits/stdc++.h>
using namespace std;
long long n, p, w, d;
long long exgcd(long long a, long long b, long long &x1, long long &y1) {
  if (!b) {
    x1 = 1, y1 = 0;
    return a;
  }
  long long x2, y2;
  long long d = exgcd(b, a % b, x2, y2);
  x1 = y2, y1 = x2 - (a / b) * y2;
  return d;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int i, j, flag = 0;
  cin >> n >> p >> w >> d;
  if (w > d) {
    flag = 1;
    swap(w, d);
  }
  long long x, y;
  long long g = exgcd(w, d, x, y);
  if (p % g != 0)
    cout << -1 << endl;
  else {
    long long s = d / g, t = w / g;
    x = (s + p % s * (x % s) % s) % s;
    y = (p - x * w) / d;
    if (x >= 0 && y >= 0 && x + y <= n) {
      if (flag)
        cout << y << ' ' << x << ' ' << n - x - y << endl;
      else
        cout << x << ' ' << y << ' ' << n - x - y << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
