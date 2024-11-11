#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100020], q;
vector<int> stk[100020];
int pre[100020];
int ch[100020 * 20][2], s[100020 * 20];
int tot, rt[100020];
int update(int i, int x, int ll, int rr) {
  int k = ++tot;
  ch[k][0] = ch[i][0];
  ch[k][1] = ch[i][1];
  s[k] = s[i] + 1;
  if (ll == rr) return k;
  if (x <= ((ll + rr) >> 1))
    ch[k][0] = update(ch[i][0], x, ll, ((ll + rr) >> 1));
  else
    ch[k][1] = update(ch[i][1], x, ((ll + rr) >> 1) + 1, rr);
  return k;
}
int query(int i, int o, int l, int r, int ll, int rr) {
  if (ll == l && rr == r) return s[i] - s[o];
  if (r <= ((ll + rr) >> 1))
    return query(ch[i][0], ch[o][0], l, r, ll, ((ll + rr) >> 1));
  if (l > ((ll + rr) >> 1))
    return query(ch[i][1], ch[o][1], l, r, ((ll + rr) >> 1) + 1, rr);
  return query(ch[i][0], ch[o][0], l, ((ll + rr) >> 1), ll, ((ll + rr) >> 1)) +
         query(ch[i][1], ch[o][1], ((ll + rr) >> 1) + 1, r,
               ((ll + rr) >> 1) + 1, rr);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    stk[a[i]].push_back(i);
    if (stk[a[i]].size() > k) {
      int len = stk[a[i]].size();
      pre[i] = stk[a[i]][len - k - 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    rt[i] = update(rt[i - 1], pre[i], 0, n);
  }
  int q;
  int ans;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = (x + ans) % n + 1;
    y = (y + ans) % n + 1;
    if (x > y) swap(x, y);
    ans = y - x + 1 - query(rt[y], rt[x - 1], x, y, 0, n);
    printf("%d\n", ans);
  }
  return 0;
}
