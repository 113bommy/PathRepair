#include <bits/stdc++.h>
using namespace std;
string s;
int n, N;
int dp[111][55][2];
int f(int pos, int changes, int dir) {
  if (pos == n) {
    if (changes == N) return 0;
    if (changes > N) return -987654321;
    if (changes < N)
      if ((N - changes) % 2 == 0) return 0;
    return -987654321;
  }
  int &ans = dp[pos][changes][dir];
  if (ans != -1) return ans;
  ans = -987654321;
  if (s[pos] == 'F') {
    ans = max(ans, f(pos + 1, changes, dir) + (dir ? 1 : -1));
    ans = max(ans, f(pos + 1, changes + 1, dir ? 0 : 1));
  } else {
    ans = max(ans, f(pos + 1, changes, dir ? 0 : 1));
    ans = max(ans, f(pos + 1, changes + 1, dir) + (dir ? 1 : -1));
  }
  return ans;
}
int main() {
  cin >> s >> N;
  n = (int)s.size();
  memset(dp, -1, sizeof(dp));
  int ans = f(0, 0, 1);
  reverse(s.begin(), s.end());
  memset(dp, -1, sizeof(dp));
  int ans2 = f(0, 0, 1);
  cout << max(ans, ans2) << endl;
  return 0;
}
