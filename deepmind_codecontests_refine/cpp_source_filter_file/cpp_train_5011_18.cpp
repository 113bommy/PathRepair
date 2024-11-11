#include <bits/stdc++.h>
using namespace std;
int n, dp[200010][3] = {}, from[200010][3];
string s;
char enc(int i) { return i == 0 ? 'R' : i == 1 ? 'G' : 'B'; }
int dec(char c) { return c == 'R' ? 0 : c == 'G' ? 1 : 2; }
int main() {
  memset(from, -1, sizeof(from));
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    int c = dec(s[i]);
    for (int j = 0; j < 3; j++) {
      int d = 1e4, f = -1;
      for (int k = 0; k < 3; k++) {
        if (k == j) continue;
        if (dp[i][k] + (c != j) < d) {
          d = dp[i][k] + (c != j);
          f = k;
        }
      }
      from[i + 1][j] = f;
      dp[i + 1][j] = d;
    }
  }
  int mc = 1e9, st = -1;
  char ans[200010] = {};
  for (int i = 0; i < 3; i++) {
    if (dp[n][i] < mc) {
      mc = dp[n][i];
      st = i;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = enc(st);
    st = from[i + 1][st];
  }
  cout << mc << endl << ans << endl;
}
