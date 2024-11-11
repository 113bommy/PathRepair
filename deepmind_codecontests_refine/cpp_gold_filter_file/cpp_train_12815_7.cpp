#include <bits/stdc++.h>
using namespace std;
const int MN = 50, inf = 1000000005, mod = 1000000007;
const long long INF = 1000000000000000005LL;
long long dp[MN][MN];
int pref[MN][2];
char S[MN];
int l;
int doklej(int p, string C, bool acc_end) {
  for (auto c : C) {
    if (p == l) return -1;
    p = pref[p][c - '0'];
  }
  if (!acc_end && p == l) return -1;
  return p;
}
void licz_dp(string suf, int N) {
  for (int i = 0; i <= N; ++i)
    for (int j = 0; j <= l; ++j) dp[i][j] = 0LL;
  int sl = suf.length();
  int p = doklej(0, suf, false);
  assert(p != -1);
  dp[sl][p] = 1LL;
  for (int i = sl; i < N; ++i) {
    for (int j = 0; j < l; ++j) {
      int ze = doklej(j, "0", false);
      int je = doklej(j, "1", false);
      if (ze != -1) dp[i + 1][ze] += dp[i][j];
      if (je != -1) dp[i + 1][je] += dp[i][j];
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", S + 1);
  l = strlen(S + 1);
  string SS, T, J, Z;
  SS = '#';
  for (int i = 1; i <= l; ++i) SS += S[i];
  for (int i = 0; i < l; ++i) {
    Z = T + '0';
    J = T + '1';
    for (int j = i + 1; j > 0; --j) {
      string P = SS.substr(1, j);
      if (!pref[i][0] && P == Z.substr(i + 1 - j, j)) pref[i][0] = j;
      if (!pref[i][1] && P == J.substr(i + 1 - j, j)) pref[i][1] = j;
    }
    T += S[i + 1];
  }
  long long res = 0LL;
  for (int i = 1; i + l - 1 <= n; ++i) {
    long long p2 = (1LL << (n - i - l + 1));
    licz_dp("", i - 1);
    for (int j = 0; j < l; ++j)
      if (doklej(j, SS.substr(1, l), true) != -1) res += dp[i - 1][j] * p2;
  }
  int it = 1;
  for (int i = n - l + 2; i <= n; ++i) {
    string suf = SS.substr(l - it + 1, it);
    licz_dp(suf, n - l + it);
    for (int j = 0; j < l; ++j)
      if (doklej(j, SS.substr(1, l), true) != -1) res += dp[n - l + it][j];
    ++it;
  }
  printf("%lld", res);
}
