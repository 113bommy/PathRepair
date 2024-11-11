#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101000;
int dep[MAXN], id[MAXN], n, son[MAXN];
vector<int> adj[MAXN], ans;
void dfsdep(int s) {
  dep[s] = 0;
  id[s] = s;
  for (auto t : adj[s]) {
    dfsdep(t);
    if (dep[t] + 1 > dep[s]) {
      dep[s] = dep[t] + 1;
      id[s] = id[t];
    }
  }
}
void dfs(int s) {
  vector<int> v;
  for (auto t : adj[s]) v.push_back(t);
  if (v.empty()) return;
  auto comp = [&](int x, int y) { return dep[x] < dep[y]; };
  stable_sort(v.begin(), v.end(), comp);
  while ((int)v.size() >= 2) {
    int sz = v.size();
    int x = v[sz - 2], y = v[sz - 1];
    for (int i = 0; i < dep[x] + 1; i++) ans.push_back(y);
    son[id[x]] = y;
    v.pop_back();
  }
  son[s] = v[0];
  for (auto t : adj[s]) dfs(t);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    son[p] = i;
    adj[p].push_back(i);
  }
  dfsdep(0);
  dfs(0);
  vector<int> v;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    v.push_back(cur);
    cur = son[cur];
  }
  for (auto t : v) {
    printf("%d ", t);
  }
  printf("\n");
  printf("%d\n", (int)ans.size());
  reverse(ans.begin(), ans.end());
  for (auto t : ans) {
    printf("%d ", t);
  }
  printf("\n");
}
