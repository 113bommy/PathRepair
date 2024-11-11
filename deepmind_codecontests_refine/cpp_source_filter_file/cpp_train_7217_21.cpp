#include <bits/stdc++.h>
using namespace std;
int static_init = []() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout << fixed;
  return 0;
}();
constexpr int N = 18;
float a[N][N], p[1 << N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> a[i][j];
  }
  vector<bool> v(1 << n);
  vector<int32_t> q[2];
  q[0].push_back((1 << n) - 1);
  p[q[0][0]] = 1;
  while (!q[0].empty()) {
    int m = __builtin_popcount(q[0][0]);
    if (m == 1) break;
    int mm = m * (m - 1) / 2;
    q[1].clear();
    for (int t : q[0]) {
      ;
      for (int j = 0; j < n; j++) {
        if (!(t & (1 << j))) continue;
        int tt = t & ~(1 << j);
        for (int i = 0; i < n; i++) {
          if (i != j && (t & (1 << i))) {
            p[tt] += p[t] * a[i][j] / mm;
          }
        }
        if (!v[tt]) {
          v[tt] = true;
          q[1].push_back(tt);
        }
      }
    }
    swap(q[0], q[1]);
  }
  cout << setprecision(6);
  for (int i = 0; i < n; i++) {
    cout << p[1 << i] << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
