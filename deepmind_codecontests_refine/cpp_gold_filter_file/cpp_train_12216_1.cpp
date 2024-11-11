#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
inline bool eq(double a, double b) { return abs(a - b) < eps; }
inline bool ls(double a, double b) { return a <= b - eps; }
inline bool gt(double a, double b) { return a >= b + eps; }
inline bool le(double a, double b) { return a < b + eps; }
inline bool ge(double a, double b) { return a > b - eps; }
inline bool zr(double lhs) { return fabs(lhs) < eps; }
inline bool nz(double lhs) { return fabs(lhs) >= eps; }
inline bool ps(double lhs) { return lhs >= eps; }
inline bool nn(double lhs) { return lhs >= -eps; }
inline bool ng(double lhs) { return lhs < -eps; }
inline bool np(double lhs) { return lhs < eps; }
const int MAX = 1000 + 20;
int a, b, ax, ay, bx, by;
int n;
struct point {
  int x, y;
  point(int a = 0, int b = 0) : x(a), y(b) {}
};
struct hg {
  int x1, y1, x2, y2;
  point ps[2];
  hg(int a = 0, int b = 0, int c = 0, int d = 0) : x1(a), y1(b), x2(c), y2(d) {}
  int length() {
    if (x1 == x2)
      return abs(y1 - y2);
    else
      return abs(x1 - x2);
  }
  void rr() { scanf("%d%d%d%d", &x1, &y1, &x2, &y2); }
  void ini() {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    ps[0] = point(x1, y1), ps[1] = point(x2, y2);
  }
};
double shortCost[MAX];
vector<pair<int, double> > adj[MAX];
int flags[MAX];
void dijst(vector<pair<int, double> > adj[], double shortCost[], int n,
           int source) {
  memset(flags, 0, sizeof(flags));
  set<pair<double, int> > lowest;
  set<pair<double, int> >::iterator ite;
  for (int i = (1); i <= (n); ++i) {
    if (i == source)
      lowest.insert(make_pair(0, i)), shortCost[i] = 0;
    else
      lowest.insert(make_pair(DBL_MAX, i)), shortCost[i] = DBL_MAX;
  }
  while (lowest.size() != 0) {
    ite = lowest.begin();
    if (ite->first == DBL_MAX) break;
    int v = ite->second;
    double shv = ite->first;
    flags[v] = 1;
    lowest.erase(ite);
    for (int j = (0); j <= ((int)adj[v].size() - 1); ++j) {
      int u = adj[v][j].first;
      double cost = adj[v][j].second;
      if (flags[u] == 0) {
        if (shv + cost < shortCost[u]) {
          lowest.erase(make_pair(shortCost[u], u));
          lowest.insert(make_pair(shv + cost, u));
          shortCost[u] = shv + cost;
        }
      }
    }
  }
}
hg hs[MAX];
inline double dist(const point &a, const point &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double getCost(int i, int j) {
  double ret = DBL_MAX;
  for (int h1 = (0); h1 <= (1); ++h1) {
    for (int h2 = (0); h2 <= (1); ++h2) {
      double dd = dist(hs[i].ps[h1], hs[j].ps[h2]);
      ret = min(ret, dd);
    }
  }
  bool dir1 = hs[i].x1 == hs[i].x2, dir2 = hs[j].x1 == hs[j].x2;
  if (dir1 == dir2) {
    if (dir1 == 1) {
      if (max(hs[i].y1, hs[j].y1) <= min(hs[i].y2, hs[j].y2)) {
        ret = min(ret, (double)abs(hs[i].x1 - hs[j].x1));
      }
    } else {
      if (max(hs[i].x1, hs[j].x1) <= min(hs[i].x2, hs[j].x2)) {
        ret = min(ret, (double)abs(hs[i].y1 - hs[j].y1));
      }
    }
  } else {
    if (dir1 == 0) swap(i, j);
    if (hs[j].y1 >= hs[i].y1 && hs[j].y1 <= hs[i].y2) {
      ret = min(ret, min((double)abs(hs[j].x1 - hs[i].x1),
                         (double)abs(hs[j].x2 - hs[i].x1)));
    }
    if (hs[i].x1 >= hs[j].x1 && hs[i].x1 <= hs[j].x2) {
      ret = min(ret, min((double)abs(hs[j].y1 - hs[i].y1),
                         (double)abs(hs[j].y1 - hs[i].y2)));
    }
  }
  return ret;
}
void add(int a, int b, double c) { adj[a].push_back({b, c}); }
int main() {
  scanf("%d%d%d%d%d%d", &a, &b, &ax, &ay, &bx, &by);
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) {
    hs[i + 1].rr();
  }
  hs[1] = hg(ax, ay, ax, ay), hs[n + 2] = hg(bx, by, bx, by);
  for (int i = (1); i <= (n + 2); ++i) hs[i].length(), hs[i].ini();
  for (int i = (1); i <= (n + 1); ++i) {
    for (int j = (1); j <= (n + 2); ++j) {
      if (i == j) continue;
      double cost = getCost(i, j);
      if (le(cost, a)) {
        if (i != n + 2 && j != n + 2) {
          add(i, j, a + b);
        } else {
          add(i, j, cost);
        }
      }
    }
  }
  dijst(adj, shortCost, n + 2, 1);
  if (shortCost[n + 2] == DBL_MAX)
    printf("%d\n", -1);
  else
    printf("%.9lf\n", shortCost[n + 2]);
  return 0;
}
