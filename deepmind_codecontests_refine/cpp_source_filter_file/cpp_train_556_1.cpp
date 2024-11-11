#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<vector<int>> v(3);
  for (int i = 0; i < 3; i++) v[i].resize(3);
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> v[i][j];
      sum += v[i][j];
    }
  }
  sum = sum / 2;
  v[0][0] = sum - v[1][0] - v[2][0];
  v[1][1] = sum - v[0][1] - v[2][0];
  v[2][2] = sum - v[0][2] - v[1][0];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}
