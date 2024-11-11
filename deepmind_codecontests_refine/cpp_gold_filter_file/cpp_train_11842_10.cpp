#include <bits/stdc++.h>
using namespace std;
enum { UNVISITED, VISITING, VISITED };
const int MAX = 1e5 + 5;
vector<int> adj[MAX];
int degree[MAX], order[MAX], state[MAX], dont_try[MAX];
int n, m;
inline double elapsed() { return clock() / (double)CLOCKS_PER_SEC; }
bool fudeu;
void dfs(int source) {
  state[source] = VISITING;
  for (auto &each : adj[source]) {
    if (state[each] == VISITING) {
      fudeu = true;
    } else if (state[each] == UNVISITED) {
      dfs(each);
    }
    if (fudeu) {
      return;
    }
  }
  state[source] = VISITED;
}
bool is_vara(int the_vara) {
  memset(state, UNVISITED, sizeof state);
  state[the_vara] = VISITED;
  for (int i = int(1); i < int(n + 1); i++) {
    if (state[i] == UNVISITED) {
      fudeu = false;
      dfs(i);
      if (fudeu) {
        for (int j = int(1); j < int(n + 1); j++) {
          if (state[j] != VISITING) {
            dont_try[j] = 1;
          }
        }
        return false;
      }
    }
  }
  return true;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = int(1); i < int(m + 1); i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    degree[u]++;
    degree[v]++;
  }
  for (int i = int(1); i < int(n + 1); i++) {
    order[i] = i;
  }
  sort(order + 1, order + n + 1,
       [](int lhs, int rhs) { return degree[lhs] > degree[rhs]; });
  int ans = -1;
  for (int i = 1; elapsed() <= 0.9 && ans == -1 && i <= n; i++) {
    if (!dont_try[order[i]] && is_vara(order[i])) {
      ans = order[i];
    }
  }
  printf("%d\n", ans);
  return 0;
}
