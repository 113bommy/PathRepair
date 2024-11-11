#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, use[200010], culoare[200010], v[200010], x, y, a;
vector<int> v2[200010];
vector<pair<int, int> > G[200010];
void DF(int nod) {
  use[nod] = 1;
  for (auto it : G[nod]) {
    if (!use[it.first]) {
      if (it.second == 1) {
        culoare[it.first] = culoare[nod];
      } else {
        culoare[it.first] = 1 - culoare[nod];
      }
      DF(it.first);
    } else {
      if (it.second == 1) {
        if (culoare[it.first] != culoare[nod]) {
          cout << "NO";
          exit(0);
        }
      } else {
        if (culoare[it.first] != 1 - culoare[nod]) {
          cout << "NO";
          exit(0);
        }
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> v[i];
  for (i = 1; i <= m; i++) {
    cin >> x;
    for (j = 1; j <= x; j++) {
      cin >> a;
      v2[a].push_back(i);
    }
  }
  for (i = 1; i <= n; i++) {
    G[v2[i][0]].push_back({v2[i][1], v[i]});
    G[v2[i][1]].push_back({v2[i][0], v[i]});
  }
  for (i = 1; i <= n; i++) {
    if (!use[i]) {
      culoare[i] = 1;
      DF(i);
    }
  }
  cout << "YES";
  return 0;
}
