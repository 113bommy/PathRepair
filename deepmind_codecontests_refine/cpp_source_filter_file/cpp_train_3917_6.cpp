#include <bits/stdc++.h>
using namespace std;
long long n, first, second, i, ans = 1, par[200005], N, E, visi[200005] = {0},
                               h = 1e9 + 7, vv[100005] = {0};
vector<long long> a[200006];
void dfs(long long node) {
  long long i;
  visi[node] = 1;
  N++;
  for (i = 0; i < a[node].size(); ++i) {
    E++;
    if (!visi[a[node][i]]) dfs(a[node][i]);
  }
}
long long fp(long long first) {
  if (par[first] == first)
    return first;
  else
    return par[first] = fp(par[first]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (i = 1; i <= 2 * n; ++i) par[i] = i;
  for (i = 0; i < n; ++i) {
    cin >> first >> second;
    par[first] = fp(second);
    a[second].push_back(first);
    if (first == second) vv[first] = 1;
  }
  for (i = 1; i <= 2 * n; ++i) {
    par[i] = fp(i);
    N = 0;
    E = 0;
    if (!visi[par[i]]) {
      dfs(par[i]);
      if (E >= N)
        ans = (ans * (!vv[par[i]] + 1)) % h;
      else
        ans = (ans * N) % h;
    }
  }
  cout << ans;
  return 0;
}
