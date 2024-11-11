#include <bits/stdc++.h>
using namespace std;
long long inf = 2000000000LL * 200000000LL;
struct Union {
  int n;
  short int c[205], rank[205];
};
void init(Union &u, int n) {
  u.n = n;
  for (int v = 0; v < n; v++) {
    u.c[v] = v;
    u.rank[v] = 0;
  }
}
int find(Union &u, int x) {
  if (u.c[x] == x) return x;
  return (u.c[x] = find(u, u.c[x]));
};
bool same(Union &u, int x, int y) { return find(u, x) == find(u, y); }
bool connected(Union &u) {
  for (int v = 0; v < u.n; v++)
    if (!same(u, 0, v)) return false;
  return true;
}
void unite(Union &u, int x, int y) {
  int cx = find(u, x);
  int cy = find(u, y);
  if (u.rank[cx] < u.rank[cy])
    u.c[cx] = cy;
  else if (u.rank[cx] > u.rank[cy])
    u.c[cy] = cx;
  else {
    u.c[cy] = cx;
    u.rank[cx]++;
  }
};
void unite(Union &u1, Union &u2) {
  for (int v = 0; v < u1.n; v++) {
    unite(u1, find(u1, v), find(u2, v));
  }
}
int n, m;
long long costGold, costSilver;
vector<pair<pair<long long, long long>, pair<int, int> > > e;
map<long long, int> us;
vector<Union> unions;
bool mycomp(int i1, int i2) {
  pair<pair<long long, long long>, pair<int, int> > e1 = e[i1], e2 = e[i2];
  long long s1 = e1.second.second, s2 = e2.second.second;
  return (s1 < s2 || (s1 == s2 && e1.first < e2.first));
}
int main() {
  cin >> n >> m >> costGold >> costSilver;
  for (int i = 0; i < m; i++) {
    int u, v;
    long long g, s;
    cin >> u >> v >> g >> s;
    u--;
    v--;
    e.push_back(pair<pair<long long, long long>, pair<int, int> >(
        pair<long long, long long>(g, s), pair<int, int>(u, v)));
  }
  sort(e.begin(), e.end());
  long long bestCost = inf;
  for (int ie = 0; ie < e.size(); ie++) {
    pair<pair<long long, long long>, pair<int, int> > edge = e[ie];
    long long g = edge.first.first, s = edge.first.second;
    int u = edge.second.first, v = edge.second.second;
    if (u == v) continue;
    map<long long, int>::iterator ip = us.upper_bound(s);
    Union un;
    if (ip == us.begin()) {
      init(un, n);
      unite(un, u, v);
      us[s] = unions.size();
      unions.push_back(un);
    } else {
      ip--;
      if (ip->first == s)
        unite(unions[ip->second], u, v);
      else {
        us[s] = unions.size();
        un = unions[ip->second];
        unite(un, u, v);
        unions.push_back(un);
      }
    }
    if (connected(unions[us[s]]))
      bestCost = ((bestCost) < (costGold * g + costSilver * s)
                      ? (bestCost)
                      : (costGold * g + costSilver * s));
    for (ip = us.upper_bound(s); ip != us.end(); ip++) {
      if (same(unions[ip->second], u, v)) break;
      unite(unions[ip->second], u, v);
      if (connected(unions[ip->second]))
        bestCost = ((bestCost) < (costGold * g + costSilver * ip->first)
                        ? (bestCost)
                        : (costGold * g + costSilver * ip->first));
    }
  }
  if (bestCost == inf) bestCost = -1;
  cout << bestCost << endl;
  int n;
  cin >> n;
  return 0;
}
