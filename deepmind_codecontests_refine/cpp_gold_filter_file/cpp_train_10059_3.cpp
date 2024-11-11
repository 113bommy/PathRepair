#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const double eps = 0.000001;
int q(int i, int j, vector<int> &ps) {
  if (i > j) return 0;
  if (i) return ps[j] - ps[i - 1];
  return ps[j];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> ps(n + 1, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ps[i + 1] = ps[i] + (int)(s[i] == 'a');
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j <= n; j++) {
      int cr = i - q(0, i, ps) + (n - j) - q(j + 1, n, ps) + q(i + 1, j, ps);
      ans = max(ans, n - cr);
    }
  }
  cout << ans << endl;
  return 0;
}
