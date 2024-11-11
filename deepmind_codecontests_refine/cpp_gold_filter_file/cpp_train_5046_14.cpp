#include <bits/stdc++.h>
using namespace std;
const int N = 70000;
int deg[N], xorsum[N], xorhave[N], n;
vector<pair<int, int> > ans;
queue<int> nodes;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &deg[i], &xorsum[i]);
    if (deg[i] == 1) {
      nodes.push(i);
    }
  }
  while (!nodes.empty()) {
    if (deg[nodes.front()] == 0) {
      nodes.pop();
      continue;
    }
    int newnode = xorhave[nodes.front()] ^ xorsum[nodes.front()];
    deg[newnode]--;
    deg[nodes.front()]--;
    xorhave[newnode] ^= nodes.front();
    ans.push_back(make_pair(nodes.front(), newnode));
    nodes.pop();
    if (deg[newnode] == 1) {
      nodes.push(newnode);
    }
  }
  int sz = ans.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
