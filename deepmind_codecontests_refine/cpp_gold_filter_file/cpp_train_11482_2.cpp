#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> gangs;
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      int x;
      scanf("%d", &x);
      gangs[x].push_back(i);
    }
    vector<pair<int, int>> edges;
    int x = (*gangs.begin()).first;
    int node = -1;
    for (auto u : gangs) {
      if (u.first == x) continue;
      if (node == -1) {
        int v = u.second[0];
        for (int p : gangs[x]) {
          node = p;
          edges.push_back({v, p});
        }
        for (int i = 1; i < u.second.size(); i++)
          edges.push_back({u.second[i], node});
      } else {
        for (int v : u.second) {
          edges.push_back({v, node});
        }
      }
    }
    if (edges.empty()) {
      printf("NO\n");
      gangs.clear();
      continue;
    }
    printf("YES\n");
    for (auto p : edges) {
      printf("%d %d\n", p.first + 1, p.second + 1);
    }
    gangs.clear();
  }
  return 0;
}
