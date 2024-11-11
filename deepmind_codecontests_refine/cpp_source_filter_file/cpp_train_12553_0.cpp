#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int h, w, n, u, l, r, s;
int tot, Ans;
void Add(int &x, int y) { x = (x + y) % p; }
void Del(int &x, int y) { x = (x - y) % p; }
void Mul(int &x, int y) { x = (long long)x * y % p; }
int add(int x, int y) { return (x + y) % p; }
int del(int x, int y) { return (x - y) % p; }
int mul(int x, int y) { return (long long)x * y % p; }
struct ask {
  int u, l, r, id, zz;
  ask() {}
  ask(int U, int L, int R, int ID, int Z) : u(U), l(L), r(R), id(ID), zz(Z) {}
  bool operator<(const ask &A) const {
    if (u != A.u) return u < A.u;
    return id < A.id;
  }
} e[100005 << 1];
struct node {
  int id, h;
  bool operator<(const node &A) const { return h > A.h; }
} ans;
int dp[100005 << 1], g[100005];
set<node> tr[100005 << 1];
int id(int l, int r) { return (l + r) | (l != r); }
void modify(int l, int r, int x, int y, int z, node t) {
  int p(id(l, r));
  if (l == x && r == y) {
    if (z == 1)
      tr[p].insert(t);
    else
      tr[p].erase(t);
    return;
  }
  int mid((l + r) >> 1);
  if (y <= mid)
    modify(l, mid, x, y, z, t);
  else if (x > mid)
    modify(mid + 1, r, x, y, z, t);
  else {
    modify(l, mid, x, mid, z, t);
    modify(mid + 1, r, mid + 1, y, z, t);
  }
}
void calc(int l, int r, int x) {
  int p(id(l, r));
  if (!tr[p].empty()) ans = min(ans, *tr[p].begin());
  if (l == r) return;
  int mid((l + r) >> 1);
  if (x <= mid)
    calc(l, mid, x);
  else
    calc(mid + 1, r, x);
}
int calc(int x) {
  ans = (node){-1, -1};
  calc(1, w, x);
  if (ans.h == -1) return 1;
  return dp[ans.id];
}
int main() {
  scanf("%d%d%d", &h, &w, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d%d", &u, &l, &r, &s);
    e[++tot] = ask(u, l, r, 1, 0);
    if (u + s + 1 <= h + 1) ++tot, e[tot] = ask(u + s + 1, l, r, -1, e[i].u);
  }
  sort(e + 1, e + tot + 1);
  for (int i = 1; i <= tot; ++i) {
    if (e[i].id == 1) {
      if (e[i].l == 1)
        dp[i] = mul(2, calc(e[i].r + 1));
      else if (e[i].r == w)
        dp[i] = mul(2, calc(e[i].l - 1));
      else
        dp[i] = add(calc(e[i].l - 1), calc(e[i].r + 1));
      modify(1, w, e[i].l, e[i].r, 1, (node){i, e[i].u});
    }
    if (e[i].id == -1) modify(1, w, e[i].l, e[i].r, -1, (node){0, e[i].zz});
  }
  for (int i = 1; i <= w; ++i) Add(Ans, calc(i));
  Ans = (Ans % p + p) % p;
  printf("%d\n", Ans);
  return 0;
}
