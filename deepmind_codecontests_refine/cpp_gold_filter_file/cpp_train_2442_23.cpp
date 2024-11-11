#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int pos[11][1111];
int gra[1111][1111];
int main() {
  int n, m;
  cin >> n >> m;
  int x;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> x;
      pos[i][x - 1] = j;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int flag = 1;
      for (int k = 0; k < m; k++) {
        flag &= (pos[k][i] < pos[k][j]);
      }
      if (flag == true)
        gra[i][j] = 1;
      else
        gra[i][j] = -INF;
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        gra[i][j] = max(gra[i][j], gra[i][k] + gra[k][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans = max(ans, gra[i][j]);
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
