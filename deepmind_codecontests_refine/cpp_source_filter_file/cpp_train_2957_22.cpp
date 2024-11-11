#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int n, m, p[100005];
set<int> s[100005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    s[u].insert(v);
    s[v].insert(u);
  }
  srand(unsigned(time(0)));
  int c = 20;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
  }
  while (c--) {
    random_shuffle(p + 1, p + n + 1);
    p[n + 1] = p[1];
    bool flag = true;
    for (int i = 1; i <= m; i++) {
      if (s[p[i]].count(p[i + 1])) {
        flag = false;
        break;
      }
    }
    if (flag) {
      for (int i = 1; i <= m; i++) {
        cout << p[i] << ' ' << p[i + 1] << endl;
      }
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
