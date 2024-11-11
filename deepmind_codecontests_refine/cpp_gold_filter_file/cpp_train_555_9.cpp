#include <bits/stdc++.h>
using namespace std;
const int OO = 1e9 + 7;
const int MOD = 1e9 + 7;
const int N = 100 + 7;
bool b[N][N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> m;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= i - 1; j++) {
      int cnt = 0;
      for (int k = 1; k <= 100; k++) {
        if (b[k][i] && b[k][j]) cnt++;
      }
      if (cnt > m) continue;
      b[i][j] = 1;
      b[j][i] = 1;
      m -= cnt;
      if (m == 0) break;
    }
    if (m == 0) break;
  }
  cout << 100 << endl;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) cout << b[i][j];
    cout << endl;
  }
  return 0;
}
