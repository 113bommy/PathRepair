#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
const int INF = 1000000007;
struct Store {
  int location;
  int shovels;
  int price;
} store[N];
queue<int> q;
int d[N];
int nStore;
int n, m;
vector<int> adj[N];
void bfs(int u) {
  memset(d, 255, sizeof(d));
  d[u] = 0;
  q.push(u);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
}
bool check(int timer, int maxShovels, int maxCost) {
  for (int i = 1; i <= nStore; i++)
    if (d[store[i].location] <= timer && d[store[i].location] != -1) {
      int need = min(maxShovels, store[i].shovels);
      if (need * store[i].price > maxCost) return false;
      maxCost -= need * store[i].price;
      maxShovels -= need;
      if (maxShovels == 0) return true;
    }
  return maxShovels == 0;
}
int func(int u, int maxShovels, int maxCost) {
  bfs(u);
  int l = 0, r = n, ans = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(m, maxShovels, maxCost)) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  return ans;
}
bool cmp(Store a, Store b) { return a.price < b.price; }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> nStore;
  for (int i = 1; i <= nStore; i++)
    scanf("%d%d%d", &store[i].location, &store[i].shovels, &store[i].price);
  sort(store + 1, store + nStore + 1, cmp);
  int nQuery;
  cin >> nQuery;
  while (nQuery--) {
    int g, r, a;
    cin >> g >> r >> a;
    printf("%d\n", func(g, r, a));
  }
}
