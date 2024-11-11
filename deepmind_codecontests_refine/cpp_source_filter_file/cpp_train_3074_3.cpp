#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = double;
using f80 = long double;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
using ptx = pair<f64, f64>;
i64 sum, xsum, ant;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  i64 tsum, a(0), b(0);
  cin >> sum >> xsum;
  ant = 1;
  tsum = sum;
  for (int lg = 4; lg >= 0; --lg) {
    i64 add = 1LL << lg;
    if (~xsum & (1LL << lg)) {
      add *= 2;
      if (tsum - add >= 0) {
        a += add / 2;
        b += add / 2;
        tsum -= add;
      }
    } else {
      ant *= 2;
      if (tsum - add >= 0) {
        a += add;
        tsum -= add;
      }
    }
  }
  if (b == 0) ant -= 2;
  if (a + b == sum && (a ^ b) == xsum)
    cout << ant << endl;
  else
    cout << 0 << endl;
  return 0;
}
