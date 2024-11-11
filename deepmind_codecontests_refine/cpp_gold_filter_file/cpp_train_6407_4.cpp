#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> v[N];
bool viz[N];
void dfs(int x) {
  viz[x] = 1;
  for (auto it : v[x])
    if (!viz[it]) dfs(it);
}
int main() {
  int n, m;
  cin >> n >> m;
  if (m != n - 1) {
    cout << "no";
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1);
  for (int i = 1; i <= n; i++)
    if (!viz[i]) {
      cout << "no";
      return 0;
    }
  cout << "yes";
}
