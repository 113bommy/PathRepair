#include <bits/stdc++.h>
using namespace std;
long long arr[105][105];
void solve() {
  arr[1][1] = 1;
  arr[1][0] = 1;
  for (int i = 2; i <= 100; i++) {
    arr[i][0] = 1;
    for (int j = 1; j <= i; j++) arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  long long n, r, k;
  cin >> n >> r >> k;
  long long ans = 0;
  for (int i = 4; i < k; i++) {
    ans = ans + (arr[n][i] * arr[r][k - i]);
  }
  cout << ans;
  return 0;
}
