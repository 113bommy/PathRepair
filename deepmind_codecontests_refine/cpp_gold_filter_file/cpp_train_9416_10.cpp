#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF32 = INT_MAX;
const ll INF64 = ((ll)INF32 << 29ll);
void reflex() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
}
vector<int> a, tag;
vector<pii> mn;
void push(int u, int l, int r) {
  if (r - l == 1 || !tag[u]) return;
  mn[u + u + 1].first += tag[u];
  mn[u + u + 2].first += tag[u];
  tag[u + u + 1] += tag[u];
  tag[u + u + 2] += tag[u];
  tag[u] = 0;
}
void build(int u = 0, int l = 0, int r = a.size()) {
  if (r - l == 1) {
    mn[u] = {a[l], l};
    return;
  }
  int m = (l + r) >> 1;
  build(u + u + 1, l, m);
  build(u + u + 2, m, r);
  if (mn[u + u + 1].first <= mn[u + u + 2].first)
    mn[u] = mn[u + u + 1];
  else
    mn[u] = mn[u + u + 2];
}
void modify(int l, int r, int u = 0, int ul = 0, int ur = a.size()) {
  if (ul >= r || l >= ur) return;
  push(u, ul, ur);
  if (l <= ul && ur <= r) {
    mn[u].first++;
    tag[u]++;
    return;
  }
  int um = (ul + ur) >> 1;
  modify(l, r, u + u + 1, ul, um);
  modify(l, r, u + u + 2, um, ur);
  if (mn[u + u + 1].first <= mn[u + u + 2].first)
    mn[u] = mn[u + u + 1];
  else
    mn[u] = mn[u + u + 2];
}
signed main() {
  reflex();
  int n, m, w;
  cin >> n >> m >> w;
  a.resize(n);
  for (int& x : a) cin >> x;
  mn.resize(n << 2);
  tag.resize(n << 2);
  build();
  while (m--) {
    int pos = mn[0].second;
    if (pos + w > n) pos = n - w;
    modify(pos, pos + w);
  }
  cout << mn[0].first;
  return false;
}
