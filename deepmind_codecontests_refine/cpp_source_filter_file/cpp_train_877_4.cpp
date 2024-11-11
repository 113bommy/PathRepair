#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 100000 + 10;
vector<int> G[maxn];
vector<int> val[maxn];
vector<int> ver[maxn];
struct he {
  int from, to, w;
} HMM[maxn];
int n, m, u, v, w;
bool cmp(he a, he b) { return a.w < b.w; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u, &v, &w);
    HMM[i].from = u;
    HMM[i].to = v;
    HMM[i].w = w;
  }
  int over = 0;
  sort(HMM + 1, HMM + m + 1, cmp);
  for (int i = 1; i <= m; i++) {
    u = HMM[i].from;
    v = HMM[i].to;
    w = HMM[i].w;
    int ks = 1;
    for (int j = 0; j < G[u].size(); j++) {
      int t = val[u][j];
      int st = ver[u][j];
      if (t < w && st + 1 > ks) {
        ks = st + 1;
      }
    }
    if (G[v].size() == 2) {
      if (w != val[v][0]) {
        if (ks > ver[v][0]) {
          if (ver[v][0] < ver[v][1]) {
            std::vector<int>::iterator it = G[v].begin();
            G[v].erase(it);
            std::vector<int>::iterator it1 = ver[v].begin();
            ver[v].erase(it1);
            std::vector<int>::iterator it2 = val[v].begin();
            val[v].erase(it2);
            G[v].push_back(u);
            val[v].push_back(w);
            ver[v].push_back(ks);
          } else {
            std::vector<int>::iterator it = G[v].begin() + 1;
            G[v].erase(it);
            std::vector<int>::iterator it1 = ver[v].begin() + 1;
            ver[v].erase(it1);
            std::vector<int>::iterator it2 = val[v].begin() + 1;
            val[v].erase(it2);
            G[v].push_back(u);
            val[v].push_back(w);
            ver[v].push_back(ks);
          }
        }
      } else {
        if (ks > ver[v][0]) {
          std::vector<int>::iterator it = G[v].begin() + 1;
          G[v].erase(it);
          std::vector<int>::iterator it1 = ver[v].begin() + 1;
          ver[v].erase(it1);
          std::vector<int>::iterator it2 = val[v].begin() + 1;
          val[v].erase(it2);
          G[v].push_back(u);
          val[v].push_back(w);
          ver[v].push_back(ks);
        }
      }
    } else {
      G[v].push_back(u);
      val[v].push_back(w);
      ver[v].push_back(ks);
    }
    over = max(over, ks);
  }
  printf("%d\n", over);
  return 0;
}
