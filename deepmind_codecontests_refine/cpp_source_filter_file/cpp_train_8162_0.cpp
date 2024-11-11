#include <bits/stdc++.h>
using namespace std;
map<int, bool> a;
map<int, vector<int>> v;
map<int, vector<pair<int, int>>> s;
vector<pair<int, int>> temp;
int main() {
  int i, j, n, m, x, y, z, t, len, pre;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    a[x] = 1;
    v[x].push_back(y);
  }
  for (auto p : a) {
    sort(v[p.first].begin(), v[p.first].end());
    pre = 1;
    for (auto pp : v[p.first]) {
      if (pp != pre) {
        s[p.first].push_back(make_pair(pre, pp - 1));
      }
      pre = pp + 1;
    }
    if (pre <= n) {
      s[p.first].push_back(make_pair(pre, n));
    }
  }
  if (a.count(1)) {
    while (((int)(s[1]).size()) > 1) {
      s[1].pop_back();
    }
  }
  if (a[n] == 0) s[n].push_back(make_pair(1, n));
  if (a[1] == 0) s[1].push_back(make_pair(1, n));
  for (auto pp : s) {
    auto it = pp.first;
    temp.clear();
    if (it == 1) {
      pre = 1;
      continue;
    }
    if ((it - pre) > 1) {
      for (auto p : s[it]) {
        y = 1000000007;
        j = lower_bound(s[pre].begin(), s[pre].end(),
                        make_pair(p.first, p.first)) -
            s[pre].begin();
        if (j < ((int)(s[pre]).size())) {
          y = s[pre][j].first;
        }
        if (j > 0) {
          y = p.first;
        }
        if (y <= p.second) {
          temp.push_back(make_pair(y, p.second));
        }
      }
    } else {
      for (auto p : s[it]) {
        y = 1000000007;
        j = lower_bound(s[pre].begin(), s[pre].end(),
                        make_pair(p.first, p.first)) -
            s[pre].begin();
        if (j < ((int)(s[pre]).size())) {
          y = s[pre][j].first;
        }
        if (j > 0 && s[pre][j - 1].second >= p.first) {
          y = p.first;
        }
        if (y <= p.second) {
          temp.push_back(make_pair(y, p.second));
        }
      }
    }
    if (temp.empty()) {
      puts("-1");
      return 0;
    }
    pre = it;
    s[pre].clear();
    for (auto p : temp) {
      s[pre].push_back(p);
    }
  }
  if (s[1][0].first == 1 && s[n][((int)(s[n]).size()) - 1].second == n) {
    printf("%d\n", 2 * n - 2);
    ;
  } else {
    printf("%d\n", -1);
    ;
  }
}
