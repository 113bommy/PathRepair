#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
const double DELTA = 1e-12;
const int INF = ~(1 << 31);
const long long LINF = ~(1LL << 63);
const int MOD = (int)998244353;
const int MAXN = 3e5 + 10;
long long sy, a, b, n, l, r, q, x, y;
long long a1, b1, c1, a2, b2, c2;
vector<long long> fence{};
vector<long long> sums{};
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> sy >> a >> b >> n;
  sums.push_back(0);
  fence.push_back(0);
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    fence.push_back(l);
    fence.push_back(r);
    int len = r - l;
    sums.push_back(sums[sums.size() - 1] + len);
  }
  fence.push_back(1e9 + 10);
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> x >> y;
    a1 = y - sy;
    b1 = a - x;
    c1 = -a1 * x - b1 * y;
    double x1 = -c1 / (a1 + 0.);
    long long leftFenceIdx =
        lower_bound((fence).begin(), (fence).end(), x1) - fence.begin();
    a2 = y - sy;
    b2 = b - x;
    c2 = -a2 * x - b2 * y;
    double x2 = -c2 / (a2 + 0.);
    long long rightFenceIdx =
        prev(upper_bound((fence).begin(), (fence).end(), x2)) - fence.begin();
    double coef = x != a ? (x - a) / (x - x1) : (x - b) / (x - x2);
    double currSum = 0;
    if (leftFenceIdx % 2 == 0) {
      currSum += fence[leftFenceIdx] - x1;
    }
    if (rightFenceIdx % 2 == 1) {
      currSum += x2 - fence[rightFenceIdx];
    }
    if (leftFenceIdx % 2 == 0 && leftFenceIdx - rightFenceIdx == 1) {
      currSum -= (fence[leftFenceIdx] - fence[rightFenceIdx]);
    }
    if (rightFenceIdx - leftFenceIdx > 0) {
      long long rightSumsIdx = rightFenceIdx / 2 - 1;
      long long leftSumsIdx = leftFenceIdx / 2;
      currSum += sums[rightSumsIdx + 1] - sums[leftSumsIdx];
    }
    printf("%.10f\n", currSum * coef);
  }
  return 0;
}
