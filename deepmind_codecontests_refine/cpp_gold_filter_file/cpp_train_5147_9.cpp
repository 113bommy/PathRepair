#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int w[N][N];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j <= i + k; ++j) {
      w[i][j % n] = 1;
      w[j % n][i] = 0;
    }
  }
  bool ok = true;
  vector<pair<int, int> > ans;
  for (int i = (0); i < (int)(n); ++i) {
    if (w[i][i]) ok = false;
    int cnt = 0;
    for (int j = (0); j < (int)(n); ++j) {
      if (w[i][j]) {
        ans.push_back(make_pair(i, j));
        ++cnt;
      }
    }
    if (cnt != k) ok = false;
  }
  if (!ok)
    cout << -1 << endl;
  else {
    cout << ans.size() << endl;
    for (auto &p : ans) {
      printf("%d %d\n", p.first + 1, p.second + 1);
    }
  }
  return 0;
}
