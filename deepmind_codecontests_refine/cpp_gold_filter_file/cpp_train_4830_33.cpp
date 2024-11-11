#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
int add(int x, int y) { return x + y >= 998244353 ? x + y - 998244353 : x + y; }
int sub(int x, int y) { return x - y < 0 ? x - y + 998244353 : x - y; }
int mul(int x, int y) { return 1LL * x * y % 998244353; }
pair<double, double> operator+(pair<double, double> x, pair<double, double> y) {
  pair<double, double> R;
  R.first = x.first + y.first;
  R.second = x.second + y.second;
  return R;
}
pair<double, double> trans(pair<double, double> x) {
  return make_pair(x.second * cos(x.first), x.second * sin(x.first));
}
void print(pair<double, double> x) { printf("%lf %lf\n", x.first, x.second); }
signed main() {
  int n = read();
  if (n <= 4) {
    cout << "No solution\n";
    return 0;
  }
  double a = 2 * acos(-1) / n;
  pair<double, double> cur = make_pair(0, 0), v = make_pair(a, 700);
  print(cur);
  for (int i = 1; i < n - 1; i++) {
    cur = cur + trans(v);
    print(cur);
    v.first += a;
    v.second += 0.01;
  }
  double x = cur.second / tan(a);
  cur.first += x, cur.second = 0;
  print(cur);
  return 0;
}
