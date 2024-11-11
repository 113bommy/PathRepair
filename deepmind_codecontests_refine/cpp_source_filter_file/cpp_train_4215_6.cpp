#include <bits/stdc++.h>
using namespace std;
const int N = 500;
string s[N];
int n, root, used[N];
vector<int> g[N], ans, g2[N], ans2[N], gg[N];
bool ok, u[N];
void comp(int x, int y) {
  ok = 0;
  for (int j = 0; j < min(s[x].size(), s[y].size()); j++) {
    if (s[x][j] == s[y][j]) {
      continue;
    } else {
      g[s[x][j] - 'a' + 1].push_back(s[y][j] - 'a' + 1);
      ok = 1;
      return;
    }
  }
  if (s[x].size() > s[y].size()) {
    cout << "Impossible";
    return;
  }
}
void dfs(int v) {
  used[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (used[to] == 1) {
      cout << "Impossible";
      exit(0);
    }
    if (!used[to]) {
      dfs(to);
    }
  }
  used[v] = 2;
  ans.push_back(v);
}
int main() {
  setlocale(LC_ALL, "Russian");
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      comp(i, j);
    }
  }
  for (int i = 1; i <= 26; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << char(ans[i] + 'a' - 1);
  }
  return 0;
}
