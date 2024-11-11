#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:214721677")
using namespace std;
const double Pi = acos(-1.0);
const double eps = 1e-10;
const int INF = 1000 * 1000 * 1000 + 7;
const double phi = 0.5 + sqrt(1.25);
template <typename T>
T sqr(T a) {
  return (a) * (a);
}
template <typename T>
T abs(T a) {
  return (a < 0) ? -(a) : (a);
}
template <typename T>
T gcd(T a, T b) {
  return (b) ? gcd(b, a % b) : a;
}
const int maxn = 55;
int main() {
  int na, nb, ma, mb;
  int a[maxn][maxn], b[maxn][maxn];
  string s;
  cin >> na >> ma;
  for (int i = 0, _n = (na)-1; i <= _n; ++i) {
    cin >> s;
    for (int j = 0, _n = (ma)-1; j <= _n; ++j) a[i][j] = (s[j] - '0');
  }
  cin >> nb >> mb;
  for (int i = 0, _n = (nb)-1; i <= _n; ++i) {
    cin >> s;
    for (int j = 0, _n = (mb)-1; j <= _n; ++j) a[i][j] = (s[j] - '0');
  }
  int ans = 0;
  int n = 0;
  int m = 0;
  for (int x = (-maxn), _b = (maxn); x <= _b; ++x)
    for (int y = (-maxn), _b = (maxn); y <= _b; ++y) {
      int cur = 0;
      for (int i = 0, _n = (na)-1; i <= _n; ++i)
        for (int j = 0, _n = (na)-1; j <= _n; ++j)
          if (i + x >= 0 && i + x < nb && j + y >= 0 && j + y < mb)
            cur += a[i][j] * b[i + x][j + y];
      if (cur > ans) ans = cur, n = x, m = y;
    }
  cout << n << " " << m << endl;
  return 0;
}
