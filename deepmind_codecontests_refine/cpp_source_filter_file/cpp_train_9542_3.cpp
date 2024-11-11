#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, m, i, j;
  string s[100005], ss, sss;
  map<string, long long> cost;
  cin >> n >> k >> m;
  for (i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (i = 1; i <= n; i++) {
    cin >> j;
    cost[s[i]] = j;
  }
  for (i = 1; i <= k; i++) {
    long long x, y[100005];
    cin >> x;
    long long MN = 1000000009;
    for (j = 1; j <= x; j++) {
      cin >> y[i];
      if (cost[s[y[i]]] < MN) {
        MN = cost[s[y[i]]];
      }
    }
    for (j = 1; j <= x; j++) {
      cost[s[y[i]]] = MN;
    }
  }
  long long ans = 0;
  for (i = 1; i <= m; i++) {
    cin >> sss;
    ans += cost[sss];
  }
  cout << ans << endl;
  return 0;
}
