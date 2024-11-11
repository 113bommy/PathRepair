#include <bits/stdc++.h>
using namespace std;
const int N = 7e3 + 10;
int n, k[2], e[2][N], cnt[2][N];
bool vis[2][N], win[2][N];
void dfs(int now, int pos) {
  if (vis[now][pos]) return;
  vis[now][pos] = 1;
  int next = now ^ 1;
  for (int i = 1; i <= k[next]; i++) {
    int pre = (pos - e[next][i] + n - 1) % n + 1;
    if (pre == 1) continue;
    if (!win[now][pos]) {
      win[next][pre] = 1;
      dfs(next, pre);
    } else if (++cnt[next][pre] == k[next]) {
      win[next][pre] = 0;
      dfs(next, pre);
    }
  }
}
signed main() {
  cin >> n;
  for (int now = 0; now <= 1; now++) {
    cin >> k[now];
    for (int i = 1; i <= k[now]; i++) cin >> e[now][i];
  }
  dfs(0, 1);
  dfs(1, 1);
  for (int now = 0; now <= 1; now++, cout << " " << endl)
    for (int i = 2; i <= n; i++, cout << " ")
      if (vis[now][i])
        cout << (win[now][i] ? "Win" : "Lose");
      else
        cout << "Loop";
}
