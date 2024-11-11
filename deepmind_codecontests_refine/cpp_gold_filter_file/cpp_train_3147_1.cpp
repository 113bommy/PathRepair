#include <bits/stdc++.h>
using namespace std;
int a[100100], b[100100], c[100100], p[100100], q[100100];
map<int, set<int> > cnt[100100];
vector<int> adj[100100];
bool in_queue[100100];
bool border(int t) {
  int aux = 0;
  int u = min(a[t], b[t]), v = max(a[t], b[t]);
  if (cnt[u][v].size() == 1) aux++;
  u = min(a[t], c[t]), v = max(a[t], c[t]);
  if (cnt[u][v].size() == 1) aux++;
  u = min(b[t], c[t]), v = max(b[t], c[t]);
  if (cnt[u][v].size() == 1) aux++;
  return (aux >= 2);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      cnt[i].clear();
      adj[i].clear();
      in_queue[i] = false;
    }
    for (int i = 1; i <= n - 2; i++) {
      scanf("%d%d%d", &a[i], &b[i], &c[i]);
      cnt[min(a[i], b[i])][max(a[i], b[i])].insert(i);
      cnt[min(a[i], c[i])][max(a[i], c[i])].insert(i);
      cnt[min(b[i], c[i])][max(b[i], c[i])].insert(i);
    }
    for (int u = 1; u <= n; u++) {
      for (auto x : cnt[u]) {
        int v = x.first;
        if (x.second.size() == 1) {
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
      }
    }
    int i = 0, u = 1, last = 0;
    while (true) {
      p[i++] = u;
      int v;
      for (int i = 0; i < adj[u].size(); i++) {
        v = adj[u][i];
        if (v != last) break;
      }
      if (v == 1) break;
      last = u;
      u = v;
    }
    for (int i = 0; i < n; i++) {
      if (i) printf(" ");
      printf("%d", p[i]);
    }
    printf("\n");
    queue<int> Q;
    for (int i = 1; i <= n - 2; i++) {
      if (border(i)) {
        in_queue[i] = true;
        Q.push(i);
      }
    }
    i = 0;
    while (!Q.empty()) {
      int t = Q.front();
      Q.pop();
      q[i++] = t;
      int u = min(a[t], b[t]), v = max(a[t], b[t]);
      cnt[u][v].erase(t);
      if (cnt[u][v].size() == 1) {
        int t2 = *cnt[u][v].begin();
        if (border(t2) and !in_queue[t2]) {
          in_queue[t2] = true;
          Q.push(t2);
        }
      }
      u = min(a[t], c[t]), v = max(a[t], c[t]);
      cnt[u][v].erase(t);
      if (cnt[u][v].size() == 1) {
        int t2 = *cnt[u][v].begin();
        if (border(t2) and !in_queue[t2]) {
          in_queue[t2] = true;
          Q.push(t2);
        }
      }
      u = min(b[t], c[t]), v = max(b[t], c[t]);
      cnt[u][v].erase(t);
      if (cnt[u][v].size() == 1) {
        int t2 = *cnt[u][v].begin();
        if (border(t2) and !in_queue[t2]) {
          in_queue[t2] = true;
          Q.push(t2);
        }
      }
    }
    for (int i = 0; i < n - 2; i++) {
      if (i) printf(" ");
      printf("%d", q[i]);
    }
    printf("\n");
  }
}
