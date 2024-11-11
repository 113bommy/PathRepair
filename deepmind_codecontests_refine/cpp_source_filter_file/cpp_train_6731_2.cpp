#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, sk = 0;
  cin >> n >> m;
  vector<double> r(n), c(m, 0), k(m);
  for (int i = 0; i < (int)n; ++i) {
    cin >> r[i];
    --r[i];
  }
  for (int i = 0; i < (int)m; ++i) {
    cin >> k[i];
    sk += k[i];
  }
  for (int i = 0; i < (int)sk; ++i) ++c[r[i]];
  if (c == k) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = (int)sk; i < (int)n; ++i) {
    ++c[r[i]];
    --c[r[i - m]];
    if (c == k) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
