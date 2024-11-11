#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<vector<bool>> used;
vector<vector<char>> a;
void f(int i, int j) {
  if (a[i][j] == '.') {
    return;
  }
  int left = 0;
  int right = 0;
  while (i - right >= 0 && j + right < m && a[i - right][j + right] == '*') {
    right += 1;
  }
  while (j - left >= 0 && i - left >= 0 && a[i - left][j - left] == '*') {
    left += 1;
  }
  if (right - 1 >= k && left - 1 >= k) {
    int mi = min(right, left);
    for (int t = 0; t < mi; t++) {
      used[i - t][j + t] = true;
      used[i - t][j - t] = true;
    }
  }
}
void solution() {
  cin >> n >> m >> k;
  a.assign(n, vector<char>(m));
  for (auto &line : a) {
    for (char &x : line) {
      cin >> x;
    }
  }
  used.assign(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      f(i, j);
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '*' && !used[i][j]) {
        ok = false;
      }
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
}
int32_t main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solution();
  }
  return 0;
}
