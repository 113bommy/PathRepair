#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
vector<int> adj[1000005];
int d[1000005], ANS;
int N, M, s, t;
bool mark[1000005];
int main() {
  scanf("%d %d", &N, &M);
  for (int i = (0); i < (M); ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[v].push_back(u);
    d[u]++;
  }
  scanf("%d %d", &s, &t);
  set<int> a, b;
  a.insert(t);
  mark[t] = true;
  while ((!a.empty()) || (!b.empty())) {
    if (a.empty()) {
      for (__typeof__((b).begin()) it = (b).begin(); it != (b).end(); ++it)
        a.insert(*it);
      b.clear();
      if (!mark[s]) ANS++;
      for (__typeof__((a).begin()) it = (a).begin(); it != (a).end(); ++it)
        mark[*it] = true;
    }
    int node = *a.begin();
    a.erase(a.begin());
    for (int i = (0); i < (int((adj[node]).size())); ++i) {
      int u = adj[node][i];
      if (mark[u]) continue;
      b.insert(node);
      d[u]--;
      if (d[u] == 0) {
        mark[u] = true;
        b.erase(u);
        a.insert(u);
      }
    }
  }
  if (!mark[s])
    printf("-1\n");
  else
    printf("%d\n", ANS);
  return 0;
}
