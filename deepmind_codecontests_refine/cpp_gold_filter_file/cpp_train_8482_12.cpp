#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int n, m;
struct Range {
  int idx;
  long long l, r;
  Range() {
    idx = -1;
    l = r = -1;
  }
  bool operator<(const Range &oth) const {
    if (l == oth.l) return r < oth.r;
    return l < oth.l;
  }
} rg[MAXN];
struct Bridge {
  int idx;
  long long len;
  Bridge() {
    idx = -1;
    len = 0;
  }
  bool operator<(const Bridge &oth) const { return len < oth.len; }
} bg[MAXN];
struct Map {
  int rid, bid;
  bool operator<(const Map &oth) const { return rid < oth.rid; }
} mp[MAXN];
class Cmp {
 public:
  bool operator()(const Range &rg1, const Range &rg2) const {
    return rg1.r > rg2.r;
  }
};
int main() {
  cin >> n >> m;
  long long pl, pr;
  cin >> pl >> pr;
  for (int i = 0; i < n - 1; i++) {
    long long cl, cr;
    cin >> cl >> cr;
    rg[i].idx = i;
    rg[i].l = cl - pr;
    rg[i].r = cr - pl;
    pl = cl;
    pr = cr;
  }
  sort(rg, rg + n - 1);
  for (int i = 0; i < m; i++) {
    bg[i].idx = i;
    cin >> bg[i].len;
  }
  sort(bg, bg + m);
  priority_queue<Range, vector<Range>, Cmp> pq;
  int ptr = 0, cnt = 0;
  bool flag = true;
  for (int i = 0; i < m; ++i) {
    while (ptr < n - 1 && bg[i].len >= rg[ptr].l) {
      if (bg[i].len <= rg[ptr].r) {
        pq.push(rg[ptr]);
        ++ptr;
      } else {
        flag = false;
        break;
      }
    }
    if (!flag) break;
    if (!pq.empty()) {
      Range rg = pq.top();
      if (rg.r >= bg[i].len) {
        pq.pop();
        mp[cnt].rid = rg.idx;
        mp[cnt].bid = bg[i].idx;
        cnt++;
        if (cnt >= n - 1) break;
      } else {
        flag = false;
        break;
      }
    }
  }
  if (!flag || ptr < n - 1) {
    puts("No");
  } else {
    puts("Yes");
    sort(mp, mp + n - 1);
    for (int i = 0; i < n - 1; i++) cout << mp[i].bid + 1 << " ";
  }
  return 0;
}
