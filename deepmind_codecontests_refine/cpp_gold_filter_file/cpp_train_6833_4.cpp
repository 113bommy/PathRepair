#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;
long long int vis[N];
vector<vector<int> > v;
int dfs(int t) {
  vis[t] = 1;
  for (int i = 0; i < v[t].size(); i++) {
    if (vis[v[t][t]] == 0) {
      dfs(v[t][i]);
    }
  }
  return 0;
}
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int y = 1;
  long long int i = 0;
  long long int ans = 0, p = 0, d = 1;
  while (1) {
    if (d > n) {
      break;
    }
    p++;
    d = pow(2, p);
  }
  k = min(k, p + 1);
  long double o = 1 - (long double)(1 / (long double)(pow(2, k)));
  if (k == 1)
    cout << max(n, d / 2) << endl;
  else {
    ans = 2 * (d / 2) - 1;
    cout << ans << endl;
  }
  return 0;
}
