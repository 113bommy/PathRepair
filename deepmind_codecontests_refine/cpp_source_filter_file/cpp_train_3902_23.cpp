#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  vector<vector<char> > arr;
  cin >> n >> m;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i % 2 == 0)
        arr[i].push_back('#');
      else
        arr[i].push_back('.');
    }
  }
  for (int i = 0; i < n; i++) {
    int half = i / 2;
    if (half % 2 == 0)
      arr[i][m - 1] = '#';
    else
      arr[i][0] = '#';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << arr[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
