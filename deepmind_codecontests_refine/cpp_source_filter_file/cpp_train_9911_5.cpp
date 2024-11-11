#include <bits/stdc++.h>
using namespace std;
const long long int use = 1e6;
int main() {
  long long int n;
  cin >> n;
  set<long long int> m[n + 5];
  long long int ans[n + 7];
  ans[0] = 0;
  for (long long int i = 0; i < n - 2; i++) {
    long long int x, y, z;
    cin >> x >> y >> z;
    m[x].insert(y);
    m[x].insert(z);
    m[y].insert(x);
    m[y].insert(z);
    m[z].insert(x);
    m[z].insert(y);
  }
  bool vis[n + 1];
  memset(vis, 0, sizeof(vis));
  long long int a;
  for (long long int i = 1; i <= n; i++)
    if (m[i].size() == 2) {
      vis[i] = 1;
      a = i;
      ans[1] = a;
      break;
    }
  auto itr = m[1].begin();
  long long int x = *itr;
  itr++;
  long long int y = *itr;
  if (m[x].size() < m[y].size()) {
    vis[x] = 1;
    ans[2] = x;
  } else {
    vis[y] = 1;
    ans[2] = y;
  }
  for (long long int i = 2; i < n; i++) {
    for (auto j : m[ans[i]]) {
      if (!vis[j] and m[ans[i - 1]].find(j) != m[ans[i - 1]].end()) {
        ans[i + 1] = j;
        vis[j] = 1;
        break;
      }
    }
  }
  for (long long int i = 1; i <= n; i++) cout << ans[i] << " ";
}
