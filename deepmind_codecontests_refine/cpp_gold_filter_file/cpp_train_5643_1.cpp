#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const double pi = acos(-1.0);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int inf = 0x7f7f7f7f;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n, m, t;
int i, j, k;
set<pair<int, int> > s;
vector<int> ans;
struct Segment {
  int l, r;
  int id;
  const bool operator<(const Segment &b) const { return l < b.l; }
} a[N];
int main() {
  while (scanf("%d%d", &n, &k) == 2) {
    int maxx = -1, minn = inf;
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &a[i].l, &a[i].r);
      minn = min(a[i].l, minn);
      maxx = max(a[i].r, maxx);
      a[i].id = i;
    }
    sort(a + 1, a + 1 + n);
    int cur = 1;
    for (int i = minn; i <= maxx; i++) {
      while (cur <= n && a[cur].l <= i) {
        s.insert(make_pair(a[cur].r, a[cur].id));
        ++cur;
      }
      while (s.size() && (*s.begin()).first < i) {
        s.erase(s.begin());
      }
      while (s.size() > k) {
        int id = s.rbegin()->second;
        s.erase(*s.rbegin());
        ans.push_back(id);
      }
    }
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for (auto it : ans) {
      printf("%d ", it);
    }
    puts("");
  }
  return 0;
}
