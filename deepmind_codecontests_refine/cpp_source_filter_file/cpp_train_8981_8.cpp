#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void debug(vector<T> li) {
  for (auto v : li) {
    cout << v << " ";
  }
  cout << "\n";
}
template <typename T>
inline void debug(vector<vector<T>> li) {
  for (auto v1 : li) {
    for (auto v2 : v1) {
      cout << v2 << " ";
    }
    cout << "\n";
  }
}
const int mxN = 10;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
int vec[mxN][mxN];
void solve() {
  int n, m;
  cin >> n >> m;
  int sum = 0, count = 0, mi = 1e9;
  for (int i = 0; i < n; i += 1)
    for (int j = 0; j < m; j += 1)
      cin >> vec[i][j], sum += abs(vec[i][j]), count += vec[i][j] <= 0,
          mi = min(mi, abs(vec[i][j]));
  if (count & 1) {
    sum -= mi;
  }
  cout << sum << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}
