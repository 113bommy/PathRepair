#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, int> > G;
bool is_tank[1010];
bool is_tap[1010];
pair<int, int> capacity(int node, map<int, pair<int, int> > &G, int cap) {
  if (is_tap[node])
    return make_pair(node, cap);
  else {
    pair<int, int> p = G[node];
    return capacity(p.first, G, min(cap, p.second));
  }
}
int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  memset(is_tap, true, sizeof(is_tap));
  memset(is_tank, true, sizeof(is_tank));
  for (int i = 0; i < p; i++) {
    int src, dest, diam;
    scanf("%d %d %d", &src, &dest, &diam);
    G[src] = make_pair(dest, diam);
    is_tap[src] = false;
    is_tank[dest] = false;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (is_tank[i] && !is_tap[i]) cnt++;
  fprintf(stderr, "%d\n", cnt);
  for (int src = 1; src <= n; src++) {
    if (is_tank[src] && !is_tap[src]) {
      pair<int, int> ret = capacity(src, G, 2000000000);
      printf("%d %d %d\n", src, ret.first, ret.second);
    }
  }
  return 0;
}
