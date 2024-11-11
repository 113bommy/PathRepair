#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 7;
const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  int hp0, hp1, att0, att1, def0, def1;
  int hp_cost, att_cost, def_cost;
  cin >> hp0 >> att0 >> def0;
  cin >> hp1 >> att1 >> def1;
  cin >> hp_cost >> att_cost >> def_cost;
  int ans = INF;
  for (int i = def0; i <= 100; i++) {
    for (int j = att0; j <= 200; j++) {
      if (j <= def1) continue;
      int t = ceil(1.0 * hp1 / (j - def1));
      int h = max(hp0, 1 + (att1 - def0) * t);
      ans = min(ans, (h - hp0) * hp_cost + (j - att0) * att_cost +
                         (i - def0) * def_cost);
    }
  }
  cout << ans;
  return 0;
}
