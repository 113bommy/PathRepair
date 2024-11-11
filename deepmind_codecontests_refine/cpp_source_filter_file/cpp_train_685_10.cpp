#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
set<int> S[maxn];
int rt[maxn];
int n, m;
int cnt;
const int maxm = 10000005;
int Sum[maxm];
int Left[maxm], Right[maxm];
void Update(int L, int C, int l, int r, int &tr) {
  if (!tr) tr = ++cnt;
  Sum[tr] += C;
  if (l == r) return;
  int mid = l + r >> 1;
  if (L <= mid)
    Update(L, C, l, mid, Left[tr]);
  else
    Update(L, C, mid + 1, r, Right[tr]);
}
void modify(int pre, int now, int d) {
  while (pre <= maxn) {
    Update(now, d, 1, n, rt[pre]);
    pre += ((pre) & (-pre));
  }
}
void add(int color, int idx) {
  S[color].insert(idx);
  auto it = S[color].find(idx), pre = it, suf = it;
  bool flag1 = false, flag2 = false;
  if (it != S[color].begin()) {
    pre--;
    modify(*pre, *it, *it - *pre);
    flag1 = true;
  }
  suf++;
  if (suf != S[color].end()) {
    modify(*it, *suf, *suf - *it);
    flag2 = true;
  }
  if (flag1 && flag2) {
    modify(*pre, *suf, -(*suf - *pre));
  }
}
void del(int idx) {
  int color = a[idx];
  auto it = S[color].find(idx), pre = it, suf = it;
  bool flag1 = false, flag2 = false;
  if (it != S[color].begin()) {
    pre--;
    modify(*pre, *it, -(*it - *pre));
    flag1 = true;
  }
  suf++;
  if (suf != S[color].end()) {
    modify(*it, *suf, -(*suf - *it));
    flag2 = true;
  }
  if (flag1 && flag2) {
    modify(*pre, *suf, *suf - *pre);
  }
  S[color].erase(idx);
}
long long ask(int L, int R, int l, int r, int &tr) {
  if (!tr || L == l && R == r) return Sum[tr];
  int mid = l + r >> 1;
  if (R <= mid)
    return ask(L, R, l, mid, Left[tr]);
  else if (L > mid)
    return ask(L, R, mid + 1, r, Right[tr]);
  return ask(L, mid, l, mid, Left[tr]) + ask(mid + 1, R, mid + 1, r, Right[tr]);
}
long long query(int x, int y) {
  long long res = 0;
  while (x) {
    res += ask(1, y, 1, n, rt[x]);
    x -= ((x) & (-x));
  }
  return res;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    add(a[i], i);
  }
  int o, x, y;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &o, &x, &y);
    if (o == 1) {
      del(x);
      a[x] = y;
      add(y, x);
    } else {
      printf("%lld\n", query(y, y) - query(x - 1, y));
    }
  }
  return 0;
}
