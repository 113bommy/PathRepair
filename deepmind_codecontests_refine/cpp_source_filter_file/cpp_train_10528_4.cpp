#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
vector<int> g[maxn], leave;
int dep[maxn];
bool vis[maxn];
int n, m, k;
void pt(int s, int e) {
  if (s == e) {
    cout << s << " ";
    return;
  }
  for (auto i : g[s]) {
    if (dep[i] == dep[s] - 1) {
      cout << s << " ";
      pt(i, e);
      break;
    }
  }
}
bool dfs(int u, int d) {
  dep[u] = d;
  if (d >= n / k) {
    cout << "PATH" << endl;
    cout << d << endl;
    pt(u, 1);
    cout << endl;
    return true;
  }
  bool flag = 1;
  for (auto i : g[u]) {
    if (dep[i]) continue;
    flag = 0;
    if (dfs(i, d + 1)) {
      return true;
    }
  }
  if (flag) {
    leave.push_back(u);
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  if (!dfs(1, 1)) {
    cout << "CYCLES" << endl;
    for (auto le : leave) {
      int x = 0, y = 0;
      for (auto i : g[le]) {
        if (dep[i] != dep[le] - 1) {
          if (!x) {
            x = i;
          } else {
            y = i;
            break;
          }
        }
      }
      if ((dep[le] - dep[x] + 1) % 3) {
        cout << dep[le] - dep[x] + 1 << endl;
        pt(le, x);
        cout << endl;
      } else if ((dep[le] - dep[y] + 1) % 3) {
        cout << dep[le] - dep[y] + 1 << endl;
        pt(le, y);
        cout << endl;
      } else {
        if (dep[x] > dep[y]) swap(x, y);
        cout << dep[y] - dep[x] + 2 << endl;
        cout << le << " ";
        pt(y, x);
        cout << endl;
      }
      --k;
      if (!k) {
        break;
      }
    }
  }
  return 0;
}
