#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int a[N + 100], t[N + 100], vis[N + 100];
set<pair<int, int> > st1, st2;
int main() {
  int n, w, k;
  scanf("%d%d%d", &n, &w, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", t + i);
  }
  int cur = 0, l = 1, r = 1, cnt = 0, total = 0, ans = 0;
  while (r <= n) {
    while (cur <= k && r <= n) {
      if (cnt < w) {
        cnt++;
        vis[r] = 1;
        cur += (t[r] + 1) / 2;
        vis[r] = 1;
        st1.insert(make_pair(t[r], r));
      } else {
        auto it = *st1.begin();
        if (it.first < t[r]) {
          vis[it.second] = 2;
          vis[r] = 1;
          cur -= (it.first + 1) / 2;
          cur += it.first;
          cur += (t[r] + 1) / 2;
          st1.erase(it);
          st2.insert(it);
          st1.insert(make_pair(t[r], r));
        } else {
          st2.insert(make_pair(t[r], r));
          cur += t[r];
          vis[r] = 2;
        }
      }
      total += a[r];
      if (cur <= k) {
        ans = max(ans, total);
      }
      r++;
    }
    while (cur > k) {
      if (vis[l] == 1) {
        cnt--;
        st1.erase(make_pair(t[l], l));
        cur -= (t[l] + 1) / 2;
        if (!st2.empty()) {
          auto it = *st2.rbegin();
          vis[it.second] = 1;
          cur -= t[it.second];
          cur += (t[it.second] + 1) / 2;
          cnt++;
          st2.erase(it);
          st1.insert(it);
        }
      } else {
        st2.erase(make_pair(t[l], l));
        cur -= t[l];
      }
      total -= a[l];
      l++;
      if (cur <= k) {
        ans = max(ans, total);
      }
    }
  }
  printf("%d\n", ans);
}
