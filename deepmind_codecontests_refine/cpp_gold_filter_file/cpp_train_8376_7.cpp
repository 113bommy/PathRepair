#include <bits/stdc++.h>
using namespace std;
const int mxsz = 1e3 + 1, mxsum = 301;
vector<vector<vector<int>>> mem(2, vector<vector<int>>(mxsz,
                                                       vector<int>(mxsum, -1)));
vector<vector<vector<int>>> came(2, vector<vector<int>>(mxsz, vector<int>(mxsum,
                                                                          -1)));
int dp(int allowed, int i, int x) {
  if (i == 0) return (x == 0);
  if (mem[allowed][i][x] != -1) return mem[allowed][i][x];
  bool ans = 0;
  int sm = 0;
  for (int di = allowed; di <= 9; ++di) {
    if (di > x) break;
    bool res = dp(0, i - 1, x - di);
    if (res) sm = di;
    ans |= res;
    if (res) break;
  }
  mem[allowed][i][x] = ans, came[allowed][i][x] = sm;
  return ans;
}
string track(int i, int x, int allowed) {
  string res;
  while (i != 0) {
    res += (came[allowed][i][x] + '0');
    x -= came[allowed][i][x];
    allowed = 0;
    --i;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < mxsz; i++) {
    for (int j = 0; j < mxsum; ++j) {
      dp(0, i, j);
      dp(1, i, j);
    }
  }
  mem[0][0][0] = 1;
  mem[1][0][0] = 1;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  string last = "0";
  for (int i = 0; i < n; i++) {
    string sm;
    for (int sz = last.size() + 1; sz < mxsz; sz++) {
      if (mem[1][sz][a[i]] == 1) {
        sm = track(sz, a[i], 1);
        break;
      }
    }
    string res;
    for (int j = 0; j < last.size(); j++) {
      if (a[i] < 0) break;
      for (int di = last[j] - '0' + 1; di <= 9; ++di) {
        if (a[i] - di < 0) break;
        res += (di + '0');
        if (mem[0][last.size() - 1 - j][a[i] - di] == 1) {
          sm = res + track(last.size() - 1 - j, a[i] - di, 0);
          res.pop_back();
          break;
        }
        res.pop_back();
      }
      res += last[j];
      a[i] -= (last[j] - '0');
    }
    cout << sm << '\n';
    last = sm;
  }
  return 0;
}
