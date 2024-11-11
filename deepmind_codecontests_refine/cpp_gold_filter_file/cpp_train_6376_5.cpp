#include <bits/stdc++.h>
using namespace std;
struct FAU {
  vector<int> p;
  vector<int> r;
  FAU(int n) {
    p.resize(n, -1);
    r.resize(n, 0);
  }
  int Find(int x) {
    if (p[x] == -1) return x;
    p[x] = Find(p[x]);
    return p[x];
  }
  bool Together(int x, int y) { return (Find(x) == Find(y)); }
  void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    if (r[x] > r[y])
      p[y] = x;
    else
      p[x] = y;
    if (r[x] == r[y]) ++r[y];
    return;
  }
};
int Mx[] = {-1, 0, 1, 0}, My[] = {0, 1, 0, -1};
int MDx[] = {-1, 0, 1, 0, -1, 1, -1, 1}, MDy[] = {0, 1, 0, -1, -1, -1, 1, 1};
bool inside(int ni, int nj, int n, int m) {
  return (ni >= 0 && ni < n && nj >= 0 && nj < m);
}
int solve(int n, int m, vector<pair<int, int> > &C, vector<vector<bool> > &T) {
  for (int i = (0); i <= ((int)(C).size() - 1); ++i)
    if (C[i].first == 0 || C[i].first == n - 1 || C[i].second == 0 ||
        C[i].second == m - 1)
      return 0;
  set<pair<int, int> > ones;
  for (int it = (0); it <= ((int)(C).size() - 1); ++it)
    for (int mv = (0); mv <= (7); ++mv) {
      int ni = C[it].first + MDx[mv], nj = C[it].second + MDy[mv];
      if (inside(ni, nj, n, m) && T[ni][nj]) ones.insert(make_pair(ni, nj));
    }
  int o = (int)(ones).size();
  vector<vector<int> > G(o);
  vector<pair<int, int> > O;
  for (pair<int, int> pt : ones) O.push_back(pt);
  sort(O.begin(), O.end());
  for (int i = (0); i <= ((int)(O).size() - 1); ++i)
    for (int mv = (0); mv <= (3); ++mv) {
      pair<int, int> pt = O[i];
      int ni = pt.first + Mx[mv], nj = pt.second + My[mv];
      if (ones.count(make_pair(ni, nj)))
        G[i].push_back(lower_bound(O.begin(), O.end(), make_pair(ni, nj)) -
                       O.begin());
    }
  for (int i = (0); i <= ((int)(G).size() - 1); ++i)
    if ((int)(G[i]).size() != 2) return 0;
  FAU dsu((int)(G).size());
  for (int i = (0); i <= ((int)(G).size() - 1); ++i)
    for (int j = (0); j <= ((int)(G[i]).size() - 1); ++j) dsu.Union(i, G[i][j]);
  for (int i = (0); i <= ((int)(G).size() - 1); ++i)
    if (!dsu.Together(0, i)) return 0;
  return (int)(G).size();
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<bool> > T(n);
  for (int i = (0); i <= ((int)(T).size() - 1); ++i) T[i].resize(m);
  int one = 0, zero;
  for (int i = (0); i <= (n - 1); ++i)
    for (int j = (0); j <= (m - 1); ++j) {
      char c;
      cin >> c;
      T[i][j] = (c == '1');
      if (T[i][j])
        one++;
      else
        zero++;
    }
  FAU F(n * m);
  for (int i = (0); i <= (n - 1); ++i)
    for (int j = (0); j <= (m - 1); ++j)
      for (int mv = (0); mv <= (7); ++mv) {
        int ni = i + MDx[mv], nj = j + MDy[mv];
        if (inside(ni, nj, n, m) && (T[ni][nj] == T[i][j]))
          F.Union(i + n * j, ni + n * nj);
      }
  vector<vector<pair<int, int> > > Comp(n * m);
  for (int i = (0); i <= (n - 1); ++i)
    for (int j = (0); j <= (m - 1); ++j)
      if (!T[i][j]) Comp[F.Find(i + n * j)].push_back(make_pair(i, j));
  int best = 0;
  for (int i = (0); i <= ((int)(Comp).size() - 1); ++i)
    if (!Comp[i].empty()) {
      int here = solve(n, m, Comp[i], T);
      best = max(best, here);
    }
  for (int i = (0); i <= (n - 2); ++i)
    for (int j = (0); j <= (m - 2); ++j)
      if (T[i][j] && T[i + 1][j] && T[i][j + 1] && T[i + 1][j + 1])
        best = max(best, 4);
  cout << best;
  return 0;
}
