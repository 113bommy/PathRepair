#include <bits/stdc++.h>
using namespace std;
vector<long long> v[200005];
long long visi[200005] = {0}, d[200005] = {0}, p[200005];
void dfs(long long node) {
  long long i;
  visi[node] = 1;
  for (i = 0; i < v[node].size(); ++i)
    if (!visi[v[node][i]]) {
      p[v[node][i]] = node;
      dfs(v[node][i]);
      d[node] = max(d[node], d[v[node][i]] + 1);
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, x, i, a, b, q, h = 0, ans = 0, z;
  cin >> n >> x;
  for (i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1);
  q = x;
  while (q != 1) {
    q = p[q];
    h++;
  }
  q = x;
  z = 0;
  while (q != 1 && h > 0) {
    ans = max(z + 2 * h + 2 * d[q], ans);
    q = p[q];
    z += 2;
    h -= 2;
  }
  cout << ans;
  return 0;
}
