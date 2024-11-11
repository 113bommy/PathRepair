#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
int n, e;
vector<vector<int> > adj;
vector<int> u, v;
vector<int> t(1000000, 0);
vector<int> re;
int m = 0;
bool work() {
  for (int i = 0; i <= 1000000; i++) {
    t[i] = rand() & 1;
  }
  for (int i = 0; i < n; i++) {
    re[i] = adj[i][rand() % (int)adj[i].size()];
  }
  int cnt = 0;
  for (int i = 0; i < e; i++) {
    if (t[re[u[i]]] != t[re[v[i]]]) cnt++;
  }
  if (cnt * 2 >= e) return true;
  return false;
}
int main() {
  cin >> n >> e;
  u.assign(e, 0);
  v = u;
  for (int i = 0; i < e; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    u[i] = x;
    v[i] = y;
  }
  adj.assign(n, vector<int>(0, 0));
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (x--) {
      int y;
      cin >> y;
      m = max(m, y);
      y--;
      adj[i].push_back(y);
    }
  }
  re.assign(n, 0);
  while (!work())
    ;
  for (int i = 0; i < n; i++) {
    cout << re[i] + 1 << " ";
  }
  cout << endl;
  for (int i = 0; i < m; i++) {
    cout << t[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}
