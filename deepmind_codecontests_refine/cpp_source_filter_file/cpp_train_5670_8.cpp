#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 500;
int lsum[4 * maxn], rsum[4 * maxn], sum[4 * maxn];
int cover[4 * maxn];
int num;
int st[maxn], ed[maxn];
map<int, pair<int, int> > rec;
void build(int root, int l, int r) {
  sum[root] = lsum[root] = rsum[root] = r - l + 1;
  if (l < r) {
    int mid = (l + r) / 2;
    build(2 * root, l, mid);
    build(2 * root + 1, mid + 1, r);
  }
}
void pushdown(int root, int l, int r) {
  int lc = 2 * root, rc = 2 * root + 1;
  int len = r - l + 1;
  if (cover[root] > -1) {
    cover[lc] = cover[rc] = cover[root];
    lsum[lc] = rsum[lc] = sum[lc] = cover[root] ? 0 : len - len / 2;
    lsum[rc] = rsum[rc] = sum[rc] = cover[root] ? 0 : len / 2;
    cover[root] = -1;
  }
}
void pushup(int root, int l, int r) {
  int lc = 2 * root, rc = 2 * root + 1;
  int len = (r - l + 1);
  lsum[root] = lsum[lc];
  if (lsum[lc] == len - len / 2) lsum[root] += lsum[rc];
  rsum[root] = rsum[rc];
  if (rsum[rc] == len / 2) rsum[root] += rsum[lc];
  sum[root] = max(rsum[lc] + lsum[rc], max(sum[lc], sum[rc]));
}
void modify(int root, int l, int r, int x, int y, int s) {
  if (x <= l && r <= y) {
    if (s == 0)
      sum[root] = lsum[root] = rsum[root] = r - l + 1;
    else
      sum[root] = lsum[root] = rsum[root] = 0;
    cover[root] = s;
  } else {
    pushdown(root, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) modify(2 * root, l, mid, x, y, s);
    if (y > mid) modify(2 * root + 1, mid + 1, r, x, y, s);
    pushup(root, l, r);
  }
}
int query(int root, int l, int r, int z) {
  int lc = 2 * root, rc = 2 * root + 1, mid = (l + r) / 2;
  if (l == r) {
    return l;
  } else {
    pushdown(root, l, r);
    if (sum[lc] >= z)
      return query(2 * root, l, mid, z);
    else if (rsum[lc] + lsum[rc] >= z) {
      return mid - rsum[lc] + 1;
    } else
      return query(2 * root + 1, mid + 1, r, z);
  }
}
void print(int root, int l, int r) {
  printf("%d %d %d %d %d\n", root, cover[root], lsum[root], rsum[root],
         sum[root]);
  if (l < r) {
    int mid = (l + r) / 2;
    print(2 * root, l, mid);
    print(2 * root + 1, mid + 1, r);
  }
}
int main() {
  int l, b, f, n;
  while (scanf("%d%d%d", &l, &b, &f) != EOF) {
    scanf("%d", &n);
    memset(cover, -1, sizeof(cover));
    build(1, 1, l + b + f);
    int s, t;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &s, &t);
      if (s == 1) {
        if (sum[1] >= t + b + f) {
          int temp = query(1, 1, l + b + f, t + b + f);
          printf("%d\n", temp - b);
          modify(1, 1, l + b + f, temp + b, temp + b + t - 1, 1);
          rec[i] = make_pair(temp, temp + t + b);
        } else {
          printf("-1\n");
          rec[i] = make_pair(-1, -1);
        }
      } else {
        rec[i] = make_pair(-1, -1);
        modify(1, 1, l + b + f, rec[t].first, rec[t].second, 0);
      }
    }
  }
  return 0;
}
