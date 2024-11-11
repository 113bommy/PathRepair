#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > s(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> s[i][j];
  int answer = 0;
  for (int i = 1; i < n; i++) {
    int cur = 0;
    if (s[i][0] == 1) cur += 1;
    for (int j = 1; j < m; j++) {
      if (s[i][j] == 0 and cur == 1) answer += 1;
      if (s[i][j] == 1) cur = 1;
    }
    cur = 0;
    if (s[i][m - 1] == 1) cur += 1;
    for (int j = m - 2; j > -1; j--) {
      if (s[i][j] == 0 and cur == 1) answer += 1;
      if (s[i][j] == 1) cur = 1;
    }
  }
  for (int i = 1; i < m; i++) {
    int cur = 0;
    if (s[0][i] == 1) cur = 1;
    for (int j = 1; j < n; j++) {
      if (s[j][i] == 0 and cur == 1) answer += 1;
      if (s[j][i] == 1) cur = 1;
    }
    cur = 0;
    if (s[n - 1][i] == 1) cur = 1;
    for (int j = n - 2; j >= 0; j--) {
      if (s[j][i] == 0 and cur == 1) answer += 1;
      if (s[j][i] == 1) cur = 1;
    }
  }
  cout << answer << endl;
  return 0;
}
