#include <bits/stdc++.h>
using namespace std;
int block;
struct data {
  int l, r, idx;
  bool operator<(const data& a) const {
    if (l / block != a.l / block) {
      return l / block < a.l / block;
    }
    return r < a.r;
  }
};
int ara[100007], cnt[2000000], counti = 0, n, m;
inline void add(int ps) {
  if (ara[ps] <= n) {
    cnt[ara[ps]]++;
    if (cnt[ara[ps]] == ara[ps]) {
      counti++;
    }
    if (cnt[ara[ps]] == ara[ps] + 1) {
      counti--;
    }
  }
}
inline void rmv(int ps) {
  if (ara[ps] <= n) {
    cnt[ara[ps]]--;
    if (cnt[ara[ps]] == ara[ps] - 1) {
      counti--;
    }
    if (cnt[ara[ps]] == ara[ps]) {
      counti++;
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  block = sqrt(n) + 1;
  for (int i = 1; i <= n; i++) scanf("%d ", &ara[i]);
  data Q[m + 7];
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &Q[i].l, &Q[i].r);
    Q[i].idx = i;
  }
  sort(Q, Q + m);
  int curL = 1, curR = 1;
  int ans[m + 7];
  memset(cnt, 0, sizeof cnt);
  add(1);
  for (int i = 0; i < m; i++) {
    while (curL < Q[i].l) rmv(curL++);
    while (curL > Q[i].l) add(--curL);
    while (curR < Q[i].r) add(++curR);
    while (curR > Q[i].r) rmv(curR--);
    ans[Q[i].idx] = counti;
  }
  for (int i = 0; i < m; i++) cout << ans[i] << endl;
  return 0;
}
