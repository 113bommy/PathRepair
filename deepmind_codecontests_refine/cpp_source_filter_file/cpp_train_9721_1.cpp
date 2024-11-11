#include <bits/stdc++.h>
using namespace std;
const int maxn = 300001;
int m, n, x, y, tmp;
vector<int> adj[maxn];
bool daste[maxn], b;
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  while (b == 0) {
    b = 1;
    for (int i = 1; i <= n; i++) {
      tmp = 0;
      for (int j = 0; j < adj[i].size(); j++)
        if (daste[i] == daste[adj[i][j]]) tmp++;
      if (tmp > 1) {
        daste[i] = 1 - daste[i];
        b = 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << daste[i] << " ";
  cout << endl;
  return 0;
}
