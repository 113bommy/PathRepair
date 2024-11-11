#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int sz;
int ans;
int n, m, t;
int a[maxn];
int b[maxn];
int c[maxn];
int kmp[maxn];
int L[50 * maxn];
int R[50 * maxn];
int seg[50 * maxn];
vector<int> roots;
vector<int> bois[maxn];
void in();
void solve();
void pers();
bool can(int, int);
int make(int, int);
int add(int, int, int, int);
int get(int, int, int, int, int);
void out();
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  in();
  solve();
  out();
}
void in() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i]--;
  }
}
void solve() {
  for (int i = 0; i < n; i++) {
    c[a[i]] = i;
    bois[i].push_back(a[i]);
  }
  for (int i = 0; i < m; i++) {
    c[b[i] + n] = i;
    bois[i].push_back(b[i] + n);
  }
  t = n + m;
  pers();
  for (int i = 2; i <= t; i++) {
    int k = kmp[i - 1];
    if (i == n + 1) k = 0;
    if (k == n) k = kmp[n];
    while (k && !can(i - 1, k)) k = kmp[k];
    kmp[i] = k + 1;
    if (kmp[i] == n) ans++;
  }
}
void pers() {
  roots.push_back(make(0, t));
  for (int i = 0; i < m; i++) {
    int r = roots.back();
    for (auto x : bois[i]) r = add(r, 0, t, x);
    roots.push_back(r);
  }
}
bool can(int x, int y) {
  int a = get(roots[c[y]], 0, t, 0, y);
  int b = get(roots[c[x]], 0, t, x - y, x);
  return a == b;
}
int get(int id, int l, int r, int s, int e) {
  if (r <= s || e <= l) return 0;
  if (s <= l && r <= e) return seg[id];
  int mid = (l + r) >> 1;
  return get(L[id], l, mid, s, e) + get(R[id], mid, r, s, e);
}
int add(int ID, int l, int r, int idx) {
  int id = sz++;
  if (r - l == 1) {
    seg[id] = 1;
    return id;
  }
  int mid = (l + r) >> 1;
  L[id] = L[ID];
  R[id] = R[ID];
  if (idx < mid)
    L[id] = add(L[ID], l, mid, idx);
  else
    R[id] = add(R[ID], mid, r, idx);
  seg[id] = seg[L[id]] + seg[R[id]];
  return id;
}
int make(int l, int r) {
  int id = sz++;
  if (r - l == 1) return id;
  int mid = (l + r) >> 1;
  L[id] = make(l, mid);
  R[id] = make(mid, r);
  return id;
}
void out() { cout << ans; }
