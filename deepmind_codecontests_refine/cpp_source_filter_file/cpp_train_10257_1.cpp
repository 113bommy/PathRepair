#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 5;
int loga[MAXN];
void add(int x, int val) {
  for (; x <= MAXN; x += (x & (-x))) {
    loga[x] += val;
  }
}
int sum(int x) {
  int ret = 0;
  for (; x > 0; x -= (x & (-x))) {
    ret += loga[x];
  }
  return ret;
}
int query(int x, int y) { return sum(y) - sum(x - 1); }
struct event {
  int x, y, tip, cnt;
  event(){};
  event(int _x, int _y, int _tip, int _cnt) {
    x = _x;
    y = _y;
    tip = _tip;
    cnt = _cnt;
  }
  friend bool operator<(const event A, const event B) {
    if (A.cnt != B.cnt) return A.cnt < B.cnt;
    return A.tip > B.tip;
  }
};
int n, m;
int l[MAXN][MAXN], r[MAXN][MAXN], dia[MAXN][MAXN];
int sol;
char a[MAXN][MAXN];
vector<event> v;
void broji() {
  sort(v.begin(), v.end());
  for (int i = (0); i < ((int)v.size()); ++i) {
    if (v[i].tip == 1)
      add(v[i].cnt, 1);
    else if (v[i].tip == 0) {
      sol += query(max(v[i].cnt - l[v[i].x][v[i].y] + 1, 1), v[i].cnt);
    } else
      add(v[i].x, -1);
  }
  v.clear();
}
void solve(int x, int y) {
  int cnt = 1;
  while (x >= 0 && y < m) {
    if (a[x][y] == 'z') {
      int nest = min(r[x][y], dia[x][y]);
      v.push_back(event(x, y, 1, cnt));
      v.push_back(event(x, y, 0, cnt));
      v.push_back(event(cnt, cnt, -1, cnt + nest - 1));
    } else {
      broji();
    }
    --x;
    ++y;
    ++cnt;
  }
  broji();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) cin >> a[i][j];
  for (int i = (0); i < (n); ++i) {
    l[i][0] = a[i][0] == 'z';
    for (int j = (1); j < (m); ++j)
      l[i][j] = a[i][j] == '.' ? 0 : l[i][j - 1] + 1;
  }
  for (int i = (0); i < (n); ++i) {
    r[i][m - 1] = a[i][m - 1] == 'z';
    for (int j = m - 2; j >= 0; --j)
      r[i][j] = a[i][j] == '.' ? 0 : r[i][j + 1] + 1;
  }
  for (int j = m - 1; j >= 0; --j) {
    for (int i = (0); i < (n); ++i) {
      if (i == 0 || j == m - 1)
        dia[i][j] = a[i][j] == 'z';
      else
        dia[i][j] = a[i][j] == 'z' ? dia[i - 1][j + 1] + 1 : 0;
    }
  }
  for (int i = (0); i < (n - 1); ++i) {
    solve(i, 0);
  }
  for (int i = (0); i < (m); ++i) {
    solve(n - 1, i);
  }
  cout << sol << endl;
}
