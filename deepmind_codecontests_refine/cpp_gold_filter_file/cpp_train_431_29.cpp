#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
vector<pair<int, int> > G[N];
bool in[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 3 * n; ++i) {
      G[i].clear();
      in[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      G[u].push_back({v, i + 1});
      G[v].push_back({u, i + 1});
    }
    vector<int> match;
    for (int i = 1; i <= 3 * n; ++i) {
      bool found = 0;
      for (auto e : G[i]) {
        if (in[e.first]) {
          found = 1;
          match.push_back(e.second);
          in[e.first] = 0;
          break;
        }
      }
      if (!found) in[i] = 1;
    }
    if ((int)match.size() >= n) {
      printf("Matching\n");
      int cnt = 0;
      for (int i : match) {
        printf("%d ", i);
        cnt++;
        if (cnt == n) break;
      }
      puts("");
    } else {
      printf("IndSet\n");
      int cnt = 0;
      for (int i = 1; i <= 3 * n; ++i)
        if (in[i]) {
          printf("%d ", i);
          cnt++;
          if (cnt == n) break;
        }
      assert(cnt >= n);
      puts("");
    }
  }
}
