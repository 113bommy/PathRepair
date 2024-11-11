#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template <typename T>
using VT = vector<T>;
template <typename T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;
const double EPS = 1e-9;
const int MAX = 1010;
int N, H;
long double ans[MAX];
int main() {
  scanf("%d%d", &N, &H);
  const long double one = ((1. * H) / 2) / N;
  long double pre = 0, presum = 0;
  for (int(i) = 0; (i) < (N); (i)++) {
    long double high = H, low = pre;
    for (int(_) = 0; (_) < (1000); (_)++) {
      long double mid = (high + low) / 2;
      if (mid / 2 * (mid / H) - presum <= one)
        low = mid;
      else
        high = mid;
    }
    ans[i] = low;
    pre = low;
    presum = one;
  }
  for (int(i) = 0; (i) < (N - 1); (i)++) {
    cout << fixed << setprecision(20) << ans[i]
         << (i + 1 == N - 1 ? "\n" : " ");
  }
}
