#include <bits/stdc++.h>
using namespace std;
string M[1100];
int C[1100], R[1010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m, n;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) cin >> M[i];
    int first = -1, second = -1;
    memset(C, 0, sizeof(C));
    memset(R, 0, sizeof(R));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (M[i][j] == '*') {
          C[i]++;
          R[j]++;
        }
      }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        int u = C[i] + R[j];
        if (M[i][j] == '*') u--;
        if (u > C[first] + R[second]) {
          first = i;
          second = j;
        }
      }
    for (int i = 0; i < m; i++) M[first][i] = '.';
    for (int i = 0; i < n; i++) M[i][second] = '.';
    bool sw = 1;
    for (int i = 0; i < n and sw; i++)
      for (int j = 0; j < m and sw; j++) {
        if (M[i][j] == '*') {
          sw = 0;
        }
      }
    if (sw)
      cout << "YES\n" << first + 1 << " " << second + 1 << "\n";
    else
      cout << "NO\n";
  }
  return 0;
}
