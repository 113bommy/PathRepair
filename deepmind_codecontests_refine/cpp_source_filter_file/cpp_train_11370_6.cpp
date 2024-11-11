#include <bits/stdc++.h>
using namespace std;
void fst() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
const int MOD = 1e9 + 7;
void print(int x) { cout << x << "\n"; }
int solve(int r, int c, vector<string> &arr) {
  vector<int> row(r), col(c);
  int total = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (arr[i][j] == 'A') {
        row[i]++;
        col[j]++;
        total++;
      }
    }
  }
  if (!total) {
    return -1;
  }
  if (total == r * c) return 0;
  if (col[0] == c || row[r - 1] == c || col[0] == r || col[c - 1] == r)
    return 1;
  if (arr[0][0] == 'A' || arr[0][c - 1] == 'A' || arr[r - 1][c - 1] == 'A' ||
      arr[r - 1][0] == 'A')
    return 2;
  int r_max = *max_element(row.begin(), row.end()),
      c_max = *max_element(col.begin(), col.end());
  if (r_max == c || c_max == r) return 2;
  if (row[0] || row[c - 1] || col[0] || col[r - 1]) return 3;
  return 4;
}
int main() {
  fst();
  int tc;
  cin >> tc;
  while (tc--) {
    int r, c;
    cin >> r >> c;
    vector<string> arr(r);
    for (int i = 0; i < r; i++) {
      cin >> arr[i];
    }
    int res = solve(r, c, arr);
    ((res != -1) ? cout << res : cout << "MORTAL") << "\n";
  }
}
