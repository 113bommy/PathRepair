#include <bits/stdc++.h>
using namespace std;
int sum(vector<vector<int>> arr) {
  int ret = 0;
  for (int i = 0; i < 101; ++i) {
    for (int j = 0; j < 101; ++j) {
      ret += arr[i][j];
    }
  }
  return ret;
}
int main() {
  int n;
  cin >> n;
  vector<vector<int>> arr(101, vector<int>(101, 0));
  for (int i = 0; i < n; ++i) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int x = x1; x <= x2; ++x) {
      for (int y = y1; y <= y2; ++y) {
        arr[x][y]++;
      }
    }
  }
  cout << sum(arr);
}
