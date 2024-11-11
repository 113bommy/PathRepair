#include <bits/stdc++.h>
int a[200005], b[200005];
using namespace std;
inline double cal_possible(int n, int learned_num) {
  double c2 = 1.5 * static_cast<double>(n - learned_num) / n *
              (n - learned_num - 1) / (n - 1) * (learned_num) / (n - 2);
  double c3 = static_cast<double>(n - learned_num) / n * (n - learned_num - 1) /
              (n - 1) * (n - learned_num - 2) / (n - 2);
  return 1 - c2 - c3;
}
int main() {
  ios::sync_with_stdio(false);
  if (0) freopen("data.in", "r", stdin);
  int n;
  double p;
  cin >> n >> p;
  int l = 0, r = n - 1;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    double ans = cal_possible(n, mid);
    if (0) cout << "when " << mid << " " << ans << endl;
    if (cal_possible(n, mid) >= p) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;
}
