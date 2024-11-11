#include <bits/stdc++.h>
using namespace std;
int n;
map<pair<pair<bool, int>, pair<int, int>>, int> dp;
int recurse(bool asc, int cx, int cy, int hm) {
  if (hm < 0 || cx > n) return 0;
  if (hm == 0) {
    if (asc && cx == n)
      return 1;
    else
      return 0;
  }
  pair<pair<bool, int>, pair<int, int>> index =
      make_pair(make_pair(asc, hm), make_pair(cx, cy));
  if (dp.count(index)) {
    return dp[index];
  } else {
    int ans;
    if (asc) {
      if (cy == 1) {
        ans = recurse(false, cx + 1, 2, hm) + recurse(false, cx + 1, 3, hm) +
              recurse(false, cx + 1, 4, hm) + recurse(false, cx + 2, 3, hm) +
              2 * recurse(false, cx + 2, 4, hm) + recurse(false, cx + 3, 4, hm);
      } else if (cy == 2) {
        ans = recurse(false, cx + 1, 3, hm) + recurse(false, cx + 1, 4, hm) +
              recurse(false, cx + 2, 4, hm);
      } else if (cy == 3) {
        ans = recurse(false, cx + 1, 4, hm);
      } else
        ans = 0;
    } else {
      if (cy == 4) {
        ans = recurse(true, cx + 1, 3, hm - 1) +
              recurse(true, cx + 1, 2, hm - 1) +
              recurse(true, cx + 1, 1, hm - 1) +
              recurse(true, cx + 2, 2, hm - 1) +
              2 * recurse(true, cx + 2, 1, hm - 1) +
              recurse(true, cx + 3, 1, hm - 1);
      } else if (cy == 3) {
        ans = recurse(true, cx + 1, 2, hm - 1) +
              recurse(true, cx + 1, 1, hm - 1) +
              recurse(true, cx + 2, 1, hm - 1);
      } else if (cy == 2) {
        ans = recurse(true, cx + 3, 1, hm - 1);
      } else
        ans = 0;
    }
    dp[index] = ans;
    return ans;
  }
}
int main() {
  int t;
  cin >> n >> t;
  cout << recurse(true, 1, 1, t) + recurse(true, 1, 2, t) +
              recurse(true, 1, 3, t)
       << endl;
}
