#include <bits/stdc++.h>
using namespace std;
bool *Seive(long long n, bool *p) {
  memset(p, 1, sizeof(p));
  long long i, j;
  for (i = 2; i <= n; i++) {
    if (p[i] == 1)
      for (j = i * i; j <= n; j += i) {
        p[j] = 0;
      }
  }
  p[1] = 0;
  return p;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long modexp(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0) {
    return modexp((x * x) % (long long)(1e9 + 7), y / 2);
  } else {
    return (x * modexp((x * x) % (long long)(1e9 + 7), (y - 1) / 2)) %
           (long long)(1e9 + 7);
  }
}
long long fact(long long n) {
  long long f = 1;
  for (long long i = 2; i <= n; i++) {
    f = (i % (long long)(1e9 + 7) * f % (long long)(1e9 + 7)) %
        (long long)(1e9 + 7);
  }
  return f;
}
long long nCr(long long n, long long r) {
  return (fact(n) * modexp((fact(n - r) * fact(r)) % (long long)(1e9 + 7),
                           (long long)(1e9 + 7) - 2)) %
         (long long)(1e9 + 7);
}
void showlist(list<int> g) {
  list<int>::iterator it;
  for (it = g.begin(); it != g.end(); ++it) cout << *it << " ";
  cout << '\n';
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
struct Point {
  int x, y;
};
long long overlappingArea(long long x3, long long x4, long long x5,
                          long long x6, long long y3, long long y4,
                          long long y5, long long y6) {
  long long area1 = abs(x3 - x4) * abs(y3 - y4);
  long long area2 = abs(x5 - x6) * abs(y5 - y6);
  long long areaI = (min(x4, x6) - max(x3, x5)) * (min(y4, y6) - max(y3, y5));
  if (areaI <= 0) areaI = 0;
  return (area1 + area2 - areaI);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long a, x1, x2, y1, y2, x3, x4, x5, x6, y3, y4, y5, y6;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;
  if (x4 > x2) {
    x4 = x2;
  }
  if (x3 < x1) {
    x3 = x1;
  }
  if (y4 > y2) {
    y4 = y2;
  }
  if (y3 < y1) {
    y3 = y1;
  }
  cin >> x5 >> y5 >> x6 >> y6;
  if (x6 > x2) {
    x6 = x2;
  }
  if (x5 < x1) {
    x5 = x1;
  }
  if (y6 > y2) {
    y6 = y2;
  }
  if (y5 < y1) {
    y5 = y1;
  }
  a = 0;
  if (x4 - x3 <= 0 || y4 - y3 <= 0 && (x6 - x5 <= 0 || y6 - y5 <= 0))
    ;
  else if (x4 - x3 <= 0 || y4 - y3 <= 0) {
    a = (x6 - x5) * (y6 - y5);
  } else if (x6 - x5 <= 0 || y6 - y5 <= 0) {
    a = (x4 - x3) * (y4 - y3);
  } else {
    a = overlappingArea(x3, x4, x5, x6, y3, y4, y5, y6);
  }
  if (a == (x2 - x1) * (y2 - y1)) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
