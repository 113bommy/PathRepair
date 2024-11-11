#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxx = 3e5 + 10;
int n;
int l[maxn];
int r[maxn];
int v[maxn];
int lazy[4 * maxx];
pair<int, int> seg[4 * maxx];
pair<int, pair<int, int>> ans;
vector<pair<pair<pair<int, int>, int>, int>> Q;
void in();
void solve();
void doit();
void make(int id, int l, int r);
pair<int, int> get(int id, int l, int r, int L, int R);
void upd(int id, int l, int r, int L, int R, int val);
void push(int id);
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
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> v[i] >> r[i];
    r[i]++;
  }
}
bool cmp(pair<pair<pair<int, int>, int>, int> a,
         pair<pair<pair<int, int>, int>, int> b) {
  if (a.first.first.first == b.first.first.first) return a.second > b.second;
  return a.first.first.first < b.first.first.first;
}
void solve() {
  make(1, 0, maxx);
  for (int i = 0; i < n; i++) {
    Q.push_back({{{l[i], l[i]}, r[i]}, 1});
    Q.push_back({{{l[i], l[i]}, v[i]}, -1});
    Q.push_back({{{v[i] + 1, v[i] + 1}, r[i]}, -1});
    Q.push_back({{{r[i], l[i]}, r[i]}, -1});
    Q.push_back({{{v[i], l[i]}, v[i]}, 1});
    Q.push_back({{{r[i], v[i] + 1}, r[i]}, 1});
  }
  sort(Q.begin(), Q.end(), cmp);
  doit();
}
void make(int id, int l, int r) {
  seg[id] = {0, l};
  if (r - l == 1) return;
  int mid = (l + r) >> 1;
  make(id << 1, l, mid);
  make(id << 1 | 1, mid, r);
}
void doit() {
  for (int i = 0; i < Q.size(); i++) {
    auto x = Q[i];
    upd(1, 0, maxx, x.first.first.second, x.first.second, x.second);
    if (i == Q.size() - 1 ||
        x.first.first.first != Q[i + 1].first.first.first) {
      auto oof = get(1, 0, maxx, x.first.first.first, maxx);
      if (oof.first > ans.first)
        ans = {oof.first, {x.first.first.first, oof.second}};
    }
  }
}
pair<int, int> get(int id, int l, int r, int L, int R) {
  if (r <= L || R <= l) return {0, l};
  if (L <= l && r <= R) {
    return seg[id];
  }
  push(id);
  int mid = (l + r) >> 1;
  return max(get(id << 1, l, mid, L, R), get(id << 1 | 1, mid, r, L, R));
}
void upd(int id, int l, int r, int L, int R, int val) {
  if (r <= L || R <= l) return;
  if (L <= l && r <= R) {
    seg[id].first += val;
    lazy[id] += val;
    return;
  }
  push(id);
  int mid = (l + r) >> 1;
  upd(id << 1, l, mid, L, R, val);
  upd(id << 1 | 1, mid, r, L, R, val);
  seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
void push(int id) {
  seg[id << 1].first += lazy[id];
  seg[id << 1 | 1].first += lazy[id];
  lazy[id << 1] += lazy[id];
  lazy[id << 1 | 1] += lazy[id];
  lazy[id] = 0;
}
void out() {
  cout << ans.first << '\n';
  for (int i = 0; i < n; i++)
    if (l[i] <= ans.second.first && ans.second.second < r[i] &&
        ans.second.first <= v[i] && v[i] <= ans.second.second)
      cout << i + 1 << ' ';
}
