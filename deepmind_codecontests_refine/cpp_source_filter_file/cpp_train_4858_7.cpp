#include <bits/stdc++.h>
using namespace std;
struct data {
  int x, y;
} p[100000];
set<pair<pair<int, int>, int> > cur;
vector<pair<int, int> > ve[100000];
int sx, sy, tx, ty, n, ans, id, flag, fa[100000];
int find1(int x) { return fa[x] == x ? x : find1(fa[x]); }
void mod(pair<int, int> x) {
  ++id;
  int m1, m2, flag1 = 1;
  fa[id] = id;
  for (auto it = cur.begin(); it != cur.end();) {
    if (x.first == it->first.first) {
      flag1--;
      fa[id] = fa[it->second];
      m1 = x.second;
      m2 = it->first.second;
      if (m1 >= m2) swap(m1, m2);
      x = make_pair(m1, m2);
      it = cur.erase(it);
      break;
    } else if (x.second == it->first.second) {
      flag1--;
      fa[id] = fa[it->second];
      m1 = x.first;
      m2 = it->first.first;
      if (m1 >= m2) swap(m1, m2);
      x = make_pair(m1, m2);
      it = cur.erase(it);
      break;
    } else if (x.first > it->first.first && x.second < it->first.second) {
      flag1--;
      fa[id] = fa[it->second];
      fa[id + 1] = fa[it->second];
      fa[id + 2] = fa[it->second];
      cur.insert({make_pair(it->first.first, x.first), ++id});
      cur.insert({make_pair(x.second, it->first.second), ++id});
      x = make_pair(0, 0);
      cur.erase(it);
      break;
    } else if (x.second == it->first.first) {
      if (find1(id) != find1(it->second))
        flag1--, fa[find1(id)] = find1(it->second);
      m1 = x.first;
      m2 = it->first.second;
      x = make_pair(m1, m2);
      it = cur.erase(it);
      continue;
    } else if (x.first == it->first.second) {
      if (find1(id) != find1(it->second))
        flag1--, fa[find1(id)] = find1(it->second);
      m1 = it->first.first;
      m2 = x.second;
      x = make_pair(m1, m2);
      it = cur.erase(it);
      continue;
    }
    it++;
  }
  if (flag) ans += flag1;
  if (x.first < x.second) cur.insert(make_pair(x, id));
}
int main() {
  int m1, m2;
  scanf("%d%d%d%d%d", &sx, &sy, &tx, &ty, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &p[i].x, &p[i].y);
  }
  p[n + 1] = p[1];
  swap(sy, ty);
  for (int i = 1; i <= n; i++) {
    if (p[i].x == p[i + 1].x) continue;
    m1 = max(min(p[i].x, p[i + 1].x), sx);
    m2 = min(max(p[i].x, p[i + 1].x), tx);
    if (m1 < m2) ve[p[i].y].push_back(make_pair(m1, m2));
  }
  for (int i = 0; i <= ty; i++) {
    for (auto x : ve[i]) mod(x);
    if (i == sy) ans = cur.size(), flag = 1;
  }
  printf("%d\n", ans);
}
