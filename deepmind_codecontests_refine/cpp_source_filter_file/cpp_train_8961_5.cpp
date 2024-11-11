#include <bits/stdc++.h>
using namespace std;
int n, p[1005];
vector<int> T;
bool ok;
inline void enter() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
}
void dfs(int u) {
  while (T[u] != 1) {
    T[u]++;
    u = p[u];
  }
  cout << u << ' ';
}
inline void solve() {
  for (int i = 1; i <= n; i++) {
    T.resize(n + 3);
    dfs(i);
  }
}
int main() {
  enter();
  solve();
  return 0;
}
