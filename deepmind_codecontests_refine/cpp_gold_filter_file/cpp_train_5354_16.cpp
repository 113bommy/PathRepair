#include <bits/stdc++.h>
using namespace std;
const int N = 2222;
long double dp[N][N];
int n;
long double go(int r, int c) {
  if (r == 0 && c == 0) return 0.0;
  long double &ret = dp[r][c];
  if (ret < 0) {
    ret = 0;
    if (r == 0) {
      ret += go(r, c - 1) + n / (long double)c;
    } else if (c == 0) {
      ret += go(r - 1, c) + n / (long double)r;
    } else {
      ret += (go(r - 1, c - 1)) * (long double)r * c;
      ret += (go(r - 1, c)) * (long double)r * (n - c);
      ret += (go(r, c - 1)) * (long double)(n - r) * c;
      ret += n * n;
      ret /= (long double)((r + c) * n - r * c);
    }
  }
  return ret;
}
int main() {
  int m;
  cin >> n >> m;
  set<int> row, col;
  for (int i = 0; i < (m); i++) {
    int r, c;
    cin >> r >> c;
    row.insert(r);
    col.insert(c);
  }
  for (int i = 0; i < (n + 1); i++)
    for (int j = 0; j < (n + 1); j++) dp[i][j] = -1.0;
  cout << setprecision(10) << fixed
       << go(n - (int)row.size(), n - (int)col.size()) << endl;
  return 0;
}
