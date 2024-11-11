#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 1005;
long long v[N], w[N];
long long dp[M] = {0};
vector<int> vt[M];
int pa[M];
int fpa(int x) {
  if (pa[x] != x) pa[x] = fpa(pa[x]);
  return pa[x];
}
void lnk(int x, int y) {
  x = fpa(x), y = fpa(y);
  if (x != y) pa[x] = y;
}
int main() {
  ios::sync_with_stdio(0);
  long long n, m, V, x, y;
  cin >> n >> m >> V;
  for (int i = 1; i <= (n); i++) pa[i] = i;
  for (int i = 1; i <= (n); i++) cin >> v[i];
  for (int i = 1; i <= (n); i++) cin >> w[i];
  for (int i = 0; i < (m); i++) {
    cin >> x >> y;
    lnk(x, y);
  }
  for (int i = 1; i <= (n); i++) vt[fpa(i)].push_back(i);
  for (int i = 1; i <= (n); i++) {
    if (vt[i].size()) {
      for (int j = V; j >= 0; j--) {
        long long sumv = 0, sumw = 0;
        for (auto x : vt[i]) {
          sumv += v[x], sumw += w[x];
          if (j >= v[i]) dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
        if (j >= sumv) dp[j] = max(dp[j], dp[i - sumv] + sumw);
      }
    }
  }
  cout << dp[V] << endl;
  return 0;
}
