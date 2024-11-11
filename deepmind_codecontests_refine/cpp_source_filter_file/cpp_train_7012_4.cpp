#include <bits/stdc++.h>
using namespace std;
template <class T>
T bigmod(T base, T power) {
  T tem, t;
  if (power == 1) {
    return base;
  }
  if (power == 0) {
    return 1;
  }
  t = bigmod(base, power / 2);
  tem = t * t;
  tem %= 1000000007;
  if (power & 1) {
    tem *= base;
    tem %= 1000000007;
  }
  return tem;
};
long long n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  long long mm = bigmod<long long>(2, m) - 1;
  mm += 1000000007;
  mm %= 1000000007;
  long long cur = mm;
  long long ans = 1;
  for (int i(0), _n(n); i < _n; ++i) {
    ans *= cur;
    ans %= 1000000007;
    cur--;
    if (cur < 0) cur = mm;
  }
  cout << ans << endl;
}
