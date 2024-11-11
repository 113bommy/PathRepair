#include <bits/stdc++.h>
using namespace std;
const long long MAX = 3e5 + 9;
long long n, m, x, y;
int a[1000 + 1];
int memo[1002][1002][3];
int solve(int col, int wid, int last) {
  if (col == m) {
    if (wid < x || wid > y) return 10000000;
    return 0;
  }
  int &ans = memo[col][wid][last];
  if (ans != -1) return ans;
  int dots = 1000000;
  if (col == 0 || (last == 0 && wid + 1 <= y) || (last == 1 && wid >= x))
    dots = n - a[col] + solve(col + 1, (last == 0) ? wid + 1 : 1, 0);
  int hashes = 1000000;
  if (col == 0 || (last == 1 && wid + 1 <= y) || (last == 0 && wid >= x))
    hashes = a[col] + solve(col + 1, (last == 1) ? wid + 1 : 1, 1);
  ans = min(dots, hashes);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      if (ch == '.') a[j]++;
    }
  }
  memset(memo, -1, sizeof(-1));
  cout << solve(0, 0, 2);
  return 0;
}
