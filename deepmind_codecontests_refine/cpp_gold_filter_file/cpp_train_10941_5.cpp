#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, c;
  string v;
  cin >> n;
  map<string, int> costs;
  for (int i = 0; i < n; i++) {
    cin >> c >> v;
    sort(v.begin(), v.end());
    if (costs[v] != 0)
      costs[v] = min(costs[v], c);
    else
      costs[v] = c;
  }
  if (costs["A"] == 0) costs["A"] = 300001;
  if (costs["B"] == 0) costs["B"] = 300001;
  if (costs["C"] == 0) costs["C"] = 300001;
  if (costs["AB"] == 0) costs["AB"] = 300001;
  if (costs["AC"] == 0) costs["AC"] = 300001;
  if (costs["BC"] == 0) costs["BC"] = 300001;
  if (costs["ABC"] == 0) costs["ABC"] = 300001;
  int ans = min({costs["A"] + costs["B"] + costs["C"], costs["A"] + costs["BC"],
                 costs["AB"] + costs["C"], costs["AC"] + costs["B"],
                 costs["AB"] + costs["BC"], costs["AC"] + costs["BC"],
                 costs["AC"] + costs["AB"], costs["ABC"]});
  if (ans != 300001)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}
