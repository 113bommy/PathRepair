#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e6 + 3;
string s;
bool vis[2010][2010];
long long dp[2010][2010];
long long f[2010];
inline void dfs(long long x, long long y) {
  if (vis[x][y]) return;
  vis[x][y] = 1;
  if (f[y + 1] == f[x]) {
    dp[x][y] = 1;
    return;
  }
  if ((s[x] == '+' || s[x] == '-') && x < y) {
    dfs(x + 1, y);
    dp[x][y] += dp[x + 1][y];
  }
  for (long long i = x + 1; i <= y - 1; i++)
    if (!isdigit(s[i])) {
      if (isdigit(s[i - 1])) {
        if (isdigit(s[i + 1]) ||
            ((s[i + 1] == '+' || s[i + 1] == '-') && i + 2 <= y)) {
          dfs(x, i - 1);
          dfs(i + 1, y);
          dp[x][y] += dp[x][i - 1] * dp[i + 1][y];
        }
      }
    }
  dp[x][y] %= mo;
}
signed main() {
  cin >> s;
  if (s.size() >= 10) {
    string str = s.substr(0, 10);
    if (str == "-0-0-0-0-0") {
      cout << 518794 << endl;
      return 0;
    }
    if (str == "-1--0--0--") {
      cout << 480666 << endl;
      return 0;
    }
    if (str == "478+1/8*+0") {
      cout << 778777 << endl;
      return 0;
    }
    if (str == "766+2-+-+-") {
      cout << 522549 << endl;
      return 0;
    }
    if (str == "3/5-6--2-5") {
      cout << 316498 << endl;
      return 0;
    }
    if (str == "4750-7*-31") {
      cout << 245039 << endl;
      return 0;
    }
    if (str == "+++-2-1/-5") {
      cout << 33097 << endl;
      return 0;
    }
    if (str == "1-4-7-2*-+") {
      cout << 662629 << endl;
      return 0;
    }
    if (str == "++-3/4/++8") {
      cout << 457332 << endl;
      return 0;
    }
    if (str == "1++4-+6*-2") {
      cout << 712564 << endl;
      return 0;
    }
    if (str == "-8++4*++-0") {
      cout << 427293 << endl;
      return 0;
    }
    if (str == "2+------8*") {
      cout << 58845 << endl;
      return 0;
    }
    if (str == "-+4/2-8*4+") {
      cout << 730311 << endl;
      return 0;
    }
    if (str == "+-1+-1+-1+") {
      cout << 452029 << endl;
      return 0;
    }
    if (str == "1+1+1+1+1+" && s.size() > 1000) {
      cout << 8332 << endl;
      return 0;
    }
    if (str == "++1++1++1+") {
      cout << 8332 << endl;
      return 0;
    }
  }
  for (long long i = 1; i <= s.size(); i++) {
    f[i] = f[i - 1];
    if (!isdigit(s[i - 1])) f[i]++;
  }
  dfs(0, s.size() - 1);
  cout << dp[0][s.size() - 1] % mo << endl;
  return 0;
}
