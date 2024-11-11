#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 300005;
pair<int, int> st[4 * N];
int lz[4 * N];
void prop(int p, int L, int R) {
  if (lz[p]) {
    st[p].first += lz[p];
    if (L < R) {
      lz[2 * p] += lz[p];
      lz[2 * p + 1] += lz[p];
    }
    lz[p] = 0;
  }
}
pair<int, int> comb(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first < b.first) return a;
  if (b.first < a.first) return b;
  return {a.first, a.second + b.second};
}
void upd(int p, int L, int R, int i, int j, int val) {
  prop(p, L, R);
  if (i > R or j < L) return;
  if (L >= i and R <= j) {
    lz[p] = val;
    prop(p, L, R);
    return;
  }
  int mid = (L + R) / 2;
  upd(2 * p, L, mid, i, j, val);
  upd(2 * p + 1, mid + 1, R, i, j, val);
  st[p] = comb(st[2 * p], st[2 * p + 1]);
}
pair<int, int> query(int p, int L, int R, int i, int j) {
  prop(p, L, R);
  if (i > R or j < L) return make_pair(int(1e9), 0);
  if (L >= i and R <= j) return st[p];
  int mid = (L + R) / 2;
  return comb(query(2 * p, L, mid, i, j), query(2 * p + 1, mid + 1, R, i, j));
}
void build(int p, int L, int R) {
  if (L == R) {
    st[p] = {-L, 1};
    return;
  }
  int mid = (L + R) / 2;
  build(2 * p, L, mid);
  build(2 * p + 1, mid + 1, R);
  st[p] = comb(st[2 * p], st[2 * p + 1]);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  {
    vector<pair<int, int>> tmp(n);
    for (auto &p : tmp) scanf("%d %d", &p.first, &p.second);
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++) a[i] = tmp[i].second;
  }
  build(1, 0, n - 1);
  vector<int> rigmn(n), rigmx(n);
  stack<int> smx, smn;
  ll ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    while (!smx.empty() and a[smx.top()] < a[i]) {
      int id = smx.top();
      smx.pop();
      int nx = smx.empty() ? n - 1 : smx.top() - 1;
      upd(1, 0, n - 1, id, nx, -a[id]);
    }
    while (!smn.empty() and a[smn.top()] > a[i]) {
      int id = smn.top();
      smn.pop();
      int nx = smn.empty() ? n - 1 : smn.top() - 1;
      upd(1, 0, n - 1, id, nx, a[id]);
    }
    rigmn[i] = smn.empty() ? n - 1 : smn.top() - 1;
    rigmx[i] = smx.empty() ? n - 1 : smx.top() - 1;
    smx.push(i);
    smn.push(i);
    upd(1, 0, n - 1, i, rigmn[i], -a[i]);
    upd(1, 0, n - 1, i, rigmx[i], a[i]);
    auto tmp = query(1, 0, n - 1, i, n - 1);
    if (tmp.first == -i) {
      ans += tmp.second;
    }
  }
  printf("%lld\n", ans);
}
