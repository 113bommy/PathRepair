#include <bits/stdc++.h>
using namespace std;
void shift_left(vector<pair<int, int> > &a, int k) {
  for (int j = 0; j < k; ++j) {
    pair<int, int> tmp = a[0];
    for (int i = 1; i < a.size(); ++i) a[i - 1] = a[i];
    a[a.size() - 1] = tmp;
  }
}
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
struct Point {
  int x, y;
  Point(int i_ = 0, int j_ = 0) {
    x = i_;
    y = j_;
  }
};
long long func(long long l, long long r) {
  if (l == r) return l;
  long long tmp = r, b = 0;
  while (tmp > 1ll) {
    ++b;
    tmp = tmp >> 1ll;
  }
  if ((1ll << b) <= l)
    return func(l - (1ll << b), r - ((1ll << b))) + (1ll << b);
  if ((1ll << (b + 1ll)) - 1ll <= r) return (1ll << (b + 1ll)) - 1ll;
  return (1ll << b) - 1ll;
}
bool cmp(Point a, Point b) {
  if (a.x != b.x)
    return a.x < b.x;
  else
    return a.y < b.y;
}
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> x(n + 1), y(n + 1);
  for (int i = 0; i < m; ++i) {
    int tx, ty;
    scanf("%d%d", &tx, &ty);
    x[tx] = 1;
    y[ty] = 1;
  }
  for (int i = 2; i < n; ++i) {
    if (2 * i - 1 != n) {
      if (!x[i]) ++ans;
      if (!y[i]) ++ans;
    } else {
      if (!x[i] && !y[i]) ++ans;
    }
  }
  cout << ans;
  return 0;
}
