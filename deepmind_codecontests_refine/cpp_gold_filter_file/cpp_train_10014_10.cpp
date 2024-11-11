#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int ans[N + 100];
vector<pair<int, int> > v;
set<pair<int, int> > stp;
set<int> sti1, sti2;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    v.push_back(make_pair(a, i));
    stp.insert(make_pair(a, i));
    sti1.insert(i);
  }
  sort(v.begin(), v.end(), greater<pair<int, int> >());
  if (v.back().first * 2 >= v[0].first) {
    for (int i = 1; i <= n; i++) {
      printf("-1 ");
    }
    printf("\n");
    return 0;
  }
  for (auto it : v) {
    auto i = stp.lower_bound(make_pair((it.first + 1) / 2, -1));
    while (i != stp.end()) {
      sti1.erase(i->second);
      pair<int, int> del = *i;
      i++;
      stp.erase(del);
    }
    if (sti1.empty()) {
      auto cur = sti2.lower_bound(it.second);
      if (cur == sti2.end()) cur = sti2.lower_bound(0);
      if (*cur > it.second) {
        ans[it.second] = *cur - it.second + ans[*cur];
      } else {
        ans[it.second] = n - it.second + *cur + ans[*cur];
      }
    } else {
      if (sti2.empty()) {
        auto cur = sti1.lower_bound(it.second);
        if (cur == sti1.end()) {
          cur = sti1.lower_bound(0);
        }
        if (*cur > it.second) {
          ans[it.second] = *cur - it.second;
        } else {
          ans[it.second] = n - it.second + *cur;
        }
      } else {
        auto cur = sti2.lower_bound(it.second);
        if (cur == sti2.end()) {
          cur = sti2.lower_bound(0);
        }
        auto now = sti1.lower_bound(it.second);
        if (now == sti1.end()) {
          now = sti1.lower_bound(0);
        }
        int t2 = *cur, t1 = *now;
        if (t1 < it.second) t1 += n;
        if (t2 < it.second) t2 += n;
        if (t2 <= t1) {
          ans[it.second] = t2 - it.second;
          if (t2 > n) t2 -= n;
          ans[it.second] += ans[t2];
        } else {
          ans[it.second] = t1 - it.second;
        }
      }
    }
    sti2.insert(it.second);
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}
