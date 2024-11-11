#include <bits/stdc++.h>
using namespace std;
int vis[300010], sq = 316;
vector<int> vc[300010];
vector<pair<int, int> > ac[300010];
int main() {
  int i, j, k, l, m, n, q, ts;
  cin >> ts;
  while (ts--) {
    scanf("%d%d", &n, &q);
    int ck = 0;
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
      ac[i].clear();
    }
    for (int i = 1; i <= q; i++) {
      scanf("%d", &l);
      vc[i].clear();
      for (int j = 1; j <= l; j++) {
        scanf("%d", &k);
        vc[i].push_back(k);
      }
    }
    for (int i = 1; i <= q; i++) {
      if (vc[i].size() > sq) continue;
      for (int j = 0; j < vc[i].size() - 1; j++) {
        int a = vc[i][j], b = vc[i][j + 1];
        for (int k = j + 1; k < vc[i].size(); k++) {
          ac[a].push_back(make_pair(b, vc[i][k]));
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < ac[i].size(); j++) {
        int a = ac[i][j].second;
        int b = ac[i][j].first;
        if (vis[a] && vis[a] != b) {
          ck = 1;
          break;
        }
        vis[a] = b;
      }
      if (ck) break;
      for (int j = 0; j < ac[i].size(); j++) {
        int a = ac[i][j].second;
        vis[a] = 0;
      }
    }
    for (int i = 1; i <= q; i++) {
      if (vc[i].size() <= sq) continue;
      memset(vis, 0, sizeof vis);
      for (int j = 0; j < vc[i].size(); j++) {
        vis[vc[i][j]] = j + 1;
      }
      for (int l = 1; l <= q; l++) {
        if (vc[l].size() > sq && l <= i) continue;
        int age = 0;
        for (int j = vc[l].size() - 1; j >= 0; j--) {
          int v = vc[l][j];
          if (vis[v] && vis[v] < age && vc[l][j + 1] != vc[i][vis[v] + 1]) {
            ck = 1;
            break;
          }
          age = max(age, vis[v]);
        }
        if (ck) break;
      }
      if (ck) break;
    }
    if (ck == 0)
      printf("Robot\n");
    else
      printf("Human\n");
  }
}
