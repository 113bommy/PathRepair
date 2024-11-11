#include <bits/stdc++.h>
using namespace std;
struct NODE {
  int posx;
  int l, r;
  int del, id;
} data[100005 << 2];
int n, m, tot, cnt;
int p[100005], s[100005], b[100005];
int inc[100005], pref[100005], ans[100005];
int c1[100005 << 2], c2[100005 << 2], num[100005 << 2];
inline int lowbit(int x) { return x & (-x); }
void changeA(int pos, int val) {
  while (pos <= tot) {
    c1[pos] += val;
    pos += lowbit(pos);
  }
}
void changeB(int pos, int val) {
  while (pos <= tot) {
    c2[pos] += val;
    pos += lowbit(pos);
  }
}
int queryA(int pos) {
  int sum = 0;
  while (pos) {
    sum += c1[pos];
    pos -= lowbit(pos);
  }
  return sum;
}
int queryB(int pos) {
  int sum = 0;
  while (pos) {
    sum += c2[pos];
    pos -= lowbit(pos);
  }
  return sum;
}
bool comp(const NODE& x, const NODE& y) {
  return x.posx < y.posx || (x.posx == y.posx && x.del < y.del);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &inc[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &pref[i]);
  for (int i = 1; i <= n; i++)
    num[++tot] = p[i] + b[i], num[++tot] = b[i] - p[i] + 1;
  for (int i = 1; i <= m; i++)
    num[++tot] = inc[i] + pref[i], num[++tot] = pref[i] - inc[i];
  sort(num + 1, num + tot + 1);
  int tt = unique(num + 1, num + tot + 1) - num - 1;
  tot = tt;
  for (int i = 1; i <= n; i++) {
    data[++cnt] = (NODE){p[i], p[i], b[i], 1, 0};
    data[++cnt] = (NODE){s[i] + 1, p[i], b[i], -1, 0};
  }
  for (int i = 1; i <= m; i++) data[++cnt] = {inc[i], inc[i], pref[i], 2, i};
  sort(data + 1, data + cnt + 1, comp);
  for (int i = 1; i <= cnt; i++)
    if (data[i].del <= 1) {
      changeA(lower_bound(num + 1, num + tot + 1, data[i].l + data[i].r) - num,
              data[i].del);
      changeB(
          lower_bound(num + 1, num + tot + 1, data[i].r - data[i].l + 1) - num,
          data[i].del);
    } else
      ans[data[i].id] =
          queryA(lower_bound(num + 1, num + tot + 1, data[i].l + data[i].r) -
                 num) -
          queryB(lower_bound(num + 1, num + tot + 1, data[i].r - data[i].l) -
                 num);
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
  return 0;
}
