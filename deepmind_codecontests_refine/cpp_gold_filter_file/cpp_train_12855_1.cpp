#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
constexpr int inf = 1e9;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), as;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    as.push_back(a[i]);
  }
  sort(begin(as), end(as));
  as.erase(unique(begin(as), end(as)), end(as));
  for (auto& h : a) {
    h = lower_bound(begin(as), end(as), h) - begin(as);
  }
  vector<vector<int>> pos(as.size());
  for (int i = 0; i < n; ++i) {
    pos[a[i]].push_back(i);
  }
  set<pii> segs;
  multiset<int> lens;
  vector<int> ans(n, -1);
  auto erase_seg = [&](pii s) {
    segs.erase(s);
    lens.erase(lens.lower_bound(s.second - s.first + 1));
  };
  auto insert_seg = [&](pii s) {
    segs.insert(s);
    lens.insert(s.second - s.first + 1);
  };
  for (int i = as.size() - 1; i >= 0; --i) {
    for (auto& p : pos[i]) {
      if (segs.empty()) {
        insert_seg(make_pair(p, p));
        continue;
      }
      auto it = segs.lower_bound(make_pair(p, -1));
      if (end(segs) != it && begin(segs) != it) {
        auto pre = prev(it);
        if (it->first == p + 1 && pre->second + 1 == p) {
          auto s1 = *pre, s2 = *it;
          erase_seg(s1);
          erase_seg(s2);
          insert_seg(make_pair(s1.first, s2.second));
        } else if (it->first == p + 1) {
          auto s = *it;
          erase_seg(s);
          insert_seg(make_pair(s.first - 1, s.second));
        } else if (pre->second + 1 == p) {
          auto s = *pre;
          erase_seg(s);
          insert_seg(make_pair(s.first, s.second + 1));
        } else {
          insert_seg(make_pair(p, p));
        }
      } else if (end(segs) != it) {
        auto s = *it;
        if (s.first == p + 1) {
          erase_seg(s);
          insert_seg(make_pair(s.first - 1, s.second));
        } else {
          insert_seg(make_pair(p, p));
        }
      } else {
        it = prev(it);
        auto s = *it;
        if (s.second + 1 == p) {
          erase_seg(s);
          insert_seg(make_pair(s.first, s.second + 1));
        } else {
          insert_seg(make_pair(p, p));
        }
      }
    }
    auto maxi_len = *prev(end(lens));
    ans[maxi_len - 1] = max(ans[maxi_len - 1], as[i]);
  }
  for (int i = n - 1; i >= 1; --i) {
    ans[i - 1] = max(ans[i - 1], ans[i]);
  }
  for (int i = 0; i < n; ++i) {
    printf("%d\n", ans[i]);
  }
}
