#include <bits/stdc++.h>
using namespace std;
struct Node {
  int l, r, cost;
  bool operator<(const Node& rhs) const {
    return l != rhs.l ? l < rhs.l : r < rhs.r;
  }
} sec[200010];
set<pair<int, int> > dic[200010];
vector<pair<int, int> > tmp;
inline void push_dic(int l, int r, int c) {
  dic[r - l + 1].insert(pair<int, int>(r, c));
  auto it = dic[r - l + 1].find(pair<int, int>(r, c));
  tmp.clear();
  if (it != dic[r - l + 1].begin()) {
    auto pre = it;
    pre--;
    if (pre->second <= c)
      dic[r - l + 1].erase(it);
    else {
      auto nxt = it;
      nxt++;
      while (nxt != dic[r - l + 1].end() && nxt->second >= c) {
        tmp.push_back(*nxt);
        nxt++;
      }
    }
  } else {
    auto nxt = it;
    nxt++;
    while (nxt != dic[r - l + 1].end() && nxt->second >= c) {
      tmp.push_back(*nxt);
      nxt++;
    }
  }
  for (pair<int, int> v : tmp) {
    dic[r - l + 1].erase(v);
  }
}
int main() {
  int n, x;
  int l, r, c;
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &l, &r, &c);
    sec[i] = (Node){l, r, c};
  }
  sort(sec, sec + n);
  int ans = 0x7fffffff;
  for (int i = 0; i < n; i++) {
    l = sec[i].l, r = sec[i].r, c = sec[i].cost;
    if (x > r - l + 1 && dic[x - (r - l + 1)].size() > 0) {
      auto it =
          dic[x - (r - l + 1)].lower_bound(pair<int, int>(r, -0x7fffffff));
      if (it != dic[x - (r - l + 1)].begin()) {
        it--;
        ans = min(ans, it->second + c);
      }
    }
    push_dic(l, r, c);
  }
  printf("%d\n", ans == 0x7fffffff ? -1 : ans);
  return 0;
}
