#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 15;
int tot = 1, N;
const int L = -2e8;
const int R = 2e8;
struct Node {
  int l, r, num;
  long long sum;
  Node() { l = 0, r = 0, num = 0, sum = 0; }
} E[maxn * 40];
struct Point {
  long long x, v;
  bool operator<(const Point &T) const { return x > T.x; }
} P[maxn];
void update(int l, int r, int x, int v, int id) {
  if (l == r) {
    E[id].num++;
    E[id].sum += x;
    return;
  }
  int mid = (l + r) >> 1;
  if (v <= mid) {
    if (!E[id].l) E[id].l = ++tot;
    update(l, mid, x, v, E[id].l);
  } else {
    if (!E[id].r) E[id].r = ++tot;
    update(mid + 1, R, x, v, E[id].r);
  }
  E[id].num = E[E[id].l].num + E[E[id].r].num;
  E[id].sum = E[E[id].l].sum + E[E[id].r].sum;
}
void getSum(int l, int r, int ln, int rn, int id, int &num, long long &sum) {
  if (ln > rn) return;
  if (ln == l && rn == r) {
    num += E[id].num;
    sum += E[id].sum;
    return;
  }
  int mid = (l + r) >> 1;
  if (ln > mid && E[id].r)
    getSum(mid + 1, r, ln, rn, E[id].r, num, sum);
  else if (rn <= mid && E[id].l)
    getSum(l, mid, ln, rn, E[id].l, num, sum);
  else {
    if (E[id].r) getSum(mid + 1, r, mid + 1, rn, E[id].r, num, sum);
    if (E[id].l) getSum(l, mid, ln, mid, E[id].l, num, sum);
  }
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%lld", &P[i].x);
  for (int i = 1; i <= N; i++) scanf("%lld", &P[i].v);
  sort(P + 1, P + 1 + N);
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    int num = 0;
    long long sum = 0;
    getSum(L, R, P[i].v, R, 1, num, sum);
    ans += (sum - 1LL * num * P[i].x);
    update(L, R, P[i].x, P[i].v, 1);
  }
  printf("%lld\n", ans);
  return 0;
}
