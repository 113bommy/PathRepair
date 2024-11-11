#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long c, d, i, j, k, l, m, n, x, y, z, r, sum = 0, ans = 0, tmp;
  cin >> n;
  vector<long long> v(n);
  for (auto &it : v) cin >> it;
  if (n > 1) {
    cout << "1 " << n << '\n';
    for (i = 0; i < n; i++) {
      cout << -(v[i] * n) << " ";
    }
    cout << "\n2 " << n << '\n';
    for (i = 1; i < n; i++) {
      cout << v[i] * (n - 1) << " ";
    }
    cout << "\n1 1" << '\n';
    cout << v[0] * n;
  } else {
    cout << "1 1\n" << -v[0] << "\n1 1\n0\n1 1\n0";
  }
}
int main() {
  ios::sync_with_stdio(0);
  ;
  int t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
