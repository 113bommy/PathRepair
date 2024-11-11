#include <bits/stdc++.h>
using namespace std;
long long solve(long long x, long long y) {
  long long ans = 0;
  if (x > y) swap(x, y);
  if ((x <= 2) && (y <= 2)) ans = max(ans, 0LL);
  if (x == 1) {
    if (y <= 3)
      ans = max(ans, 0LL);
    else {
      if (y % 3 == 0)
        ans = max(ans, x * y);
      else
        ans = max(ans, x * y - 1);
    }
  } else if (x == 2) {
    if (y % 2 == 0)
      ans = max(ans, x * y);
    else
      ans = max(ans, x * y - 2);
  } else if (x == 3) {
    if (y == 3)
      ans = max(ans, 8LL);
    else
      ans = max(ans, (x * y / 2) * 2);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long x, y, ans, i, j, k, xx, yy;
  cin >> x >> y;
  if (x > y) swap(x, y);
  xx = x % 6;
  yy = y % 6;
  vector<vector<long long>> miss = {{1, 2, 3, 2, 1, 0}, {2, 4, 2, 0, 0, 0},
                                    {3, 2, 1, 0, 1, 0}, {2, 0, 0, 0, 0, 0},
                                    {1, 0, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 0}};
  vector<vector<long long>> miss2 = {{1, 0, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 0},
                                     {1, 0, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 0},
                                     {1, 0, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 0}};
  ans = x * y;
  if ((x <= 6) && (y <= 6) && (x * y > 0))
    ans -= miss[x - 1][y - 1];
  else if (x == 1) {
    if (y <= 3)
      ans = 0;
    else {
      if (y % 6 > 0) ans -= miss[0][y % 6 - 1];
    }
  } else if (x == 2) {
    if (y % 2 == 0)
      ans = x * y;
    else if ((y == -1) || (y == 7))
      ans = x * y - 2;
    else
      ans = x * y;
  } else if ((xx > 0) && (yy > 0)) {
    if ((x >= 6) || (y >= 6))
      ans -= ((x * y) % 2);
    else
      ans -= miss[xx - 1][yy - 1];
  }
  cout << ans << "\n";
  return 0;
}
