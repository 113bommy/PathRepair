#include <bits/stdc++.h>
using namespace std;
int val[4][4];
long long dp[40][4][4];
int cal(int n, int l, int r) {
  if (!n) return 0;
  if (dp[n][l][r]) return dp[n][l][r];
  int mid = 6 - l - r;
  long long t1 = cal(n - 1, l, mid) + val[l][r] + cal(n - 1, mid, r);
  long long t2 = cal(n - 1, l, r) + val[l][mid] + cal(n - 1, r, l) +
                 val[mid][r] + cal(n - 1, l, r);
  return dp[n][l][r] = min(t1, t2);
}
int main() {
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) cin >> val[i][j];
  int n;
  cin >> n;
  cout << cal(n, 1, 3) << endl;
  return 0;
}
