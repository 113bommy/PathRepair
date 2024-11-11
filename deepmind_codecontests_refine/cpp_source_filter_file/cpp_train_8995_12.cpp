#include <bits/stdc++.h>
using namespace std;
long long n, x, y, dx, dy, t;
vector<vector<long long>> d = {{2, 1, 1, 1, 0, 0}, {1, 2, 1, 1, 0, 0},
                               {1, 0, 1, 0, 0, 0}, {0, 1, 0, 1, 0, 0},
                               {1, 1, 1, 1, 1, 0}, {2, 2, 2, 2, 1, 1}};
vector<vector<long long>> mul(vector<vector<long long>> a,
                              vector<vector<long long>> b) {
  vector<vector<long long>> c(a.size(), vector<long long>(a[0].size()));
  for (long long i = 0; i < a.size(); ++i) {
    for (long long j = 0; j < b[0].size(); ++j) {
      for (long long k = 0; k < a[0].size(); ++k) {
        c[i][j] += (a[i][k] * b[k][j] + n) % n;
        c[i][j] %= n;
      }
    }
  }
  return c;
}
vector<vector<long long>> bp(vector<vector<long long>> a, long long n) {
  vector<vector<long long>> ans = {{1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0},
                                   {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0},
                                   {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1}};
  while (n) {
    if (n % 2) ans = mul(ans, a);
    a = mul(a, a);
    n /= 2;
  }
  return ans;
}
signed main() {
  cin >> n >> x >> y >> dx >> dy >> t;
  vector<vector<long long>> ans = mul({{x - 1, y - 1, dx, dy, 0, 1}}, bp(d, t));
  cout << ans[0][0] + 1 << ' ' << ans[0][1] + 1;
  return 0;
}
