#include <bits/stdc++.h>
using namespace std;
vector<int> path, ed[100000];
void trav(int t, int l) {
  if (path.size() == l) {
    path.push_back(1);
  } else {
    path[l] ^= 1;
  }
  for (auto x : ed[t]) {
    trav(x, l + 1);
  }
}
void add(int u, int v) { ed[u].push_back(v); }
int main() {
  int n, i, w, cnt;
  scanf("%d", &n);
  for (i = 0; i < n; i++) ed[i].clear();
  path.clear();
  for (i = 1; i < n; i++) {
    scanf("%d", &w);
    add(w - 1, i);
  }
  trav(0, 0);
  cnt = 0;
  for (auto x : path) {
    cnt += x;
  }
  printf("%d\n", cnt);
  return 0;
}
