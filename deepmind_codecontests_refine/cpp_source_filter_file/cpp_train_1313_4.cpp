#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const double PI = acos(-1);
int n, q, arr[N], lastl[4 * N], lastr[4 * N], cur1, cur2, cur3, cur4, cur5,
    cur6, cur7, cur8, cur9, st, l, r, l2, r2;
vector<int> seg[4 * N];
vector<int>::iterator it, it2;
long long ans = 0;
void build(int s, int e, int idx) {
  if (s == e) {
    seg[idx].push_back(arr[s] - 1);
    return;
  }
  build(s, (s + e) / 2, idx * 2);
  build((s + e) / 2 + 1, e, idx * 2 + 1);
  int j = 0;
  for (int i = 0; i < seg[idx * 2].size(); i++) {
    while (j < seg[idx * 2 + 1].size() && seg[idx * 2 + 1][j] < seg[idx * 2][i])
      seg[idx].push_back(seg[idx * 2 + 1][j++]);
    seg[idx].push_back(seg[idx * 2][i]);
  }
  while (j < seg[idx * 2 + 1].size()) seg[idx].push_back(seg[idx * 2 + 1][j++]);
}
inline void get(int s, int e, int idx, int l, int r, int l2, int r2) {
  if (l > r) return;
  if (s > r || e < l) return;
  if (s >= l && e <= r) {
    it = upper_bound(seg[idx].begin(), seg[idx].end(), r2);
    it2 = lower_bound(seg[idx].begin(), seg[idx].end(), l2);
    if (st == 0) {
      cur1 += it2 - seg[idx].begin();
      cur4 += it - it2;
      cur7 += seg[idx].end() - it;
    } else if (st == 1) {
      cur2 += it2 - seg[idx].begin();
      cur5 += it - it2;
      cur8 += seg[idx].end() - it;
    } else {
      cur3 += it2 - seg[idx].begin();
      cur6 += it - it2;
      cur9 += seg[idx].end() - it;
    }
    return;
  }
  get(s, (s + e) / 2, idx * 2, l, r, l2, r2);
  get((s + e) / 2 + 1, e, idx * 2 + 1, l, r, l2, r2);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  build(0, n - 1, 1);
  while (q--) {
    scanf("%d%d%d%d", &l2, &l, &r2, &r);
    l--, r--, l2--, r2--;
    cur1 = cur2 = cur3 = cur4 = cur5 = cur6 = cur7 = cur8 = cur9 = 0;
    st = 0;
    get(0, n - 1, 1, 0, l - 1, l2, r2);
    st = 1;
    get(0, n - 1, 1, l, r, l2, r2);
    st = 2;
    get(0, n - 1, 1, r + 1, n - 1, l2, r2);
    ans = 0;
    ans += (long long)cur1 * (cur5 + cur6 + cur8 + cur9);
    ans += (long long)cur2 * (cur4 + cur5 + cur6 + cur7 + cur8 + cur9);
    ans += (long long)cur3 * (cur4 + cur5 + cur7 + cur8);
    ans += (long long)cur4 * (cur5 + cur6 + cur8 + cur9);
    ans += (long long)cur5 * (cur6 + cur7 + cur8 + cur9);
    ans += (long long)cur6 * (cur7 + cur8);
    ans += (long long)cur5 * (cur5 - 1) / 2;
    printf("%lld\n", ans);
  }
  return 0;
}
