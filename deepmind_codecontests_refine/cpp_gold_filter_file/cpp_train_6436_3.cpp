#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int64_t>> x(3, vector<int64_t>(n));
  for (int i = 0; i < n; ++i) {
    cin >> x[0][i] >> x[1][i] >> x[2][i];
  }

  int64_t ans = -1001001001001001ll;
  for (int bit = 0; bit < 8; ++bit) {
    vector<int64_t> v(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 3; ++j) {
        v[i] += (bit & (1 << j) ? -1 : 1) * x[j][i];
      }
    }

    sort(v.rbegin(), v.rend());
    ans = max(ans, (int64_t)accumulate(v.begin(), v.begin() + m, 0ll));
  }

  cout << ans << endl;
}
