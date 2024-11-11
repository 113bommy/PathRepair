#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
bool u[N];
vector<int> g[N], st;
int deg[N], cnt[N];
inline bool check(int v, int k, int p = 0) {
  if (k == 0) {
    return g[v].size() == 1;
  }
  int wow = 0;
  for (auto to : g[v]) {
    if (to == p) continue;
    if (check(to, k - 1)) {
      ++wow;
    } else {
      return 0;
    }
  }
  return wow >= 3;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  for (int i = 1; i <= n; ++i) deg[i] = -10000;
  for (int i = 1; i <= n; ++i) {
    if (g[i].size() == 1) {
      deg[i] = 0;
      st.emplace_back(i);
    }
  }
  int alreadyYes = 0;
  int it = 0;
  while (it != st.size()) {
    int v = st[it++];
    int parent = 0;
    if (deg[v] > k) {
      cout << "No\n";
      return 0;
    }
    for (auto to : g[v]) {
      if (deg[to] + 1 == deg[v]) continue;
      if (deg[to] == -10000 || deg[to] == deg[v] + 1) {
        deg[to] = deg[v] + 1;
        ++parent;
        if (++cnt[to] == 3) {
          st.emplace_back(to);
        }
      } else {
        cout << "No\n";
        return 0;
      }
    }
    if (parent == 0) {
      if (deg[v] == k && cnt[v] >= 3) {
        if (alreadyYes) {
          cout << "No\n";
          return 0;
        }
        alreadyYes = v;
      } else {
        cout << "No\n";
        return 0;
      }
    }
    if (parent > 1) {
      cout << "No\n";
      return 0;
    }
  }
  if (alreadyYes && check(alreadyYes, k)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
