#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, s = 0;
  int c[55], d[55][55];
  int temp[2501][2] = {0}, v = 1;
  int res[2501][4];
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < c[i]; ++j) {
      cin >> d[i][j];
      temp[v][0] = i + 1, temp[v][1] = j + 1;
      v++;
      s++;
    }
  }
  int num = 1;
  int count = 0;
  while (1) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < c[i]; ++j) {
        if (d[i][j] == num && num != s) {
          swap(d[i][j], d[temp[num][0] - 1][temp[num][1] - 1]);
          if (!(i == temp[num][0] - 1 && j == temp[num][1] - 1)) {
            res[count][0] = i + 1;
            res[count][1] = j + 1;
            res[count][2] = temp[num][0];
            res[count][3] = temp[num][1];
            count++;
          }
          num++;
        }
      }
    }
    if (num == s) break;
  }
  cout << count << endl;
  for (int i = 0; i < count; ++i) {
    cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << " "
         << res[i][3] << endl;
  }
  return 0;
}
