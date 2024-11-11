#include <bits/stdc++.h>
using namespace std;
const int maxn = 2100;
long long val[maxn], N, memo[maxn][maxn], h;
long long solve(int x, int pre) {
  if (pre < 0) return 0;
  if (x == N) return pre == 0;
  long long ret = 0;
  if (memo[x][pre] != -1) return memo[x][pre];
  if (pre + val[x] > h || h - pre - val[x] - 1 >= 1)
    ret = 0;
  else if (pre + val[x] == h) {
    ret = solve(x + 1, pre);
    if (pre >= 1)
      ret =
          (ret + (pre * 1LL * solve(x + 1, pre - 1)) % 1000000007) % 1000000007;
  } else if (h - pre - val[x] - 1 == 0) {
    ret = (solve(x + 1, pre) + solve(x + 1, pre + 1)) % 1000000007;
    if (pre >= 1) ret = (ret + solve(x + 1, pre) * 1LL * pre) % 1000000007;
  }
  return memo[x][pre] = ret;
}
int main() {
  memset(memo, -1, sizeof memo);
  cin >> N >> h;
  for (int i = 0; i < N; i++) cin >> val[i];
  cout << solve(0, 0) << endl;
  return 0;
}
