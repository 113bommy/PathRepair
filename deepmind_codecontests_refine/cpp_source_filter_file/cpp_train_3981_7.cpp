#include <bits/stdc++.h>
using namespace std;
int n, m, k, l[100100], c[100100];
vector<int> g[100100];
vector<int> s;
void dfs(int t) {
  s.push_back(t);
  l[t] = s.size();
  for (auto v : g[t]) {
    if (!l[v])
      dfs(v);
    else {
      if (l[t] - l[v] > k) {
        printf("2\n%d\n", l[t] - l[v] + 1);
        for (int i = l[v] - 1; i < l[t]; i++) printf("%d ", s[i]);
        exit(0);
      }
    }
  }
  if (!c[t])
    for (auto v : g[t]) c[v] = 1;
  s.pop_back();
}
int main() {
  int i, a, b;
  scanf("%d %d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  while (k * k < n) k++;
  dfs(1);
  printf("1\n");
  for (i = 1; k; i++) {
    if (!c[i]) {
      printf("%d ", i);
      k--;
    }
  }
}
