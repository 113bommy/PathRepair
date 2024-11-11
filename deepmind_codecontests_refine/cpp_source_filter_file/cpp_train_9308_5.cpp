#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
const long long int INF = 2e9;
void init(vector<int> &dsu) {
  for (int i = 0; i < ((int)(dsu).size()); i++) {
    dsu[i] = i;
  }
}
int find_p(vector<int> &dsu, int id) {
  if (dsu[id] == id) return id;
  return dsu[id] = find_p(dsu, dsu[id]);
}
bool unite(vector<int> &dsu, int f, int s) {
  f = find_p(dsu, f);
  s = find_p(dsu, s);
  if (f == s) return true;
  dsu[f] = s;
  return false;
}
inline bool in(long double f, long double s, long double d) {
  return s >= f && s <= d;
}
bool intr(pair<long double, long double> f, pair<long double, long double> s,
          long double time) {
  if (time == INF) return true;
  long double a1 = -1, b1 = -1, c1 = -(a1 * f.first + b1 * f.second);
  long double a2 = 1, b2 = -1, c2 = -(a2 * s.first + b2 * s.second);
  long double x = (b1 * c2 - b2 * c1) / (a1 * b2 - b1 * a2),
              y = (c1 * a2 - a1 * c2) / (a1 * b2 - b1 * a2);
  return in(f.first - time, x, f.first + time) &&
         in(f.second - time, y, f.second + time) &&
         in(s.first - time, x, s.first + time) &&
         in(s.second - time, y, s.second + time);
}
bool ini(long double f, long double s, long double time) {
  return (f - s) <= time * 2;
}
bool intr2(pair<long double, long double> f, pair<long double, long double> s,
           int q, long double time) {
  if (!q && !(f.first + f.second == s.first + s.second)) return false;
  if (q && !(f.first - f.second == s.first - s.second)) return false;
  if (time == INF) return true;
  long double x = min(f.first, s.first), x2 = max(f.first, s.first);
  long double y = min(f.second, s.second), y2 = max(f.second, s.second);
  return ini(x, x2, time) && ini(y, y2, time);
}
bool can(vector<pair<long double, long double> > p1,
         vector<pair<long double, long double> > p2, long long int time) {
  int n = (int)(p1).size(), m = (int)(p2).size();
  for (int q = 0; q < (2); q++) {
    vector<int> with(n, -1);
    vector<int> dsu(m);
    init(dsu);
    for (int i = 0; i < (n); i++) {
      for (int j = 0; j < (m); j++) {
        if (intr(!q ? p1[i] : p2[j], !q ? p2[j] : p1[i], time)) {
          if (with[i] == -1)
            with[i] = j;
          else {
            if (unite(dsu, j, with[i])) {
              return true;
            }
          }
        }
      }
      for (int j = 0; j < (i); j++) {
        if (i == j) continue;
        if (with[j] == -1 || with[i] == -1) continue;
        if (intr2(p1[i], p1[j], q, time)) {
          if (unite(dsu, with[i], with[j])) {
            return true;
          }
        }
      }
    }
    swap(n, m);
    swap(p1, p2);
  }
  return false;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<long double, long double> > p1(n), p2(m);
  bool yes = false;
  for (int i = 0; i < (n); i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    p1[i] = make_pair(a, b);
    if (i && a + b != p1[i - 1].first + p1[i - 1].second) yes = true;
  }
  bool yes2 = false;
  for (int i = 0; i < (m); i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    p2[i] = make_pair(a, b);
    if (i && a - b != p2[i - 1].first - p2[i - 1].second) yes2 = true;
  }
  if ((!yes && !yes2) || !can(p1, p2, INF)) {
    cout << "Poor Sereja!";
    return 0;
  }
  long long int l = 0, r = INF;
  while (l != r) {
    long long int m = (l + r) / 2;
    if (can(p1, p2, m)) {
      r = m;
    } else
      l = m + 1;
  }
  cout << l;
}
