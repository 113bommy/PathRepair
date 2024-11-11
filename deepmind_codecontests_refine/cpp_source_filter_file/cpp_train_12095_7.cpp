#include <bits/stdc++.h>
using namespace std;
default_random_engine gen(42);
uniform_real_distribution<double> ran(0, 1);
void vin(std::vector<int> &a) {
  for (auto &x : a) cin >> x;
}
void vout(std::vector<int> &a) {
  for (auto x : a) cout << x << " ";
  cout << endl;
}
bool vm(array<pair<int, int>, 2> m) {
  if (abs(m[0].first - m[1].first) + abs(m[0].second - m[1].second) != 3)
    return 0;
  if (m[0].first == m[1].first || m[0].second == m[1].second) return 0;
  return 1;
}
pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
  return {a.first + b.first, a.second + b.second};
}
std::vector<pair<int, int> > mo{{1, 2},   {2, 1},   {2, -1}, {1, -2},
                                {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
array<std::vector<std::vector<int> >, 2> dp;
int n, m;
void initdp() {
  for (int qw = 0; qw < 2; qw++) {
    dp[qw].resize(n, std::vector<int>(m, -1));
    priority_queue<tuple<int, int, int>, std::vector<tuple<int, int, int> >,
                   greater<tuple<int, int, int> > >
        pq;
    pq.emplace(make_tuple(0, n / 2 - 1 + qw, m / 2 - 1));
    while (!pq.empty()) {
      int x, y, d;
      tie(d, x, y) = pq.top();
      pq.pop();
      if (dp[qw][x][y] != -1) continue;
      dp[qw][x][y] = d;
      for (auto move : mo) {
        pair<int, int> t = move + make_pair(x, y);
        if (t.first >= 0 && t.first < n && t.second >= 0 && t.second < m &&
            dp[qw][t.first][t.second] == -1)
          pq.emplace(make_tuple(d + 1, t.first, t.second));
      }
    }
  }
}
int dist(pair<int, int> b, bool t) { return dp[t][b.first][b.second]; }
int end(array<pair<int, int>, 2> a, bool t) {
  if (vm(a)) return t;
  if (a[0].first == n / 2 - 1 && a[0].second == m / 2 - 1) return 0;
  if (a[1] == make_pair(n / 2, m / 2 - 1)) return 1;
  return -1;
}
pair<int, int> w;
double rek(array<pair<int, int>, 2> a, bool t, int rd = 5, double mx = INT_MAX,
           double mn = INT_MIN) {
  pair<int, int> mw = {0, 0};
  if (end(a, t) != -1)
    return ((end(a, t) ? 1000 : -1000) + ran(gen) * .001) * pow(1.01, rd);
  if (rd == 0) {
    double d[2][2];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) d[i][j] = dist(a[i], j);
    d[t][0] -= .5;
    d[t][1] -= .5;
    return (d[0][0] - d[1][1] + (d[0][1] - d[1][0]) * .1 + ran(gen) * .001) *
           pow(1.01, rd);
  }
  double rt = t ? -100000 : 100000;
  priority_queue<array<pair<int, int>, 2>,
                 std::vector<array<pair<int, int>, 2> >,
                 greater<array<pair<int, int>, 2> > >
      pq;
  for (auto x : mo) {
    pair<int, int> c = a[t] + x;
    if (c.first >= 0 && c.first < n && c.second >= 0 && c.second < m)
      pq.emplace(array<pair<int, int>, 2>{
          make_pair(dp[t][c.first][c.second], dp[!t][c.first][c.second]), c});
  }
  assert(!pq.empty());
  while (!pq.empty()) {
    array<pair<int, int>, 2> n = a;
    n[t] = pq.top()[1];
    pq.pop();
    double r = rek(n, !t, rd - 1, mx, mn);
    if ((t && r > rt) || (!t && r < rt)) {
      rt = r;
      mw = n[t];
    }
    if ((t && rt > mx) || (!t && rt < mn)) break;
    if (t)
      mn = max(mn, rt);
    else
      mx = min(mx, rt);
  }
  w = mw;
  return rt;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  initdp();
  int xWI, yWI, xBL, yBL;
  cin >> xWI >> yWI >> xBL >> yBL;
  xWI--;
  yWI--;
  xBL--;
  yBL--;
  array<pair<int, int>, 2> a = {make_pair(xWI, yWI), make_pair(xBL, yBL)};
  if (vm(a)) {
    cout << "WHITE\n" << xBL + 1 << " " << yBL + 1 << "\n";
    return 0;
  }
  double r = rek(a, 0);
  int me;
  if (fabs(r) > 500)
    me = r > 0;
  else {
    int fr = ((xWI + yWI + xBL + yBL) % 2);
    int df = dp[fr][a[fr].first][a[fr].second],
        da = dp[fr][a[!fr].first][a[!fr].second];
    cerr << df << " " << da << "\n";
    if (df + 1 + fr <= da)
      me = fr;
    else
      me = !fr;
  }
  cout << (me ? "BLACK" : "WHITE") << endl;
  int t = 0;
  while (true) {
    if (t == me) {
      rek(a, t);
      cout << w.first + 1 << " " << w.second + 1 << endl;
      if (w == a[!t]) return 0;
      if (!vm(a) && w == make_pair(n / 2 - 1 + t, m / 2 - 1)) return 0;
    } else {
      cin >> w.first >> w.second;
      w.first--;
      w.second--;
    }
    a[t] = w;
    t = !t;
  }
}
