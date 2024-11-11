#include <bits/stdc++.h>
using namespace std;
const int MAXN = 31;
int n, m, can[MAXN][MAXN];
vector<vector<int>> a, b;
pair<int, int> par[MAXN][MAXN];
vector<pair<int, int>> getpath(int sx, int sy, int tx, int ty) {
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    for (int j = 0, ThxDem = m; j < ThxDem; ++j) par[i][j] = {-1, -1};
  queue<pair<int, int>> q;
  q.push({sx, sy});
  par[sx][sy] = {sx, sy};
  while (int(q.size())) {
    pair<int, int> now = q.front();
    q.pop();
    for (int dx = -1, ThxDem = 2; dx < ThxDem; ++dx)
      for (int dy = -1, ThxDem = 2; dy < ThxDem; ++dy)
        if (dx || dy) {
          pair<int, int> to = {now.first + dx, now.second + dy};
          if (to.first < 0 || to.first == n || to.second < 0 || to.second == m)
            continue;
          if (par[to.first][to.second].first != -1 || !can[to.first][to.second])
            continue;
          par[to.first][to.second] = now;
          q.push(to);
        }
  }
  vector<pair<int, int>> pt;
  pair<int, int> now = {tx, ty};
  while (1) {
    pair<int, int> to = par[now.first][now.second];
    if (now == to) break;
    pt.push_back(now);
    now = to;
  }
  reverse(pt.begin(), pt.end());
  return pt;
}
void rot(vector<vector<int>> &a) {
  int n = int(a.size()), m = int(a[0].size());
  vector<vector<int>> rr(m, vector<int>(n));
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    for (int j = 0, ThxDem = m; j < ThxDem; ++j) rr[j][n - i - 1] = a[i][j];
  a = rr;
}
int mx, my;
vector<pair<int, int>> ans;
pair<int, int> getone(int x) {
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    for (int j = 0, ThxDem = m; j < ThxDem; ++j)
      if (a[i][j] == x && (i != mx || j != my)) return {i, j};
  assert(0);
}
void doit(pair<int, int> st, pair<int, int> en, pair<int, int> top) {
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    for (int j = 0, ThxDem = m; j < ThxDem; ++j)
      can[i][j] = i < top.first || (i == top.first && j <= top.second);
  can[st.first][st.second] = 0;
  auto pth = getpath(mx, my, en.first, en.second);
  pth.push_back(st);
  for (auto vv : pth) {
    swap(a[mx][my], a[vv.first][vv.second]);
    ans.push_back(vv);
    mx = vv.first;
    my = vv.second;
  }
}
void move(pair<int, int> st, pair<int, int> en,
          void f(pair<int, int>, pair<int, int>, pair<int, int>),
          int flag = 0) {
  if (flag) {
    while (st.first < en.first)
      f(st, {st.first + 1, st.second}, en), st.first++;
    while (st.first > en.first)
      f(st, {st.first - 1, st.second}, en), st.first--;
    while (st.second < en.second)
      f(st, {st.first, st.second + 1}, en), st.second++;
    while (st.second > en.second)
      f(st, {st.first, st.second - 1}, en), st.second--;
  } else {
    while (st.second < en.second)
      f(st, {st.first, st.second + 1}, en), st.second++;
    while (st.second > en.second)
      f(st, {st.first, st.second - 1}, en), st.second--;
    while (st.first < en.first)
      f(st, {st.first + 1, st.second}, en), st.first++;
    while (st.first > en.first)
      f(st, {st.first - 1, st.second}, en), st.first--;
  }
}
void base() {
  for (int wh = 0, ThxDem = m; wh < ThxDem; ++wh) {
    auto lef = a;
    ans.push_back({0, wh});
    for (int j = wh + 1, ThxDem = m; j < ThxDem; ++j) {
      swap(lef[0][j], lef[0][j - 1]);
      ans.push_back({0, j});
      if (lef == b) return;
    }
    ans.clear();
    auto rig = a;
    ans.push_back({0, wh});
    for (int j = wh - 1; j >= 0; j--) {
      swap(rig[0][j], rig[0][j + 1]);
      ans.push_back({0, j});
      if (rig == b) return;
    }
    ans.clear();
  }
  cout << "-1\n";
  exit(0);
}
pair<int, int> getone2(int x, int y) {
  for (int i = 0, ThxDem = 2; i < ThxDem; ++i)
    for (int j = 0, ThxDem = m; j < ThxDem; ++j)
      if (j < y || (j == y && i <= x)) {
        if (b[x][y] == a[i][j] && (mx != i || my != j)) return {i, j};
      }
  assert(0);
}
void doit2(pair<int, int> st, pair<int, int> en, pair<int, int> top) {
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    for (int j = 0, ThxDem = m; j < ThxDem; ++j)
      can[i][j] = j < top.second || (j == top.second && i <= top.first);
  can[st.first][st.second] = 0;
  auto pth = getpath(mx, my, en.first, en.second);
  pth.push_back(st);
  for (auto vv : pth) {
    swap(a[mx][my], a[vv.first][vv.second]);
    ans.push_back(vv);
    mx = vv.first;
    my = vv.second;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int swp = 0;
  cin >> n >> m;
  a.resize(n, vector<int>(m));
  b.resize(n, vector<int>(m));
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    for (int j = 0, ThxDem = m; j < ThxDem; ++j) cin >> a[i][j];
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    for (int j = 0, ThxDem = m; j < ThxDem; ++j) cin >> b[i][j];
  vector<int> aa, bb;
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    for (int j = 0, ThxDem = m; j < ThxDem; ++j)
      aa.push_back(a[i][j]), bb.push_back(b[i][j]);
  sort(aa.begin(), aa.end());
  sort(bb.begin(), bb.end());
  if (aa != bb) cout << "-1\n", exit(0);
  if (n > m) rot(a), rot(b), swap(n, m), swp = 1;
  if (n == 1)
    base();
  else {
    for (int i = 0, ThxDem = n; i < ThxDem; ++i)
      for (int j = 0, ThxDem = m; j < ThxDem; ++j)
        if (a[i][j] == b[0][0]) mx = i, my = j;
    ans.push_back({mx, my});
    for (int i = n - 1; i > 1; i--)
      for (int j = m - 1; j >= 0; j--) {
        pair<int, int> now = getone(b[i][j]);
        assert(now.first < i || (now.first == i && now.second <= j));
        move(now, {i, j}, doit);
      }
    for (int j = m - 1; j; j--)
      for (int i = 1; i >= 0; i--) {
        pair<int, int> now = getone2(i, j);
        move(now, {i, j}, doit2, 1);
      }
    if (mx) ans.push_back({0, 0}), swap(a[0][0], a[1][0]), mx--;
    for (int i = 0, ThxDem = n; i < ThxDem; ++i)
      for (int j = 0, ThxDem = m; j < ThxDem; ++j) assert(a[i][j] == b[i][j]);
  }
  if (swp) {
    for (int it = 0, ThxDem = 3; it < ThxDem; ++it) {
      for (int i = 0, ThxDem = int(ans.size()); i < ThxDem; ++i)
        ans[i] = {ans[i].second, n - ans[i].first - 1};
      swap(n, m);
    }
  }
  cout << int(ans.size()) - 1 << "\n";
  for (auto x : ans) cout << x.first + 1 << " " << x.second + 1 << "\n";
}
