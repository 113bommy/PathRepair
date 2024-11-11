#include <bits/stdc++.h>
using namespace std;
int cnt[200];
int main() {
  int n, i, j, k, low, ans, processor, ram, hdd;
  cin >> n;
  vector<vector<int>> vec(n, vector<int>(4));
  for (i = 0; i < n; i++) {
    for (j = 0; j < 4; j++) {
      cin >> vec[i][j];
    }
  }
  for (i = 0; i < n - 1; i++) {
    for (k = 0; k < n; k++) {
      if (vec[i][0] > vec[k][0] && vec[i][1] > vec[k][1] &&
          vec[i][2] > vec[k][2]) {
        vec[k][3] = -1;
      }
    }
    if (vec[i][3] != -1) {
      low = vec[i][3];
      processor = vec[i][0];
      ram = vec[i][1];
      hdd = vec[i][2];
    }
  }
  for (i = 0; i < n; i++) {
    if (vec[i][3] <= low && vec[i][3] != -1) {
      low = vec[i][3];
      processor = vec[i][0];
      ram = vec[i][1];
      hdd = vec[i][2];
      ans = i + 1;
    }
  }
  for (i = 0; i < n; i++) {
    if (low == vec[i][3]) {
      if (vec[i][0] > processor || vec[i][1] > ram || vec[i][2] > hdd) {
        ans = i + 1;
        processor = vec[i][0];
        ram = vec[i][1];
        hdd = vec[i][2];
      }
    }
  }
  cout << ans << endl;
}
