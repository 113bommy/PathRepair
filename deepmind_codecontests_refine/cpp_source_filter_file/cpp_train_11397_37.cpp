#include <bits/stdc++.h>
using namespace std;
long long dp[1005][101][2];
long long pw[1005];
int n, m, k;
void Set() {
  pw[0] = 1;
  for (int i = 1; i < 1001; i++) {
    pw[i] = pw[i - 1] * 10;
    pw[i] %= m;
  }
}
long long cal(int cp, int cm, int cf) {
  if (dp[cp][cm][cf] != -1) return dp[cp][cm][cf];
  if (cp == 0 && cm == 0) return 1;
  if (cp == 0) return 0;
  dp[cp][cm][cf] = 0;
  int st = 0;
  if (cp == 1) st = 1;
  for (int i = st; i < 10; i++) {
    int nm = cm + i * pw[n - cp];
    int nf = 0;
    if (cf == 1 || nm >= k) nf = 1;
    if (cf == 1 || nm >= k) nm %= k;
    if (cf == 1 && cm == 0) nm = 0;
    dp[cp][cm][cf] += cal(cp - 1, nm, nf);
    dp[cp][cm][cf] %= m;
  }
  return dp[cp][cm][cf];
}
int main() {
  cin >> n >> k >> m;
  Set();
  memset((dp), -1, sizeof((dp)));
  cout << cal(n, 0, 0) << endl;
  return 0;
}
