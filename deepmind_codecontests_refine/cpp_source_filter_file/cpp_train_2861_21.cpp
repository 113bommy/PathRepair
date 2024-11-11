#include <bits/stdc++.h>
using namespace std;
int n, m, t, r, mx;
deque<pair<int, int> > cur;
vector<int> res;
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d:%d:%d", &a, &b, &c);
    int x = 3600 * a + 60 * b + c;
    while (!cur.empty() && cur.crbegin()->first <= x) {
      cur.pop_back();
    }
    if (cur.size() == m) {
      res.push_back(cur[0].second);
      cur[0].first = x + t;
    } else {
      res.push_back(++r);
      cur.push_back({x + t, r});
    }
    mx = max(int(res.size()), mx);
  }
  if (mx < m) {
    puts("No solution");
  } else {
    printf("%d\n", r);
    for (int i = 0; i < n; i++) {
      printf("%d\n", res[i]);
    }
  }
  return 0;
}
