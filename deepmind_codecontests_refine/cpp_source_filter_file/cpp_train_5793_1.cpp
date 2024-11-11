#include <bits/stdc++.h>
using namespace std;
const int MAXN = 22;
int N, M, aim_state, min_steps, min_pset, edges[MAXN], vis[1 << MAXN];
void DFS(int state, int pset, int steps) {
  if (steps >= min_steps) return;
  if (vis[pset]) return;
  vis[pset] = true;
  if (state == aim_state) {
    min_steps = steps;
    min_pset = pset;
    return;
  }
  for (int i = 0; i < N; ++i) {
    if ((1 << i) & (state ^ pset)) {
      if ((state | edges[i]) > state)
        DFS(state | edges[i], pset | (1 << i), steps + 1);
    }
  }
}
inline void init() {
  scanf("%d%d", &N, &M);
  for (int i = 0, u, v; i < M; ++i) {
    scanf("%d%d", &u, &v);
    --u;
    --v;
    edges[u] |= 1 << v;
    edges[v] |= 1 << u;
  }
  for (int i = 0; i < N; ++i) edges[i] |= 1 << i;
}
inline int solve() {
  if (M == N * (N - 1) / 2) return 0;
  aim_state = (1 << N) - 1;
  min_steps = N + 1;
  min_pset = aim_state;
  for (int i = 0; i < N; ++i) DFS(edges[i], 1 << i, 1);
  return min_steps;
}
int main() {
  init();
  int steps = solve();
  if (steps) {
    printf("%d\n", steps);
    bool first = true;
    for (int i = 0; i < N; ++i)
      if (min_pset & (1 << i)) {
        if (first)
          first = false;
        else
          printf(" ");
        printf("%d", i + 1);
      }
    printf("\n");
  } else
    printf("\n");
  return 0;
}
