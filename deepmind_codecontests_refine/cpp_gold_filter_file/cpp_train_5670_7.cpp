#include <bits/stdc++.h>
using namespace std;
int l, b, f;
int a[105], c[105];
int sum[101205 << 2], lsum[101205 << 2], rsum[101205 << 2], visit[101205 << 2];
void pushup(int l, int r, int node) {
  int len = r - l + 1;
  lsum[node] = lsum[node << 1];
  rsum[node] = rsum[node << 1 | 1];
  if (lsum[node] == len - (len >> 1)) lsum[node] += lsum[node << 1 | 1];
  if (rsum[node] == (len >> 1)) rsum[node] += rsum[node << 1];
  sum[node] = max(rsum[node << 1] + lsum[node << 1 | 1],
                  max(sum[node << 1], sum[node << 1 | 1]));
}
void pushdown(int l, int r, int node) {
  int len = r - l + 1;
  if (visit[node] != -1) {
    visit[node << 1] = visit[node << 1 | 1] = visit[node];
    lsum[node << 1] = rsum[node << 1] = sum[node << 1] =
        visit[node] ? 0 : len - (len >> 1);
    lsum[node << 1 | 1] = rsum[node << 1 | 1] = sum[node << 1 | 1] =
        visit[node] ? 0 : (len >> 1);
    visit[node] = -1;
  }
}
void build(int l, int r, int node) {
  visit[node] = -1;
  lsum[node] = rsum[node] = sum[node] = r - l + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, node << 1);
  build(mid + 1, r, node << 1 | 1);
}
void update(int x, int y, int v, int l, int r, int node) {
  if (x <= l && y >= r) {
    lsum[node] = rsum[node] = sum[node] = v ? 0 : r - l + 1;
    visit[node] = v;
    return;
  }
  pushdown(l, r, node);
  int mid = (l + r) >> 1;
  if (x <= mid) update(x, y, v, l, mid, node << 1);
  if (y > mid) update(x, y, v, mid + 1, r, node << 1 | 1);
  pushup(l, r, node);
}
int query(int a, int l, int r, int node) {
  if (l == r) return l;
  pushdown(l, r, node);
  int mid = (l + r) >> 1;
  if (sum[node << 1] >= a)
    return query(a, l, mid, node << 1);
  else if (rsum[node << 1] + lsum[node << 1 | 1] >= a)
    return mid - rsum[node << 1] + 1 + b;
  else
    return query(a, mid + 1, r, node << 1 | 1);
}
int main() {
  int n, choice, x, cnt = 0;
  while (scanf("%d%d%d", &l, &b, &f) != EOF) {
    l = l + b + f;
    build(1, l, 1);
    scanf("%d", &n);
    while (n--) {
      scanf("%d", &choice);
      ++cnt;
      if (choice == 1) {
        scanf("%d", &a[cnt]);
        if (sum[1] < a[cnt] + b + f)
          printf("-1\n");
        else {
          c[cnt] = query(a[cnt] + b + f, 1, l, 1);
          update(c[cnt], c[cnt] + a[cnt] - 1, 1, 1, l, 1);
          printf("%d\n", c[cnt] - 1 - b);
        }
      } else if (choice == 2) {
        scanf("%d", &x);
        update(c[x], c[x] + a[x] - 1, 0, 1, l, 1);
      }
    }
  }
}
