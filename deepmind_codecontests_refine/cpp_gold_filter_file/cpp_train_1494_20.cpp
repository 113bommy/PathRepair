#include <bits/stdc++.h>
using namespace std;
static int m1[2000000];
static vector<vector<int> > vc, vc1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, x, res = 1, k;
  cin >> n >> m >> k;
  vc.resize(m);
  vc1.resize(m);
  for (int i = 0; i < n; ++i) {
    cin >> m1[i];
    --m1[i];
    vc[m1[i]].push_back(i);
  }
  int a, b;
  for (int i = 0; i < m; ++i) {
    for (int j = 1; j < vc[i].size(); ++j)
      vc1[i].push_back(vc[i][j] - vc[i][j - 1] - 1);
    a = 0;
    b = 0;
    for (int j = 0; j < vc1[i].size(); ++j) {
      b += vc1[i][j];
      while (b > k) b -= vc1[i][a++];
      res = max(res, j - a + 2);
    }
  }
  cout << res << endl;
  return 0;
}
