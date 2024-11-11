#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = (0); i < (int)(n); ++i) cin >> v[i];
  double ans = 0;
  for (int i = (0); i < (int)(m); ++i) {
    int a, b, e;
    cin >> a >> b >> e;
    ans = max(ans, (1. * v[a - 1] + v[b - 1]) / e);
  }
  cout.setf(ios::fixed);
  cout.precision(8);
  cout << ans << endl;
  return 0;
}
