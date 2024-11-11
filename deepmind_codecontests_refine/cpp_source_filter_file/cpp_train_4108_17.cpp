#include <bits/stdc++.h>
using namespace std;
int n;
int a[(100002)];
long long dp[(100002)][2];
long long sol(int i, bool t) {
  if (i == ((100002) - 1)) return 0;
  long long &tt = dp[i][t];
  if (tt != -1) return tt;
  long long c1, c2 = 0;
  c1 = sol(i + 1, 0);
  if (t == 0) c2 = a[i] + sol(i + 1, 1);
  return tt = max(c1, c2);
}
int main() {
  memset(a, 0, sizeof(a));
  memset(dp, -1, sizeof(dp));
  cin >> n;
  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    a[num]++;
  }
  for (int i = 1; i < (100002); i++) a[i] *= i;
  cout << sol(1, 0);
  return 0;
}
