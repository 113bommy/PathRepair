#include <bits/stdc++.h>
using namespace std;
int n, r1, r2, r3, d, a[1000100];
long long Dp[1000100][2];
long long Solve(int i = 0, int j = 0) {
  if (i == n) return 0;
  long long &Res = Dp[i][j];
  if (Res != -1) return Res;
  Res = a[i] * r1 + r3 + d * (i != n - 1) - d * (i == n - 1 && j == 1);
  Res += Solve(i + 1, 0);
  if (j == 0) {
    long long R1 = Solve(i + 1, 1) + min(r2 + r1, a[i] * r1 + 2 * r1) + 2 * d +
                   d * (i != n - 1);
    Res = min(Res, R1);
  } else {
    long long R1 =
        Solve(i + 1, 0) + min(r2 + r1, a[i] * r1 + 2 * r1) + d * (i != n - 1);
    Res = min(Res, R1);
  }
  return Res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> r1 >> r2 >> r3 >> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(Dp, -1, sizeof Dp);
  cout << Solve() << endl;
  return 0;
}
