#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long linf = 2e18;
const long long mod = 1e9 + 7;
template <typename T>
ostream& operator<<(ostream& s, vector<T>& v) {
  for (auto el : v) {
    s << el << " ";
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  vector<vector<long long>> c(1000, vector<long long>(1000));
  for (int i = 0; i < 1000; i++) {
    c[i][i] = 1;
    c[i][0] = 1;
  }
  for (int n = 1; n < 1000; n++) {
    for (int k = 1; k <= n; k++) {
      c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
      c[n][k] %= mod;
    }
  }
  int n, m, k;
  cin >> n >> m >> k;
  cout << c[n - 1][2 * k] * c[m - 1][2 * k] % mod << endl;
  return 0;
}
