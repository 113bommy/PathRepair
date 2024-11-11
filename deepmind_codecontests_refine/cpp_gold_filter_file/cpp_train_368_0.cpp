#include <bits/stdc++.h>
using namespace std;
int n, w, k;
int t[200010], a[200010];
int partly(int x) { return (x % 2 ? x / 2 + 1 : x / 2); }
void solve() {
  scanf("%d %d %d", &n, &w, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t[i]);
  }
  int i = 1, j = 1;
  long long ans = 0, cans = 0, time = 0;
  set<pair<int, int>> S, oS;
  auto insert = [&](int i) {
    time += partly(t[i]);
    cans += a[i];
    S.insert({t[i], i});
    if (S.size() > w) {
      int er = S.begin()->second;
      time -= partly(t[er]);
      time += t[er];
      S.erase({t[er], er});
      oS.insert({t[er], er});
    }
  };
  auto erase = [&](int i) {
    cans -= a[i];
    if (S.find({t[i], i}) != S.end()) {
      time -= partly(t[i]);
      S.erase({t[i], i});
      if (oS.size() > 0) {
        int er = oS.rbegin()->second;
        oS.erase({t[er], er});
        time -= t[er];
        time += partly(t[er]);
        S.insert({t[er], er});
      }
    } else {
      time -= t[i];
      oS.erase({t[i], i});
    }
  };
  for (i = 1; i <= n; ++i) {
    j = max(j, i);
    while (j <= n && time <= k) {
      insert(j);
      ++j;
    }
    if (time > k) {
      --j;
      erase(j);
    }
    ans = max(ans, cans);
    if (j > i) erase(i);
  }
  cout << ans << "\n";
}
void reset() {}
int main() {
  int k = 1;
  for (; k <= 1; ++k) {
    reset();
    solve();
  }
}
