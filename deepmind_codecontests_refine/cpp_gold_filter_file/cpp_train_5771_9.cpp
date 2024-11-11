#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 25;
int n, k, p[25], e[25], match[25], ans = INF;
void read() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> p[i] >> e[i];
}
void solve() {
  for (int i = 0; i < (1 << n); i++) {
    int power = 0, point = 0, Rank = n + 1;
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) {
        power += e[j];
        ++point;
        match[j] = 0;
      } else
        match[j] = 1;
    for (int j = 0; j < n; j++) {
      if (point > p[j] + match[j] || (point == p[j] && (i & (1 << j)))) --Rank;
      if (Rank <= k) ans = min(ans, power);
    }
  }
}
void result() {
  if (ans == INF)
    cout << "-1";
  else
    cout << ans;
}
int main() {
  read();
  solve();
  result();
}
