#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[100000];
int a[100000];
int currA[100000];
queue<int> q;
vector<int> ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v, to;
    cin >> v >> to;
    v--;
    to--;
    g[v].push_back(to);
    g[to].push_back(v);
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) currA[i] = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == currA[i]) q.push(i);
  }
  while (q.empty() == 0) {
    int curr = q.front();
    currA[curr]++;
    ans.push_back(curr);
    q.pop();
    for (int i = 0; i < g[curr].size(); i++) {
      int to = g[curr][i];
      currA[to]++;
      if (currA[to] == a[to]) q.push(to);
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << " ";
  }
  return 0;
}
