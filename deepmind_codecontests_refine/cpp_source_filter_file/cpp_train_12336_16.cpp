#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int memo[N][N];
string s, t;
int solve(int i, int j) {
  if (j == t.size() && i == s.size()) return 0;
  int& ret = memo[i][j];
  if (ret != -1) return ret;
  if (i == s.size())
    ret = 1 + solve(i, j + 1);
  else if (j == t.size())
    ret = 1 + solve(i + 1, j);
  else if (s[i] == t[j])
    ret = solve(i + 1, j + 1);
  else
    ret = 1 + min(solve(i + 1, j), min(solve(i, j + 1), solve(i + 1, j + 1)));
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T = 1;
  while (T--) {
    memset(memo, -1, sizeof(memo));
    cin >> s >> t;
    cout << solve(0, 0) << "\n";
    int i = 0, j = 0;
    int p = 1;
    while (i < s.size() || j < t.size()) {
      if (i == s.size()) {
        cout << "INSERT " << p++ << " " << t[j] << "\n";
        j++;
      } else if (j == t.size()) {
        cout << "DELETE " << p++ << "\n";
        i++;
      } else if (s[i] == t[j]) {
        i++;
        j++;
        p++;
      } else {
        if (memo[i + 1][j + 1] <= memo[i][j + 1] &&
            memo[i + 1][j + 1] <= memo[i + 1][j]) {
          cout << "REPLACE " << p++ << " " << t[j] << "\n";
          i++, j++;
        } else if (memo[i + 1][j] <= memo[i + 1][j + 1] &&
                   memo[i + 1][j] <= memo[i][j + 1]) {
          cout << "DELETE " << p << "\n";
          i++;
        } else {
          cout << "INSERT " << p++ << " " << t[j] << "\n";
          j++;
        }
      }
    }
  }
  return 0;
}
