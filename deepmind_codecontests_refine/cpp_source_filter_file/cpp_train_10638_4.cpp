#include <bits/stdc++.h>
using namespace std;
const int maxmask = (1 << 20);
string s;
bool exist[maxmask];
int moze;
int koliko[25];
int mask;
int dp[maxmask];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  for (int i = 1; i <= min(20, (int)s.size()); i++) {
    memset(koliko, 0, sizeof koliko);
    moze = 0;
    mask = 0;
    for (int j = 0; j < i; j++) {
      int slovo = s[j] - 'a';
      koliko[slovo]++;
      if (koliko[slovo] >= 2) moze++;
      mask |= (1 << slovo);
    }
    if (!moze) {
      exist[mask] = 1;
      dp[mask] = i;
    }
    for (int j = 1; j <= s.size() - i; j++) {
      int slovo0 = s[j - 1] - 'a';
      koliko[slovo0]--;
      if (koliko[slovo0] == 1) moze--;
      if (koliko[slovo0] == 0) mask -= (1 << slovo0);
      int slovo1 = s[j + i - 1] - 'a';
      koliko[slovo1]++;
      if (koliko[slovo1] >= 2) moze++;
      mask |= (1 << slovo1);
      if (!moze) {
        exist[mask] = 1;
        dp[mask] = i;
      }
    }
  }
  for (int i = 1; i < (1 << 20); i++)
    for (int j = 0; j < 20; j++)
      if (i & (1 << j)) dp[i] = max(dp[i], dp[i ^ (1 << j)]);
  int sol = 0;
  for (int i = 0; i < (1 << 20); i++)
    if (exist[i]) sol = max(sol, dp[i] + dp[(1 << 20) - 1 - i]);
  cout << sol;
}
