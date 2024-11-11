#include <bits/stdc++.h>
using namespace std;
const int max_n = 200005;
int n, q;
int a[max_n];
vector<int> stkd, stku;
int tag[max_n];
set<int> pos, gv, lv;
vector<int> ans4[max_n];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  gv.insert(n + 1);
  lv.insert(n + 1);
  for (int i = n; i >= 1; i--) {
    while (!stkd.empty() && a[i] > a[stkd.back()]) {
      int x = stkd.back();
      tag[x]--;
      if (tag[x] == 0) pos.insert(x);
      stkd.pop_back();
    }
    stkd.push_back(i);
    tag[i]++;
    while (!stku.empty() && a[i] < a[stku.back()]) {
      int x = stku.back();
      tag[x]--;
      if (tag[x] == 0) pos.insert(x);
      stku.pop_back();
    }
    stku.push_back(i);
    tag[i]++;
    int r1 = lower_bound(stkd.begin(), stkd.end(), i,
                         [](int x, int y) { return a[x] > a[y]; }) -
             stkd.begin() - 1;
    int r2 = lower_bound(stku.begin(), stku.end(), i,
                         [](int x, int y) { return a[x] < a[y]; }) -
             stku.begin() - 1;
    if (r1 != -1 && r2 != -1) {
      int r = max(stkd[r1], stku[r2]) + 1;
      auto it = pos.lower_bound(r);
      if (it != pos.end()) {
        r = *it;
        int id1 = *lower_bound(stku.begin(), stku.end(), r, greater<int>());
        int id2 = *lower_bound(stkd.begin(), stkd.end(), r, greater<int>());
        ans4[i].push_back(i), ans4[i].push_back(min(id1, id2)),
            ans4[i].push_back(max(id1, id2)), ans4[i].push_back(r);
      }
    }
    if (ans4[i].empty())
      ans4[i] = ans4[i + 1];
    else if (!ans4[i + 1].empty() && ans4[i].back() > ans4[i + 1].back())
      ans4[i] = ans4[i + 1];
    if (i < n) {
      if (a[i] < a[i + 1]) lv.insert(i);
      if (a[i] > a[i + 1]) gv.insert(i);
    }
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (!ans4[l].empty() && ans4[l].back() <= r) {
      printf("4\n");
      for (int i = 0; i < 4; i++) printf("%d ", ans4[l][i]);
      printf("\n");
    } else {
      int r1 = *lv.lower_bound(l), r2 = *gv.lower_bound(l);
      if (max(r1, r2) < r) {
        printf("3\n");
        printf("%d %d %d\n", l, min(r1, r2), max(r1, r2) + 1);
      } else
        printf("0\n");
    }
  }
  return 0;
}
