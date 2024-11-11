#include <bits/stdc++.h>
int adev, k, n;
struct tip {
  int a, b, c;
  inline bool operator<(const tip &u) const {
    if (a != u.a)
      return a < u.a;
    else if (b != u.b)
      return b < u.b;
    else
      return c < u.c;
  }
} t[100000 + 1];
struct myc {
  int x, y;
  myc(int _x, int _y) {
    x = _x;
    y = _y;
  }
};
std::vector<bool> viz[100000 + 1];
std::map<int, int> mp[100000 + 1];
std::vector<myc> g[100000 + 1];
std::vector<int> v[100000 + 1], u;
int e[100000 + 1], s[100000 + 1];
int ind[100000 + 1], cul[100000 + 1];
inline int urm(int a) {
  if (a == n)
    return 1;
  else
    return a + 1;
}
inline int dist(int a, int b) {
  if (b - a <= 0)
    return b - a + n;
  else
    return b - a;
}
bool cmp1(const myc &a, const myc &b) {
  return dist(adev, a.x) < dist(adev, b.x);
}
bool cmp2(const int &a, const int &b) { return t[a] < t[b]; }
inline void baga(int x, int k) {
  if (e[x]) {
    v[k].push_back(e[x]);
    v[e[x]].push_back(k);
  } else
    e[x] = k;
}
void dfs1(int x, int t) {
  u.push_back(x);
  s[x] = 1;
  for (auto y : v[x]) {
    if (t != y) {
      dfs1(y, x);
      s[x] += s[y];
    }
  }
}
void centroid(int x, int c) {
  if (v[x].size() == 0)
    cul[x] = c;
  else {
    u.clear();
    dfs1(x, 0);
    int q;
    for (auto y : u) {
      if (2 * (u.size() - s[y]) <= u.size()) {
        bool f = 1;
        for (auto z : v[y])
          if (s[z] < s[y])
            if (2 * s[z] > (int)u.size()) f = 0;
        if (f) q = y;
      }
    }
    cul[q] = c;
    for (auto y : v[q]) {
      int p = 0;
      for (int j = 1; j < (int)v[y].size(); j++)
        if (v[y][j] == q) p = j;
      std::swap(v[y][p], v[y][v[y].size() - 1]);
      v[y].pop_back();
      centroid(y, c + 1);
    }
  }
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(myc(y, i));
    g[y].push_back(myc(x, i));
  }
  for (int i = 1; i <= n; i++) {
    adev = i;
    g[i].push_back(myc(urm(i), 0));
    std::sort(g[i].begin(), g[i].end(), cmp1);
    for (int j = 0; j < (int)g[i].size(); j++) viz[i].push_back(0);
    for (int j = 0; j < (int)g[i].size(); j++) mp[i][g[i][j].x] = j;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)g[i].size(); j++)
      if (viz[i][j] == 0) {
        viz[i][j] = 1;
        k++;
        int x = i;
        myc y = g[i][j];
        t[k].a = i;
        t[k].b = 0;
        t[k].c = 0;
        ind[k] = k;
        if (g[i][j].y) baga(g[i][j].y, k);
        while (y.x != i) {
          if (y.x > t[k].a) {
            t[k].c = t[k].b;
            t[k].b = t[k].a;
            t[k].a = y.x;
          } else if (y.x > t[k].b) {
            t[k].c = t[k].b;
            t[k].b = y.x;
          } else if (y.x > t[k].c)
            t[k].c = y.x;
          int poz = mp[y.x][x];
          poz--;
          if (poz == -1) poz = g[y.x].size() - 1;
          viz[y.x][poz] = 1;
          x = y.x;
          y = g[x][poz];
          if (y.y) baga(y.y, k);
        }
      }
  }
  centroid(1, 1);
  std::sort(ind + 1, ind + k + 1, cmp2);
  for (int i = 1; i < k; i++) printf("%d ", cul[ind[i]]);
  printf("%d\n", cul[ind[k]]);
  return 0;
}
