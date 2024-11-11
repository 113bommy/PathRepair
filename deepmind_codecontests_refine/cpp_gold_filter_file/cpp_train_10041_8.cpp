#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
vector<int> adj[N];
int f(int x) {
  long long ans = 0;
  int need = x - adj[0].size();
  vector<int> kollo;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      if (adj[i].size() - j >= x)
        need--, ans += adj[i][j];
      else
        kollo.push_back(adj[i][j]);
    }
  }
  sort(kollo.begin(), kollo.end());
  int ptr = 0;
  for (int i = 0; i < need; i++) ans += kollo[ptr++];
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
  }
  for (int i = 1; i < N; i++) sort(adj[i].begin(), adj[i].end());
  int lo = max(1, int(adj[0].size())), hi = n;
  while (lo + 10 < hi) {
    int md1 = lo + (hi - lo) / 3;
    int md2 = hi - (hi - lo) / 3;
    if (f(md1) > f(md2))
      lo = md1;
    else
      hi = md2;
  }
  int ans = INT_MAX;
  for (int i = lo; i < hi + 1; i++) ans = min(ans, f(i));
  cout << ans << '\n';
  return 0;
}
