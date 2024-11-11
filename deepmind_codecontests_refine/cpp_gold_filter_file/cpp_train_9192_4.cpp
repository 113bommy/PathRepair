#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 228;
vector<int> g[MAXN];
bool vis[MAXN];
int dis[MAXN];
void dfs(int v, int a, int b) {
  vis[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if ((to == a && b == v) || (to == b && a == v)) {
      continue;
    }
    if (vis[to] == 0) {
      dis[to] = dis[v] + 1;
      dfs(to, a, b);
    }
  }
}
int main() {
  cin >> n;
  int a[n - 1];
  int b[n - 1];
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  if (n <= 3) {
    cout << 0;
    return 0;
  }
  vector<int> l;
  for (int i = 0; i < n - 1; i++) {
    int ans1 = -1;
    int ans2 = -1;
    int ans3 = -1;
    int ans4 = -1;
    if (g[a[i]].size() >= 2) {
      dfs(a[i], a[i], b[i]);
      for (int j = 0; j < n; j++) {
        if (dis[j] > ans1) {
          ans1 = dis[j];
          ans2 = j;
        }
      }
      for (int j = 0; j < n; j++) {
        dis[j] = 0;
        vis[j] = 0;
      }
      dfs(ans2, a[i], b[i]);
      ans1 = -1;
      for (int j = 0; j < n; j++) {
        if (ans1 < dis[j]) {
          ans1 = dis[j];
        }
      }
      for (int j = 0; j < n; j++) {
        dis[j] = 0;
        vis[j] = 0;
      }
    }
    if (g[b[i]].size() >= 2) {
      dfs(b[i], b[i], a[i]);
      for (int j = 0; j < n; j++) {
        if (dis[j] > ans3) {
          ans3 = dis[j];
          ans4 = j;
        }
      }
      for (int j = 0; j < n; j++) {
        dis[j] = 0;
        vis[j] = 0;
      }
      dfs(ans4, b[i], a[i]);
      ans3 = -1;
      for (int j = 0; j < n; j++) {
        if (ans3 < dis[j]) {
          ans3 = dis[j];
        }
      }
      for (int j = 0; j < n; j++) {
        dis[j] = 0;
        vis[j] = 0;
      }
    }
    l.push_back(ans1 * ans3);
  }
  sort(l.begin(), l.end());
  if (l[l.size() - 1] < 0) {
    cout << 0;
    return 0;
  }
  cout << l[l.size() - 1];
  return 0;
}
