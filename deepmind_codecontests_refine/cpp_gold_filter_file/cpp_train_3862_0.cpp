#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
const long long int N = 1e6;
vector<vector<int> > v(N + 1);
vector<long long int> seq;
map<long long int, long long int> st;
long long int dfs(long long int src, long long int par) {
  if (src == par) return 0;
  seq.push_back(src);
  long long int x = 1;
  for (auto i : v[src]) {
    x += dfs(i, src);
  }
  st[src] = x;
  return x;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, q;
  cin >> n >> q;
  for (long long int i = 0; i < n - 1; i++) {
    long long int p;
    cin >> p;
    v[p].push_back(i + 2);
  }
  for (long long int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
  dfs(1, 0);
  map<long long int, long long int> pos;
  for (long long int i = 0; i < seq.size(); i++) {
    pos[seq[i]] = i + 1;
  }
  while (q-- > 0) {
    long long int u, k;
    cin >> u >> k;
    long long int id = pos[u] + k - 1;
    long long int ans;
    if (k > st[u])
      ans = -1;
    else
      ans = seq[id - 1];
    cout << ans << endl;
  }
}
