#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
int n, i, x, y;
int l[N], r[N], a[N];
char s[N];
vector<pair<int, int> > ans;
struct atom {
  int l, r, p;
};
atom t;
bool d[N];
inline bool operator<(const atom& a, const atom& b) {
  return (a.p < b.p || (a.p == b.p && a.l < b.l));
}
multiset<atom> q;
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    l[i] = i - 1;
    r[i] = i + 1;
  }
  l[1] = r[n] = 0;
  for (i = 1; i < n; ++i)
    if (s[i] != s[i + 1]) q.insert((atom){i, i + 1, abs(a[i] - a[i + 1])});
  while (!q.empty()) {
    t = *q.begin();
    q.erase(q.begin());
    x = t.l, y = t.r;
    if (!d[x] && !d[y]) {
      ans.push_back(make_pair(x, y));
      d[x] = d[y] = 1;
      r[l[x]] = r[x];
      l[r[x]] = l[x];
      r[l[y]] = r[y];
      l[r[y]] = l[y];
      if (l[x] > 0 && r[y] > 0 && !d[l[x]] && !d[r[y]] && s[l[x]] != s[r[y]])
        q.insert((atom){l[x], r[y], abs(a[l[x]] - a[r[y]])});
    }
  }
  printf("%d\n", (int)ans.size());
  for (i = 0; i < (int)ans.size(); ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
