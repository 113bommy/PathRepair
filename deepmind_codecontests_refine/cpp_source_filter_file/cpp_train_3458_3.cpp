#include <bits/stdc++.h>
using namespace std;
const long long NUM = 1e9 + 7;
#pragma GCC optimize("Ofast")
static auto x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
int main() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  map<int, int> mm;
  int res = 0;
  for (int j = 0; j < m; j++) {
    int ans = n;
    for (int i = 0; i < n; i++) {
      if (a[i][j] % m == (j + 1) % m && a[i][j] < n * m) {
        int off = (n + (a[i][j] - (m * i + j + 1)) / m) % n;
        mm[off]++;
        ans = min(ans, (n - mm[off]) + (n - off) % n);
      }
    }
    res += ans;
    mm.clear();
  }
  cout << res;
  return 0;
}
