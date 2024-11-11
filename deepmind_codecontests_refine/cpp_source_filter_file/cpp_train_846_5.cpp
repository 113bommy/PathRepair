#include <bits/stdc++.h>
const int N = 200005;
int n, m, ll, rr, flg, cnt[N << 2], a[N], b[N];
int all_zero[N << 2], lst[N << 2], c, d, p;
void update(int rt) {
  all_zero[rt] = all_zero[rt << 1] && all_zero[rt << 1 | 1];
  if (!all_zero[rt << 1])
    lst[rt] = lst[rt << 1];
  else if (!all_zero[rt << 1 | 1])
    lst[rt] = lst[rt << 1 | 1];
  else
    lst[rt] = 2 * n + 1;
}
void build(int l, int r, int rt) {
  if (l == r) {
    if (cnt[l])
      lst[rt] = l;
    else
      all_zero[rt] = 1, lst[rt] = 2 * n + 1;
    return;
  }
  int m = (l + r) >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  update(rt);
}
int query(int l, int r, int rt, int nowl, int nowr) {
  if (l >= nowl && r <= nowr) return lst[rt];
  int m = (l + r) >> 1;
  int ans = 2 * n + 1;
  if (m >= nowl) {
    int tmp = query(l, m, rt << 1, nowl, nowr);
    ans = ans < tmp ? ans : tmp;
  }
  if (m < nowr) {
    int tmp = query(m + 1, r, rt << 1 | 1, nowl, nowr);
    ans = ans < tmp ? ans : tmp;
  }
  return ans;
}
void modify(int l, int r, int rt, int nowl) {
  if (l == nowl && r == nowl) {
    cnt[l]--;
    if (cnt[l] == 0) {
      lst[rt] = 2 * n + 1;
      all_zero[rt] = 1;
    }
    return;
  }
  int m = (l + r) >> 1;
  if (m >= nowl) modify(l, m, rt << 1, nowl);
  if (m < nowl) modify(m + 1, r, rt << 1 | 1, nowl);
  update(rt);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    cnt[b[i] ? b[i] : n]++;
    cnt[b[i] ? b[i] + n : 2 * n]++;
  }
  build(1, 2 * n, 1);
  for (int i = 1; i <= n; i++) {
    int ans = query(1, 2 * n, 1, n - a[i], 2 * n - a[i] - 1);
    modify(1, 2 * n, 1, ans % n ? ans % n : n);
    modify(1, 2 * n, 1, ans % n ? n + ans % n : n + n);
    printf("%d ", (a[i] + ans) % n);
  }
  return 0;
}
