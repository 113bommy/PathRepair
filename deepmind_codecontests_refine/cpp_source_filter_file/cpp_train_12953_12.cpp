#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 10;
struct point {
  int x, y, isabre, id;
};
bool cmp(point a, point b) {
  if (a.x == b.x) return a.x < b.x;
  return a.isabre < b.isabre;
}
vector<point> v;
set<pair<int, int> > s;
struct inter {
  int hori;
  int ini, fim, pos;
} inters[2 * MAXN];
int n;
bool teste(int k) {
  for (int i = 1; i <= n; i++) {
    inters[i].ini += k;
    inters[i].fim -= k;
    if (inters[i].ini <= inters[i].fim) {
      if (inters[i].hori) {
        v.push_back({inters[i].ini, inters[i].pos, 0, i});
        v.push_back({inters[i].fim, inters[i].pos, 2, i});
      } else {
        v.push_back({inters[i].pos, inters[i].ini, 1, i});
      }
    }
  }
  sort(v.begin(), v.end(), cmp);
  bool ans = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].isabre == 0)
      s.insert({v[i].y, v[i].id});
    else if (v[i].isabre == 2)
      s.erase({v[i].y, v[i].id});
    else {
      set<pair<int, int> >::iterator it = s.lower_bound({v[i].y, 0});
      if (it == s.end()) continue;
      if (it->first <= inters[v[i].id].fim) ans = 1;
    }
  }
  v.clear();
  s.clear();
  for (int i = 1; i <= n; i++) {
    inters[i].ini -= k;
    inters[i].fim += k;
  }
  return ans;
}
int m;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int l;
    scanf("%d %d %d", &inters[i].pos, &inters[i].ini, &l);
    inters[i].fim = inters[i].ini + l;
  }
  for (int i = n + 1; i <= m + n; i++) {
    int l;
    scanf("%d %d %d", &inters[i].ini, &inters[i].pos, &l);
    inters[i].hori = 1;
    inters[i].fim = inters[i].ini + l;
  }
  n = m + n;
  int ini = 1, fim = 100000000;
  if (!teste(ini)) {
    printf("%d\n", 0);
    return 0;
  }
  while (ini < fim) {
    int mid = (ini + fim) / 2;
    if (ini == fim - 1) mid = fim;
    if (teste(mid))
      ini = mid;
    else
      fim = mid - 1;
  }
  printf("%d\n", ini);
}
