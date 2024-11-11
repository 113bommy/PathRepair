#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000100], res;
int t[1000010];
bool vis[1000100];
int req, root;
set<int> s;
int dfs(int a, int par) {
  vis[a] = 1;
  int x = 0;
  for (int i = 0; i < v[a].size(); i++) {
    int y = v[a][i];
    if (y == par) continue;
    x += dfs(y, a);
  }
  x += t[a];
  if (x == req) {
    if (x != root && x != -1) s.insert(a);
    if (s.size() == 2) {
      cout << *s.begin() << ' ' << *s.rbegin();
      exit(0);
    }
    return 0;
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> t[i];
    sum += t[i];
    if (!x) {
      root = i;
      continue;
    }
    v[x].push_back(i);
    v[i].push_back(x);
  }
  if (sum % 3 != 0) {
    cout << -1;
    return 0;
  }
  req = sum / 3;
  dfs(root, -1);
  if (s.size() < 2) {
    cout << -1;
    return 0;
  }
  cout << *s.begin() << ' ' << *s.rbegin();
  return 0;
}
