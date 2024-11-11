#include <bits/stdc++.h>
using namespace std;
int q[10000][5];
int t[10000];
int m;
int main() {
  int n;
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> q[i][0] >> q[i][1] >> q[i][2] >> q[i][3];
  for (int i = 1; i <= n; i++) {
    t[i] = 1000000;
    int tot = 0;
    for (int j = 0; j < m; j++) {
      if (q[j][0] == 1) {
        if (q[j][1] <= i && q[j][2] >= i) tot += q[j][3];
      } else {
        if (q[j][1] <= i && q[j][2] >= i) t[i] = min(q[j][3] - tot, t[i]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    long long tot = 0;
    for (int j = 0; j < m; j++) {
      if (q[j][0] == 1) {
        if (q[j][1] <= i && q[j][2] >= i) tot += q[j][3];
      } else {
        if (q[j][1] <= i && q[j][2] >= i)
          if (t[i] + tot == q[j][3]) q[j][4] = 1;
      }
    }
  }
  int u = 1;
  for (int i = 0; i < m; i++)
    if (q[i][0] != 1 && q[i][4] == 0) u = 0;
  if (u) {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) cout << t[i] << " ";
    cout << endl;
  } else
    cout << "NO" << endl;
}
