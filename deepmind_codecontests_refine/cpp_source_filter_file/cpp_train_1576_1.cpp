#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double n, r;
  int i, j, k;
  cin >> n >> r;
  double ans = sin(2 * 3.14159265 / n);
  ans = (r * ans) / (1 - ans);
  cout << fixed << setprecision(8) << ans;
}
