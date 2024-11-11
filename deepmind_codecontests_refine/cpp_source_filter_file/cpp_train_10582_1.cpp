#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 15;
int N, Q, a[maxn], askM, changeM, belong[maxn], cnt[maxn], st[maxn], ans[maxn],
    b[maxn << 1], tot;
struct node {
  int l, r, id, k;
} ask[maxn];
struct NODE {
  int x, y;
} change[maxn];
bool cmp(node x, node y) {
  if (belong[x.l] == belong[y.l]) {
    if (belong[x.r] == belong[y.r]) return x.k < y.k;
    if (belong[x.l] & 1) return belong[x.r] < belong[y.r];
    return belong[x.r] > belong[y.r];
  }
  return belong[x.l] < belong[y.l];
}
void del(int x) {
  st[cnt[x]]--;
  cnt[x]--;
  st[cnt[x]]++;
}
void ins(int x) {
  st[cnt[x]]--;
  cnt[x]++;
  st[cnt[x]]++;
}
int main() {
  scanf("%d%d", &N, &Q);
  for (int i = 1; i <= N; i++) scanf("%d", &a[i]), b[++tot] = a[i];
  for (int i = 1; i <= Q; i++) {
    int opt, l, r, x, y;
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d%d", &l, &r);
      askM++;
      ask[askM].l = l, ask[askM].r = r, ask[askM].id = askM,
      ask[askM].k = changeM;
    } else {
      scanf("%d%d", &x, &y);
      changeM++;
      change[changeM].x = x, change[changeM].y = y, b[++tot] = y;
    }
  }
  sort(b + 1, b + tot + 1);
  tot = unique(b + 1, b + tot + 1) - b;
  for (int i = 1; i <= N; i++) a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
  for (int i = 1; i <= changeM; i++)
    change[i].y = lower_bound(b + 1, b + tot + 1, change[i].y) - b;
  int len = pow(N, (double)2.0 / 3.0), bnum = ceil((double)N / len);
  for (int i = 1; i <= bnum; i++)
    for (int j = (i - 1) * len + 1; j <= min(i * len, N); j++) belong[j] = i;
  sort(ask + 1, ask + askM + 1, cmp);
  int l = 1, r = 0, time = 0;
  for (int i = 1; i <= askM; i++) {
    int ql = ask[i].l, qr = ask[i].r, qt = ask[i].k;
    while (l > ql) ins(a[--l]);
    while (l < ql) del(a[l++]);
    while (r < qr) ins(a[++r]);
    while (r > qr) del(a[r--]);
    while (time < qt) {
      time++;
      if (l <= change[time].x and change[time].x <= r)
        del(a[change[time].x]), ins(change[time].y);
      swap(a[change[time].x], change[time].y);
    }
    while (time > qt) {
      if (l <= change[time].x and change[time].x <= r)
        del(a[change[time].x]), ins(change[time].y);
      swap(a[change[time].x], change[time].y);
      time--;
    }
    int now = 0;
    while (st[now + 1]) now++;
    ans[ask[i].id] = now + 1;
  }
  for (int i = 1; i <= askM; i++) printf("%d\n", ans[i]);
  return 0;
}
