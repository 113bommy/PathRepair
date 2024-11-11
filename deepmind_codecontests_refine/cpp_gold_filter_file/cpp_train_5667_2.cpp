#include <bits/stdc++.h>
using namespace std;
double dp[2010][2010];
const double EPS = 1e-9;
int n, m;
double rec(int r, int c) {
  if (r == 0 && c == 0) return 0;
  double &res = dp[r][c];
  if (res >= 0) return res;
  double nsq = n * n;
  double p0 = (n - r) * (n - c) / nsq;
  double p1 = r * (n - c) / nsq;
  double p2 = (n - r) * c / nsq;
  double p3 = r * c / nsq;
  res = 1;
  if (p1 >= EPS) res += p1 * rec(r - 1, c);
  if (p2 >= EPS) res += p2 * rec(r, c - 1);
  if (p3 >= EPS) res += p3 * rec(r - 1, c - 1);
  res /= (1 - p0);
  return res;
}
int main() {
  cin >> n >> m;
  set<int> R, C;
  while (m--) {
    int r, c;
    cin >> r >> c;
    R.insert(r), C.insert(c);
  }
  memset(dp, -1, sizeof(dp));
  cout.setf(ios::fixed);
  cout.precision(9);
  cout << rec(n - R.size(), n - C.size()) << endl;
  return 0;
}
