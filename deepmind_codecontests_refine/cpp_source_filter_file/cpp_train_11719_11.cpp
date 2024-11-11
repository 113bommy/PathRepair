#include <bits/stdc++.h>
using namespace std;
string s;
int k, n, g[27][27];
int dp[101][101][26];
int go(int pos, int last, int k) {
  if (k < 0) return -(1e8);
  if (pos == n) return 0;
  if (dp[pos][last][k] != -1) return dp[pos][last][k];
  int res = -(1e8);
  for (int i = 0; i < 26; i++) {
    res = max(res, g[last][i] + go(pos + 1, i, k - ((s[pos] - 'a') != i)));
  }
  return dp[pos][last][k] = res;
}
int main() {
  cin >> s;
  n = s.size();
  k = ({
    int t;
    scanf("%d", &t);
    t;
  });
  int z = ({
    int t;
    scanf("%d", &t);
    t;
  });
  for (int i = 0; i < z; i++) {
    char cx, cy;
    int cz;
    cin >> cx >> cy >> cz;
    g[cx - 'a'][cy - 'a'] = cz;
  }
  int res = -(1e8);
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < 26; i++) {
    int K = k;
    if ((s[0] - 'a') != i) K--;
    res = max(res, go(1, i, K));
  }
  cout << res << endl;
}
