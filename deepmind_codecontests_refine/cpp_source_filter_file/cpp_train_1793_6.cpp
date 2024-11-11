#include <bits/stdc++.h>
using namespace std;
int A[300010][9];
pair<int, int> mx[257];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> A[i][j];
  }
  mx[0] = make_pair(2 * 1e9, 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << m); j++) {
      pair<int, int> maxi = make_pair(2 * 1e9, -1);
      for (int k = 0; k < m; k++) {
        if (j & (1 << k)) {
          maxi = min(maxi, make_pair(A[i][k], i));
        }
      }
      mx[j] = max(mx[j], maxi);
    }
  }
  pair<int, pair<int, int> > res = make_pair(-1, make_pair(-1, -1));
  for (int i = 0; i < (1 << m); i++) {
    res = max(
        res, make_pair(min(mx[i].first, mx[i ^ ((1 << m) - 1)].first),
                       make_pair(mx[i].second, mx[i ^ ((1 << m) - 1)].second)));
  }
  cout << res.second.first + 1 << " " << res.second.second + 1 << '\n';
}
