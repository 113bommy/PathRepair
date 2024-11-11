#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;
using pii = pair<int, int>;
using vi = vector<int>;
namespace Bit {
using T = int;
vector<T> v;
int n;
inline int up(int i) { return i + (i & -i); }
inline int down(int i) { return i - (i & -i); }
void init(int _n) {
  v.resize(_n + 1, 0);
  n = _n;
}
void clear() { v.assign(n + 1, 0); }
void add(int x, T val) {
  for (; x <= n; x = up(x)) v[x] += val;
}
T sum(int x) {
  T ret = 0;
  for (; x; x = down(x)) {
    ret += v[x];
  }
  return ret;
}
};  // namespace Bit
const int N = 1e5 + 5;
int a[N];
ll cal(int l, int r) {
  ll res = 0;
  for (int i = l; i <= r; ++i) {
    res += i - l - Bit::sum(a[i]);
    Bit::add(a[i], 1);
  }
  Bit::clear();
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  Bit::init(n);
  double ori = 0;
  ori = cal(1, n);
  double res0 = 0, res = 0, ans = 0;
  double deno = (n * (n + 1)) / 2;
  double summ = 0;
  for (int i = n; i >= 1; --i) {
    double l = (n - i + 1);
    res0 = Bit::sum(a[i]) * i;
    summ += res0;
    res = (l - 1) * l / 4 * (n - l + 1);
    ans += (res - res0);
    Bit::add(a[i], l);
  }
  ans = ans / deno;
  printf("%.15lf\n", ori + ans);
  return 0;
}
