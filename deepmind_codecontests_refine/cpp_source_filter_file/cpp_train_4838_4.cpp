#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10, MOD = 1e9 + 7;
int lenT, lenS, phi[MAXN], phiS[MAXN], dp[MAXN], ac[MAXN], acc[MAXN];
string s, t;
void kmp() {
  lenT = t.size();
  lenS = s.size();
  phi[0] = -1;
  for (int i = 1, k = -1; i <= lenT; ++i) {
    if (k >= 0 && t[k] != t[i - 1]) k = phi[k];
    phi[i] = ++k;
  }
  for (int i = 1, k = 0; i <= lenS; ++i) {
    if (k >= 0 && t[k] != s[i - 1]) k = phi[k];
    phiS[i] = ++k;
    if (k == lenT) k = phi[k];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> t;
  kmp();
  for (int i = 1; i <= lenS; ++i) {
    if (phiS[i] != lenT)
      dp[i] = dp[i - 1];
    else
      dp[i] = (acc[i - lenT] + i - lenT + 1) % MOD;
    ac[i] = (ac[i - 1] + dp[i]) % MOD;
    acc[i] = (acc[i - 1] + ac[i]) % MOD;
  }
  cout << ac[lenS] << '\n';
  return 0;
}
