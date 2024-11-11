#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> graph[10005];
  int i, j, n, m, t, a, b;
  long long ans;
  cin >> n;
  for (i = 0; i < n - 1; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  ans = n - 1 - graph[1].size();
  if (graph[1].size() >= 2) {
    ans += (graph[1].size() * (graph[1].size() - 1)) / 2.0;
  }
  for (i = 2; i <= n; i++) {
    int len = graph[i].size();
    len--;
    if (len > 1) {
      ans += (len * (len - 1)) / 2.0;
    }
  }
  cout << ans << endl;
}
