#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[200005];
int acc[200005];
int main() {
  int n, w, k;
  cin >> n >> w >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i].first, acc[i] = acc[i - 1] + a[i].first;
  for (int i = 0; i < n; i++) cin >> a[i].second;
  int ans = 0;
  int lo = 0, hi = 0;
  multiset<int> St, St2;
  int tmp = 0;
  while (hi <= n) {
    if (lo > hi) {
      hi++;
      continue;
    }
    if (tmp > k) {
      if (St.find(a[lo].second) != St.end()) {
        tmp -= (a[lo].second / 2 + a[lo].second % 2);
        St.erase(St.find(a[lo].second));
        if (St2.size()) {
          int y = (*St2.rbegin());
          St2.erase(St2.find(y));
          tmp -= y;
          tmp += (y / 2 + y % 2);
          St.insert(y);
        }
      } else {
        tmp -= a[lo].second;
        St2.erase(St2.find(a[lo].second));
      }
      lo++;
    } else {
      if (hi == n) break;
      if (St.size() < w) {
        tmp += a[hi].second / 2 + a[hi].second % 2;
        St.insert(a[hi].second);
      } else {
        if (a[hi].second > (*St.rbegin())) {
          int x = (*St.rbegin());
          tmp -= (x / 2 + x % 2);
          tmp += x;
          tmp += a[hi].second / 2 + a[lo].second % 2;
          St.erase(St.find(x));
          St.insert(a[hi].second);
          St2.insert(x);
        } else {
          tmp += a[hi].second;
          St2.insert(a[hi].second);
        }
      }
      hi++;
    }
    if (tmp <= k) ans = max(ans, acc[hi - 1] - acc[lo - 1]);
  }
  cout << ans << '\n';
  return 0;
}
