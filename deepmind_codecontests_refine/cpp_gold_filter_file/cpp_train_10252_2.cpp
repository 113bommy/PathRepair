#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000 * 1000 * 1000 + 7;
constexpr int maxn = 500 + 10;
int main() {
  array<array<ll, maxn>, maxn> d = {}, d2 = {};
  array<ll, maxn> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  d[n - 1][n - 1] = 1;
  d[n][n - 1] = 1;
  for (int i = n - 2; i >= 0; --i) {
    d[i][i] = d[i][i + 1] = d[i + 1][i] = 1;
    d2[i][i + 1] = 1;
    for (int j = i + 2; j < n; ++j) {
      for (int k = i + 1; k < j; ++k) {
        if (v[k] < v[j]) {
          d2[i][j] += (d2[i][k] * d[k][j - 1]) % mod;
        }
      }
      d2[i][j] %= mod;
      for (int k = i + 1; k <= j; ++k) {
        d[i][j] += (d2[i][k] * d[k][j]) % mod;
      }
      d[i][j] %= mod;
    }
  }
  cout << d[0][n - 1] << endl;
  return 0;
}
