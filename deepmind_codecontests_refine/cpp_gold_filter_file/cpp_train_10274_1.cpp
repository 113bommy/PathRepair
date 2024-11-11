#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
template <typename T>
void print(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
  cout << '\n';
}
template <typename T>
void print(vector<vector<T>>& a) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) cout << a[i][j] << ' ';
    cout << '\n';
  }
}
template <typename T>
void input(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) cin >> a[i];
}
template <typename T>
void input(vector<vector<T>>& a) {
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < a[i].size(); j++) cin >> a[i][j];
}
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long g = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}
void solve() {
  long long n, m, x, y, xv, yv;
  cin >> n >> m >> x >> y >> xv >> yv;
  if (xv == 0) {
    if (yv == 1)
      if (x == 0)
        cout << 0 << ' ' << m;
      else if (x == n)
        cout << n << ' ' << m;
      else
        cout << -1;
    if (yv == -1)
      if (x == 0)
        cout << 0 << ' ' << 0;
      else if (x == n)
        cout << n << ' ' << 0;
      else
        cout << -1;
    return;
  }
  if (yv == 0) {
    if (xv == 1) {
      if (y == 0)
        cout << n << ' ' << 0;
      else if (y == m)
        cout << n << ' ' << m;
      else
        cout << -1;
    }
    if (xv == -1) {
      if (y == 0)
        cout << 0 << ' ' << 0;
      else if (y == m)
        cout << 0 << ' ' << m;
      else
        cout << -1;
    }
    return;
  }
  long long r1 = -x;
  long long r2 = -y;
  if (xv < 0) r1 *= -1;
  if (yv < 0) r2 *= -1;
  if (r1 < 0) r1 += n;
  if (r2 < 0) r2 += m;
  long long x1, y1;
  long long g = gcd(n, m, x1, y1);
  if (r1 % g != r2 % g) {
    cout << -1;
    return;
  }
  long long k1 = x1 * (r2 - r1) / g;
  long long t = r1 + n * (k1 % m);
  if (t > n * m / g) t -= n * m / g;
  while (t < 0) t += n * m / g;
  long long xx = x + t * xv;
  long long yy = y + t * yv;
  xx = abs(xx);
  yy = abs(yy);
  cout << xx % (2 * n) << ' ' << yy % (2 * m);
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) solve();
}
