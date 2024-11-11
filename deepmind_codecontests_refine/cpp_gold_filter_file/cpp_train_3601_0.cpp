#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node {
  int num;
  ll k1, k2;
  node operator+(const node &a) const {
    if (a.num == num)
      return {num, k1 + a.k1, k2 + a.k2};
    else if (num > a.num)
      return a;
    else
      return *this;
  }
};
node tree[222222 * 4][2];
int add[222222 * 4][2];
void build(int now, int l, int r) {
  add[now][0] = add[now][1] = 0;
  if (l == r) {
    tree[now][l & 1] = {0, 1, l - 1};
    tree[now][!(l & 1)] = {0, 0, 0};
    return;
  }
  build((now * 2), l, (l + r) / 2), build((now * 2 + 1), (l + r) / 2 + 1, r);
  tree[now][1] = tree[(now * 2)][1] + tree[(now * 2 + 1)][1];
  tree[now][0] = tree[(now * 2)][0] + tree[(now * 2 + 1)][0];
}
void pushit(int now, int x, int id) {
  tree[now][id].num += x;
  add[now][id] += x;
}
void pushdown(int now, int l, int r, int id) {
  int k = add[now][id];
  add[now][id] = 0;
  if (l == r) return;
  pushit((now * 2), k, id), pushit((now * 2 + 1), k, id);
}
void update(int now, int l, int r, int ql, int qr, int id, int x) {
  if (ql > qr) return;
  if (add[now][id]) pushdown(now, l, r, id);
  if (l == ql && r == qr) {
    pushit(now, x, id);
    return;
  }
  if (qr <= (l + r) / 2)
    update((now * 2), l, (l + r) / 2, ql, qr, id, x);
  else if (ql > (l + r) / 2)
    update((now * 2 + 1), (l + r) / 2 + 1, r, ql, qr, id, x);
  else {
    update((now * 2), l, (l + r) / 2, ql, (l + r) / 2, id, x);
    update((now * 2 + 1), (l + r) / 2 + 1, r, (l + r) / 2 + 1, qr, id, x);
  }
  tree[now][id] = tree[(now * 2)][id] + tree[(now * 2 + 1)][id];
}
node query(int now, int l, int r, int ql, int qr, int id) {
  if (add[now][id]) pushdown(now, l, r, id);
  if (l == ql && r == qr) return tree[now][id];
  if (qr <= (l + r) / 2)
    return query((now * 2), l, (l + r) / 2, ql, qr, id);
  else if (ql > (l + r) / 2)
    return query((now * 2 + 1), (l + r) / 2 + 1, r, ql, qr, id);
  else
    return query((now * 2), l, (l + r) / 2, ql, (l + r) / 2, id) +
           query((now * 2 + 1), (l + r) / 2 + 1, r, (l + r) / 2 + 1, qr, id);
}
int l[222222], r[222222], num[222222];
vector<pair<int, int> > v[222222];
int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d%d", &l[i], &r[i]);
    num[l[i]]++, num[r[i] + 1]--;
    v[l[i]].emplace_back(i, 1);
    v[r[i]].emplace_back(i, -1);
  }
  ll res = 0;
  for (int i = 0; i < 2; i++) {
    build(1, 1, m);
    for (int j = 1; j < n + 1; j++) update(1, 1, m, l[j], r[j], !i, 1);
    for (int j = 2 - i; j <= m; j += 2) {
      for (auto p : v[j - 1]) {
        int k1 = p.first;
        if (p.second == 1) {
          update(1, 1, m, 1, j - 1 - 1, 1, 1);
          update(1, 1, m, 1, j - 1 - 1, 0, 1);
        } else {
          if (((l[k1] + 1) & 1) == i) {
            update(1, 1, m, 1, l[k1] - 1, 0, -1);
            update(1, 1, m, 1, l[k1] - 1, 1, -1);
          } else {
            update(1, 1, m, 1, l[k1] - 1, 0, 1);
            update(1, 1, m, 1, l[k1] - 1, 1, 1);
          }
          update(1, 1, m, l[k1], r[k1], !i, -1);
          update(1, 1, m, l[k1], r[k1], i, 1);
        }
      }
      node r = query(1, 1, m, 1, j, 0) + query(1, 1, m, 1, j, 1);
      if (r.num == 0) res += r.k1 * j - r.k2;
    }
  }
  for (int i = 1; i < m + 1; i++) num[i] += num[i - 1];
  num[m + 1] = 0;
  int now = 1;
  while (now <= m) {
    while (num[now]) now++;
    int k1 = now;
    while (now <= m && !num[now]) now++;
    ll k2 = now - k1;
    res -= ((k2 + 1) * k2 / 2 + (k2) * (k2 + 1) * (2 * k2 + 1) / 6) / 2;
  }
  printf("%I64d\n", res);
}
