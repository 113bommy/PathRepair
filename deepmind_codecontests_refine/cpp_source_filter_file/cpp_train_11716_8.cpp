#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const double INF = 1 << 30;
int n;
double dA[MAXN], dB[MAXN], dTacho[MAXN], memo[MAXN][2][2];
long long int x[MAXN], y[MAXN];
double dist(long long int x, long long int y, long long int a,
            long long int b) {
  return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}
double dp(int i, bool leftA, bool leftB) {
  if (i == n) {
    if (!leftA || !leftB)
      return 0;
    else
      return INF;
  }
  double &res = memo[i][leftA][leftB];
  if (res != -1) return res;
  res = INF;
  if (leftA) res = min(res, dp(i + 1, false, leftB) + dA[i] + dTacho[i]);
  if (leftB) res = min(res, dp(i + 1, leftA, false) + dB[i] + dTacho[i]);
  res = min(res, dp(i + 1, leftA, leftB) + dTacho[i] * 2);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fill(memo[0][0], memo[MAXN][0], -1);
  long long int ax, ay, bx, by, tx, ty;
  cin >> ax >> ay >> bx >> by >> tx >> ty;
  cin >> n;
  for (int i = 0; i < int(n); i++) {
    cin >> x[i] >> y[i];
    dA[i] = dist(ax, ay, x[i], y[i]);
    dB[i] = dist(bx, by, x[i], y[i]);
    dTacho[i] = dist(tx, ty, x[i], y[i]);
  }
  cout << fixed << setprecision(12) << dp(0, true, true) << '\n';
  return 0;
}
