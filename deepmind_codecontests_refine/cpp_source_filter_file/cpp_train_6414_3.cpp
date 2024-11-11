#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T x, T y) {
  if (x < y) swap(x, y);
  while (y > 0) {
    T f = x % y;
    x = y;
    y = f;
  }
  return x;
}
const int maxn = 100100;
int n, w, h;
struct Dancer {
  int g, x, y;
};
Dancer G[maxn];
map<int, vector<int> > collisions;
int Gidx[maxn];
struct PointSort {
  bool operator()(int i, int j) {
    if (G[i].g != G[j].g) return G[i].g > G[j].g;
    if (G[i].g == 2) return G[i].y < G[j].y;
    return G[i].x < G[j].x;
  }
};
struct PointSort2 {
  bool operator()(int i, int j) {
    if (G[i].g != G[j].g) return G[i].g < G[j].g;
    if (G[i].g == 2) return G[i].y > G[j].y;
    return G[i].x < G[j].x;
  }
};
int main(int argc, char* argv[]) {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n >> w >> h;
  {
    collisions.clear();
    for (int i = 1; i <= n; i++) {
      int p, t;
      cin >> G[i].g >> p >> t;
      if (G[i].g == 1) {
        G[i].x = p;
        G[i].y = -t;
      } else {
        G[i].x = -t;
        G[i].y = p;
      }
      collisions[G[i].x + G[i].y].push_back(i);
      Gidx[i] = i;
    }
    for (auto t_pl : collisions) {
      int t = t_pl.first;
      auto& pl = t_pl.second;
      auto pl2 = pl;
      sort(pl.begin(), pl.end(), PointSort());
      sort(pl2.begin(), pl2.end(), PointSort2());
      for (int i = 0, j = pl.size(); i < j; i++) {
        Gidx[pl[i]] = pl2[i];
      }
    }
    for (int i = 1; i <= n; i++) {
      if (G[Gidx[i]].g == 1) {
        printf("%d %d\n", G[Gidx[i]].x, h);
      } else {
        printf("%d %d\n", w, G[Gidx[i]].y);
      }
    }
  }
  return 0;
}
