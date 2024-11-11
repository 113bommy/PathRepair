#include <bits/stdc++.h>
using namespace std;
int t, n, k;
vector<pair<int, int> > v;
queue<int> q;
vector<int> ans;
int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    ans.clear();
    v.clear();
    ans.resize(n + 1, 0);
    v.resize(n + 1);
    for (int i = 1, l, r; i <= n; i++) {
      scanf("%d%d", &l, &r);
      v[i] = make_pair(l, r);
      q.push(i);
    }
    int tm = v[1].first;
    while (!q.empty()) {
      int i = q.front();
      if (tm >= v[i].first && tm <= v[i].second) ans[i] = tm;
      q.pop();
      while (!q.empty() && v[q.front()].second <= tm) q.pop();
      if (q.empty()) break;
      tm = max(tm + 1, v[q.front()].first);
    }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
  }
  return 0;
}
