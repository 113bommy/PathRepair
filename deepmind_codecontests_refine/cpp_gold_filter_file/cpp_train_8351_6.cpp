#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void program();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  program();
}
const int MX = 14, BIT = 1 << MX, BIT2 = (1 << (MX - 1));
int n;
string s[MX];
bitset<MX> knows[MX];
int x;
vector<long long> dp[BIT][MX];
int pp[BIT];
void program() {
  cin >> n;
  for (int i = int(0); i < int(n); i++) cin >> s[i];
  for (int i = int(0); i < int(n); i++) knows[i].reset();
  for (int i = int(0); i < int(n); i++)
    for (int j = int(0); j < int(n); j++)
      if (s[i][j] == '1') knows[i][j] = 1;
  int bit = (1 << n);
  for (int i = int(0); i < int(BIT); i++) pp[i] = 0;
  for (int i = int(0); i < int(MX); i++) pp[1 << i] = i;
  for (int used = int(0); used < int(bit); used++) {
    int cnt = 0;
    for (int i = int(0); i < int(n); i++)
      if (used & (1 << i)) cnt++;
    if (cnt == 0) continue;
    int mxX = (1 << (cnt - 1));
    for (int i = int(0); i < int(n); i++) dp[used][i].assign(mxX + 1, 0);
    for (int i = int(0); i < int(n); i++)
      if (used == (1 << i)) dp[used][i][0] = 1;
  }
  for (int used = int(0); used < int(bit); used++) {
    int cnt = 0;
    for (int i = int(0); i < int(n); i++)
      if (used & (1 << i)) cnt++;
    if (cnt == 0) continue;
    int mxX = (1 << (cnt - 1));
    for (int x = int(0); x < int(mxX); x++) {
      int u = used;
      while (u) {
        int i = pp[u & -u];
        u -= u & -u;
        if (!dp[used][i][x]) continue;
        int v = (bit - 1) ^ used;
        while (v) {
          int j = pp[v & -v];
          v -= v & -v;
          int nx = x;
          if (knows[i][j]) nx |= (1 << (cnt - 1));
          dp[used | (1 << j)][j][nx] += dp[used][i][x];
        }
      }
    }
  }
  for (int x = int(0); x < int((1 << (n - 1))); x++) {
    long long ans = 0;
    for (int i = int(0); i < int(n); i++) ans += dp[bit - 1][i][x];
    cout << (x == 0 ? "" : " ") << ans;
  }
  cout << endl;
}
