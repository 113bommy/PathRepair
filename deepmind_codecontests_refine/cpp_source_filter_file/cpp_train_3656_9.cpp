#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int d, s, D[510][5010], vis[510][510];
pair<int, int> from[510][5010];
queue<pair<int, int> > Q;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> d >> s;
  Q.push({0, 0});
  D[0][0] = 0, vis[0][0] = true;
  while ((int)Q.size()) {
    int re = Q.front().first, sum = Q.front().second;
    Q.pop();
    if (re == 0 && sum == s) break;
    for (int i = 0; i < 10; i++) {
      int newre = (re * 10 + i) % d;
      if (sum + i > s) continue;
      if (!vis[newre][sum + i]) {
        vis[newre][sum + i] = 1;
        Q.push({newre, sum + i});
        D[newre][sum + i] = D[re][sum] + 1;
        from[newre][sum + i] = pair<int, int>(re, sum);
      }
    }
  }
  if (!vis[0][s])
    cout << "-1\n";
  else {
    string ans;
    pair<int, int> cur = pair<int, int>(0, s);
    while (cur != pair<int, int>(0, 0)) {
      ans += '0' + cur.second - from[cur.first][cur.second].second;
      cur = from[cur.first][cur.second];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
  }
  return 0;
}
