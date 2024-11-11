#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int> > arr;
void swap_columns(int l, int r) {
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    swap(arr[i][l], arr[i][r]);
  }
}
int valid() {
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    int misplaced = 0;
    for (__typeof(m) j = (0) - ((0) > (m)); j != (m) - ((0) > (m));
         j += 1 - 2 * ((0) > (m))) {
      if (arr[i][j] != (j + 1)) misplaced++;
    }
    if (misplaced > 2) return 0;
  }
  return 1;
}
int main() {
  srand(chrono::steady_clock::now().time_since_epoch().count());
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  arr.resize(n, vector<int>(m));
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n)))
    for (__typeof(m) j = (0) - ((0) > (m)); j != (m) - ((0) > (m));
         j += 1 - 2 * ((0) > (m)))
      cin >> arr[i][j];
  bool done = false;
  if (valid()) {
    cout << "YES";
    return 0;
  }
  for (__typeof(m) i = (0) - ((0) > (m)); i != (m) - ((0) > (m));
       i += 1 - 2 * ((0) > (m))) {
    for (int j = i + 1; j < m; j++) {
      swap_columns(i, j);
      if (valid()) {
        done = true;
        break;
      }
      swap_columns(i, j);
    }
    if (done) break;
  }
  if (done)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
