#include <bits/stdc++.h>
using namespace std;
struct cell {
  int x, y, w, z;
};
const int NMAX = 200005;
int n, m, k, q;
bool sol[NMAX];
pair<int, int> a[NMAX];
cell b[NMAX];
vector<int> v[NMAX];
vector<int> p[NMAX];
vector<int>::iterator it;
int aint[4 * NMAX];
inline void Update(int nod, int st, int dr, int poz, int val) {
  if (st == dr)
    aint[nod] = val;
  else {
    int mij = (st + dr) >> 1;
    if (poz <= mij) Update(2 * nod, st, mij, poz, val);
    if (poz > mij) Update(2 * nod + 1, mij + 1, dr, poz, val);
    aint[nod] = min(aint[2 * nod], aint[2 * nod + 1]);
  }
}
inline int Query(int nod, int st, int dr, int c, int d) {
  if (c <= st && dr <= d)
    return aint[nod];
  else {
    int mij = (st + dr) >> 1, rez = 1 << 30;
    if (c <= mij) rez = min(rez, Query(2 * nod, st, mij, c, d));
    if (d > mij) rez = min(rez, Query(2 * nod + 1, mij + 1, dr, c, d));
    return rez;
  }
}
int main() {
  int i, aux;
  cin.sync_with_stdio(false);
  cin >> n >> m >> k >> q;
  swap(n, m);
  for (i = 1; i <= k; i++) cin >> a[i].second >> a[i].first;
  for (i = 1; i <= q; i++) cin >> b[i].y >> b[i].x >> b[i].z >> b[i].w;
  for (i = 1; i <= k; i++) p[a[i].second].push_back(a[i].first);
  for (i = 1; i <= q; i++) v[b[i].z].push_back(i);
  for (i = 1; i <= n; i++) Update(1, 1, n, i, 0);
  for (i = 1; i <= m; i++) {
    for (it = p[i].begin(); it != p[i].end(); it++) Update(1, 1, n, *it, i);
    for (it = v[i].begin(); it != v[i].end(); it++) {
      aux = Query(1, 1, n, b[*it].x, b[*it].w);
      if (aux >= b[*it].y) sol[*it] = 1;
    }
  }
  for (i = 1; i <= m; i++) {
    p[i].clear();
    v[i].clear();
  }
  for (i = 1; i <= k; i++) p[a[i].first].push_back(a[i].second);
  for (i = 1; i <= q; i++) v[b[i].w].push_back(i);
  for (i = 1; i <= m; i++) Update(1, 1, n, i, 0);
  for (i = 1; i <= n; i++) {
    for (it = p[i].begin(); it != p[i].end(); it++) Update(1, 1, m, *it, i);
    for (it = v[i].begin(); it != v[i].end(); it++) {
      aux = Query(1, 1, m, b[*it].y, b[*it].z);
      if (aux >= b[*it].x) sol[*it] = 1;
    }
  }
  for (i = 1; i <= q; i++)
    if (sol[i] == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  return 0;
}
