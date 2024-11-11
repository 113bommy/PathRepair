#include <bits/stdc++.h>
using namespace std;
map<int, bool> mymap;
vector<pair<int, int> > coins;
int value[5005];
int main() {
  int i, j, x, y, z, n, m, k, q;
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) scanf("%d", &value[i]);
  for (i = n - 1; i >= 0; i--) {
    for (j = 1; j < k; j++) {
      x = j * value[i];
      if (mymap.find(x) == mymap.end()) {
        mymap[x] = true;
        coins.push_back(make_pair(x, j));
      }
    }
  }
  coins.push_back(make_pair(0, 0));
  sort(coins.begin(), coins.end());
  m = coins.size();
  scanf("%d", &q);
  while (q--) {
    int ans = 50;
    scanf("%d", &x);
    y = x / 2;
    for (i = 0; i < m && coins[i].first <= y; i++) {
      z = x - coins[i].first;
      int lo, mid, hi;
      lo = i;
      hi = m - 1;
      while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (coins[mid].first == z) {
          if (coins[i].second + coins[mid].second <= k)
            ans = min(ans, coins[i].second + coins[mid].second);
          break;
        } else if (coins[mid].first > z)
          hi = mid - 1;
        else
          lo = mid + 1;
      }
    }
    if (ans == 50) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}
