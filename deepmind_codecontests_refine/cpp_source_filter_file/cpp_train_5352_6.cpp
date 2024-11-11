#include <bits/stdc++.h>
using namespace std;
int n, a[100005], la[100005], nx[100005], nw[100005], len[100005], fst[100005];
vector<pair<int, int> > add[100005], del[100005], ask[100005];
int q, l[100005], r[100005], ans[100005], t[100005], cnt[100005];
pair<pair<int, int>, int> p[100005];
void ad(int x) {
  while (x <= n) ++t[x], x += (x & -x);
}
void de(int x) {
  while (x <= n) --t[x], x += (x & -x);
}
int get(int x) {
  int ans = 0;
  while (x) ans += t[x], x -= (x & -x);
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) {
    la[i] = nw[a[i]];
    nw[a[i]] = i;
    if (la[i]) {
      len[i] = i - la[i];
      if (len[la[i]] == len[i] || !len[la[i]])
        fst[i] = fst[la[i]];
      else
        fst[i] = la[i];
    } else
      fst[i] = i;
  }
  for (int i = 1; i <= 100000; ++i) nw[i] = n + 1;
  for (int i = n; i; i--) {
    nx[i] = nw[a[i]];
    nw[a[i]] = i;
    add[la[fst[i]] + 1].push_back(make_pair(i, nx[i] - 1));
    del[i].push_back(make_pair(i, nx[i] - 1));
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i)
    scanf("%d%d", l + i, r + i), ask[l[i]].push_back(make_pair(r[i], i)),
        p[i] = make_pair(make_pair(l[i] / 300, r[i]), i);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < add[i].size(); ++i)
      ad(add[i][j].first), de(add[i][j].second + 1);
    for (int j = 0; j < ask[i].size(); ++i)
      if (!get(ask[i][j].first)) ans[ask[i][j].second] = 1;
    for (int j = 0; j < del[i].size(); ++i)
      de(del[i][j].first), ad(del[i][j].second + 1);
  }
  sort(p + 1, p + q + 1);
  int L = 1, R = 0, res = 0;
  for (int i = 1; i <= q; ++i) {
    int k = p[i].second;
    while (R < r[k]) res += ((++cnt[a[++R]]) == 1);
    while (L > l[k]) res += ((++cnt[a[--L]]) == 1);
    while (L < l[k]) res -= ((--cnt[a[L++]]) == 0);
    while (R > r[k]) res -= ((--cnt[a[R--]]) == 0);
    ans[k] += res;
  }
  for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
  return 0;
}
