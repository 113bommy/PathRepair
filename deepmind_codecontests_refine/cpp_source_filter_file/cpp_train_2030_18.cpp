#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
vector<int> arr;
int m;
int solve(int idx, int mod) {
  if (idx == (int)arr.size())
    return (mod == 0);
  else if (dp[idx][mod] != -1)
    return dp[idx][mod];
  int ret = solve(idx + 1, mod);
  if (ret) return (dp[idx][mod] = ret);
  ret = solve(idx + 1, (mod + arr[idx]) % m);
  return (dp[idx][mod] = ret);
}
int main() {
  ios_base::sync_with_stdio(false);
  for (int i = (int)(0); i < (int)(1010); i++)
    for (int j = (int)(0); j < (int)(1010); j++) dp[i][j] = -1;
  int n;
  cin >> n >> m;
  arr.resize(n);
  for (int i = (int)(0); i < (int)(n); i++) cin >> arr[i];
  if (n > m)
    cout << "YES" << endl;
  else {
    int yes = 0;
    for (int i = (int)(0); i < (int)(n); i++) yes |= solve(i, arr[i] % m);
    if (yes)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
