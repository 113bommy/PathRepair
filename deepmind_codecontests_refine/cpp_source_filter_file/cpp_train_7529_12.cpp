#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n;
  vector<vector<int> > m;
  for (int i = 0; i < n; ++i) {
    int tmp;
    vector<int> tmp_m;
    for (int j = 0; j < n; ++j) {
      cin >> tmp;
      tmp_m.push_back(tmp);
    }
    m.push_back(tmp_m);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += m[i][i];
    ans += m[n - i - 1][n - i - 1];
    ans += m[(n - 1) / 2][i];
    ans += m[i][(n - 1) / 2];
  }
  ans -= m[(n - 1) / 2][(n - 1) / 2] * 3;
  cout << ans;
  return 0;
}
