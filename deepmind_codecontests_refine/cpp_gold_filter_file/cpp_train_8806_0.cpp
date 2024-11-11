#include <bits/stdc++.h>
using namespace std;
const int p = 257;
const long long mods = 1610612741;
const int maxn = 100010;
long long hash1[maxn][2];
char s[maxn];
char t[maxn];
int slen, tlen;
int x;
long long pp[maxn];
void gethash(char s[], int type, int N) {
  hash1[0][type] = 0;
  for (int i = 1; i <= N; i++) {
    hash1[i][type] = (hash1[i - 1][type] * p + s[i]) % mods;
  }
  return;
}
void init() {
  pp[0] = 1;
  for (int i = 1; i <= maxn - 5; i++) {
    pp[i] = (pp[i - 1] * p) % mods;
  }
}
long long getsubhash(int L, int R, int type) {
  if (R < L) return -1;
  return (hash1[R][type] - (hash1[L - 1][type] * pp[R - L + 1]) % mods + mods) %
         mods;
}
int dp[maxn][35];
int getlcp(int spos, int tpos) {
  int ll = 0;
  int rr = min(slen - spos + 1, tlen - tpos + 1);
  while (rr - ll > 1) {
    int mid = (rr + ll + 1) / 2;
    if (getsubhash(spos, spos + mid - 1, 0) ==
        getsubhash(tpos, tpos + mid - 1, 1))
      ll = mid;
    else
      rr = mid;
  }
  if (getsubhash(spos, spos + rr - 1, 0) == getsubhash(tpos, tpos + rr - 1, 1))
    return rr;
  else
    return ll;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> slen;
  cin >> s + 1;
  cin >> tlen;
  cin >> t + 1;
  cin >> x;
  init();
  gethash(s, 0, slen);
  gethash(t, 1, tlen);
  for (int j = 0; j <= x; j++) {
    dp[0][j] = 1;
  }
  for (int i = 1; i <= slen; i++) {
    for (int j = 0; j <= x; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      int lcp = getlcp(i, dp[i][j]);
      dp[i + lcp - 1][j + 1] = max(dp[i + lcp - 1][j + 1], dp[i][j] + lcp);
    }
  }
  bool flag = false;
  for (int i = 0; i <= x; i++) {
    if (dp[slen][i] > tlen) {
      flag = true;
      break;
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
