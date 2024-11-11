#include <bits/stdc++.h>
using namespace std;
int c[50010], n, m, T, v[50010], team[50010];
long long ans = 0;
vector<int> e[50010], a[50010];
bool check() {
  for (int i = 1; i <= n; i++) {
    bool p;
    p = false;
    for (int j = 1; j <= a[i][0]; j++) {
      if (c[i] == v[a[i][j]]) {
        team[i] = a[i][j];
        p = true;
        break;
      }
    }
    if (!p) return false;
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    int p = 0, q = 0;
    for (int j = 0; j < e[i].size(); j++)
      if (c[e[i][j]] = 1)
        p++;
      else if (c[e[i][j]] == 2)
        q++;
    if (p >= q)
      c[i] = 2;
    else
      c[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    int s, t;
    cin >> s;
    a[i].push_back(s);
    for (int j = 1; j <= s; j++) {
      cin >> t;
      T = max(T, t);
      a[i].push_back(t);
    }
  }
  while (true) {
    for (int i = 1; i <= T; i++) v[i] = rand() % 2 + 1;
    if (check()) break;
  }
  for (int i = 1; i <= n - 1; i++) cout << team[i] << " ";
  cout << team[n] << endl;
  for (int i = 1; i <= T - 1; i++) cout << v[i] << " ";
  cout << v[T] << endl;
}
