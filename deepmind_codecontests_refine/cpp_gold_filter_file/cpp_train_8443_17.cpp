#include <bits/stdc++.h>
using namespace std;
int cnt[200];
int main() {
  int n, i, j, k, low = 1000000, ans;
  cin >> n;
  vector<vector<int>> vec(n, vector<int>(4));
  for (i = 0; i < n; i++) {
    for (j = 0; j < 4; j++) {
      cin >> vec[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (k = 0; k < n; k++) {
      if (vec[i][0] > vec[k][0] && vec[i][1] > vec[k][1] &&
          vec[i][2] > vec[k][2]) {
        vec[k][3] = -1;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (vec[i][3] < low && vec[i][3] != -1) {
      low = vec[i][3];
      ans = i + 1;
    }
  }
  cout << ans << endl;
}
