#include <bits/stdc++.h>
using namespace std;
int lo[5000][2];
int rec[55][4];
int tb[55][55];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> tb[i][0];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= tb[i][0]; j++) {
      cin >> tb[i][j];
      lo[tb[i][j]][0] = i;
      lo[tb[i][j]][1] = j;
    }
  }
  int cnt = 0;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= tb[i][0]; j++) {
      cnt++;
      if (cnt != tb[i][j]) {
        rec[res][0] = i;
        rec[res][1] = j;
        rec[res][2] = lo[cnt][0];
        rec[res][3] = lo[cnt][1];
        lo[tb[i][j]][0] = lo[cnt][0];
        lo[tb[i][j]][1] = lo[cnt][1];
        lo[cnt][0] = i;
        lo[cnt][1] = j;
        int t = tb[i][j];
        tb[i][j] = tb[rec[res][2]][rec[res][3]];
        tb[rec[res][2]][rec[res][3]] = t;
        res++;
      }
    }
  }
  cout << res << endl;
  for (int i = 0; i < res; i++) {
    cout << rec[i][0] << " " << rec[i][1] << " " << rec[i][2] << " "
         << rec[i][3] << endl;
  }
  return 0;
}
