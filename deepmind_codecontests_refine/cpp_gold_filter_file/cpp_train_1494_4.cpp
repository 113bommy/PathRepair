#include <bits/stdc++.h>
using namespace std;
struct TNode {
  int idx, v;
} ans[200015];
int n, m;
deque<int> dq;
bool cmp(TNode p1, TNode p2) {
  return p1.v < p2.v || (p1.v == p2.v && p1.idx < p2.idx);
}
int main() {
  int i, j, k, maxl, lk, lh;
  while (scanf("%d%d%d", &n, &m, &m) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &ans[i].v);
      ans[i].idx = i;
    }
    sort(ans, ans + n, cmp);
    maxl = 0;
    dq.clear();
    dq.push_back(0);
    for (i = 1; i < n; i++) {
      if (ans[i].v == ans[i - 1].v) {
        lk = ans[i].idx - ans[i - 1].idx - 1 + dq.back();
        dq.push_back(lk);
        while (dq.back() - dq.front() > m) dq.pop_front();
        lh = dq.size();
        maxl = max(maxl, lh);
      } else {
        dq.clear();
        dq.push_back(0);
      }
    }
    maxl = max(maxl, 1);
    printf("%d\n", maxl);
  }
  return 0;
}
