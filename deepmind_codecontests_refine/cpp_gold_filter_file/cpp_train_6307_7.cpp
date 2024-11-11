#include <bits/stdc++.h>
using namespace std;
const int maxn = 7e3 + 11;
int n;
vector<int> s[2];
const int loose = 0;
const int win = 1;
bool vis[2][maxn][2];
int deg[maxn][2];
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int k, i = 0; i < 2; i++) {
    cin >> k;
    s[i].resize(k);
    for (auto &x : s[i]) cin >> x;
  }
  queue<pair<int, int> > q[2];
  q[loose].push({0, 0});
  q[loose].push({0, 1});
  vis[loose][0][0] = 1;
  vis[loose][0][1] = 1;
  while (!q[loose].empty()) {
    while (!q[loose].empty()) {
      pair<int, int> fr = q[loose].front();
      q[loose].pop();
      int player = fr.second ^ 1;
      int me = fr.first;
      for (auto x : s[player]) {
        int wp = me - x;
        while (wp < 0) wp += n;
        if (!vis[win][wp][player] && !vis[loose][wp][player]) {
          vis[win][wp][player] = 1;
          q[win].push({wp, player});
        }
      }
    }
    while (!q[win].empty()) {
      pair<int, int> fr = q[win].front();
      q[win].pop();
      int player = fr.second ^ 1;
      int me = fr.first;
      for (auto x : s[player]) {
        int lp = me - x;
        while (lp < 0) lp += n;
        if (!vis[loose][lp][player] && !vis[win][lp][player] &&
            ++deg[lp][player] == (int)(s[player]).size()) {
          vis[loose][lp][player] = 1;
          q[loose].push({lp, player});
        }
      }
    }
  }
  for (int player = 0; player < 2; player++) {
    for (int i = 1; i < n; i++) {
      if (vis[win][i][player])
        cout << "Win ";
      else if (vis[loose][i][player])
        cout << "Lose ";
      else
        cout << "Loop ";
    }
    cout << endl;
  }
  return 0;
}
