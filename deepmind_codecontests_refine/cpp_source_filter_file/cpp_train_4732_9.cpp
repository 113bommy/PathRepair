#include <bits/stdc++.h>
using namespace std;
const int N = 65;
int n, a[101], dp[101][1 << 11], masks[N];
int solve(int ind, int mask) {
  if (ind == n) return 0;
  int &ret = dp[ind][mask];
  if (ret != -1) return ret;
  ret = 1e9;
  for (int i = 1; i <= 60; i++) {
    if (masks[i] & mask) continue;
    ret = min(ret, solve(ind + 1, masks[i] | mask) + abs(i - a[ind]));
  }
  return ret;
}
void print(int ind, int mask) {
  if (ind == n) return;
  int &ret = dp[ind][mask];
  for (int i = 1; i <= 60; i++) {
    if (masks[i] & mask) continue;
    if (ret == solve(ind + 1, masks[i] | mask) + abs(i - a[ind])) {
      cout << i << " ";
      return print(ind + 1, masks[i] | mask);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int cnt = 0;
  for (int i = 2; i <= 60; i++) {
    if (masks[i]) continue;
    for (int j = i; j <= 60; j += i) masks[j] |= (1 << cnt);
    cnt++;
  }
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(dp, -1, sizeof dp);
  solve(0, 0);
  print(0, 0);
  return 0;
}
