#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
using namespace std;
const double eps = 1E-9;
const double Exp = 2.718281828459045;
const double Pi = 3.1415926535897932;
const int NMAX = 100000 + 5;
const int MMAX = 100000 + 5;
const int INF = 1000000000;
const int BASE = 1000000007;
template <typename T>
inline T abs(const T a) {
  if (a < 0) return -a;
  return a;
}
template <typename T>
inline T sqr(const T &a) {
  return a * a;
}
pair<int, long long> t[4 * NMAX];
pair<int, long long> combine(const pair<int, long long> &a,
                             const pair<int, long long> &b) {
  if (a.second > b.second) return a;
  return b;
}
void modify(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] = combine(t[v], make_pair(pos, val));
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm)
    modify(v + v, tl, tm, pos, val);
  else
    modify(v + v + 1, tm + 1, tr, pos, val);
  t[v] = combine(t[v + v], t[v + v + 1]);
}
pair<int, long long> query(int v, int tl, int tr, int l, int r) {
  if (r < l) return make_pair(-1, -INF);
  if (l == tl && r == tr) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  if (r <= tm) return query(v + v, tl, tm, l, r);
  if (l >= tm + 1) return query(v + v + 1, tm + 1, tr, l, r);
  return combine(query(v + v, tl, tm, l, tm),
                 query(v + v + 1, tm + 1, tr, tm + 1, r));
}
int main() {
  ios::sync_with_stdio(false);
  int n, d;
  int nd;
  static long long h[NMAX];
  static long long buf[NMAX];
  int i, j;
  cin >> n >> d;
  for (i = 1; i <= n; i++) {
    cin >> h[i];
    buf[i] = h[i];
  }
  sort(buf + 1, buf + n + 1);
  nd = unique(buf + 1, buf + n + 1) - (buf + 1);
  static int from[NMAX] = {0};
  static int dp[NMAX] = {0};
  pair<int, long long> x, y;
  int l, r;
  for (i = 1; i <= n; i++) {
    l = upper_bound(buf + 1, buf + nd + 1, h[i] - d) - (buf + 1);
    r = lower_bound(buf + 1, buf + nd + 1, h[i] + d) - buf;
    x = query(1, 1, nd, 1, l);
    y = query(1, 1, nd, r, nd);
    if (-1 == x.first) x = y;
    if (-1 == x.first) {
      dp[i] = 1;
      from[i] = 0;
    } else {
      if (y.first != -1 && y.second > x.second) {
        swap(x, y);
      }
      dp[i] = x.second + 1;
      from[i] = x.first;
    }
    l = lower_bound(buf + 1, buf + nd + 1, h[i]) - buf;
    modify(1, 1, nd, l, dp[i]);
  }
  int mx = 1;
  for (i = 1; i <= n; i++) {
    if (dp[mx] < dp[i]) mx = i;
  }
  cout << dp[mx] << endl;
  stack<int> ans;
  j = mx;
  for (i = mx - 1; i > 0; i--) {
    if (h[i] == buf[from[j]]) {
      ans.push(i);
      j = i;
    }
  }
  while (!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }
  cout << mx << endl;
  return 0;
}
