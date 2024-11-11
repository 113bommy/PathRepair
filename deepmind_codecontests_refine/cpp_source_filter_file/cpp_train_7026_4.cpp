#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long power(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret *= a;
    a *= a;
    if (ret >= MOD) ret %= MOD;
    if (a >= MOD) a %= MOD;
    b >>= 1;
  }
  return ret;
}
long long invmod(long long x) { return power(x, MOD - 2); }
vector<long long> vp[100005];
int vis[100005] = {0};
int dfs(int n) {
  if (vp[n].size() < 2) return 10001;
  int a[4005] = {0};
  vector<long long> vp1;
  for (int i = 0; i < vp[n].size(); i++) {
    vp1.push_back(vp[n][i]);
    a[vp[n][i]] = 1;
  }
  int min = 10001;
  for (int i = 0; i < vp1.size(); i++) {
    for (int j = 0; j < vp[vp1[i]].size(); j++) {
      if (a[vp[vp1[i]][j]] == 1) {
        if (min >
            vp[vp[vp1[i]][j]].size() + vp[n].size() + vp[vp1[i]].size() - 6) {
          min = vp[vp[vp1[i]][j]].size() + vp[n].size() + vp[vp1[i]].size() - 6;
          break;
        }
      }
    }
  }
  return min;
}
int main() {
  int n, m;
  cin >> m >> n;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    vp[x].push_back(y);
    vp[y].push_back(x);
  }
  int min1 = 10000;
  for (int i = 1; i <= n; i++) {
    min1 = min(dfs(i), min1);
  }
  if (min1 == 10000) {
    cout << "-1" << endl;
    return 0;
  }
  cout << min1 << endl;
}
