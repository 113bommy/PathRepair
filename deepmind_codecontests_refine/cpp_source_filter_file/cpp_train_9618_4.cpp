#include <bits/stdc++.h>
using namespace std;
char buf[5010];
int dp[5010], vis[5010], g[5010], can[5010];
void lemon() {
  dp[0] = 0;
  for (int i = (1); i <= (5000); i++) {
    memset(vis, 0, sizeof vis);
    for (int k = (0); k <= (i); k++)
      vis[dp[max(k - 2, 0)] ^ dp[max(i - k - 1, 0)]] = 1;
    int z = 0;
    while (vis[z]) z++;
    dp[i] = z;
  }
  scanf("%s", buf + 1);
  int n = strlen(buf + 1);
  if (n <= 2) {
    cout << "Second" << endl;
    return;
  }
  for (int i = (2); i <= (n - 1); i++)
    if (buf[i - 1] == buf[i + 1]) can[i] = 1;
  int combo = 0;
  for (int i = (2); i <= (n); i++)
    if (!can[i]) {
      g[combo]++;
      combo = 0;
    } else
      combo++;
  int final = 0;
  for (int i = (1); i <= (5000); i++)
    if (g[i] % 2) final ^= dp[i];
  if (!final) {
    cout << "Second" << endl;
    return;
  }
  cout << "First" << endl;
  combo = 0;
  for (int i = (2); i <= (n); i++)
    if (!can[i]) {
      for (int k = (0); k <= (combo); k++)
        if ((final ^ dp[combo] ^ dp[max(k - 2, 0)] ^
             dp[max(combo - k - 1, 0)]) == 0) {
          cout << i - combo + k << endl;
          return;
        }
      combo = 0;
    } else
      combo++;
}
int main() {
  ios::sync_with_stdio(true);
  lemon();
  return 0;
}
