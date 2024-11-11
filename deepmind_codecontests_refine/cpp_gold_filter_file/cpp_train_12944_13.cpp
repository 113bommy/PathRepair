#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005, MAXL = 505;
const long long INF = 1e15;
int n;
char ss[MAXL];
string s[MAXN];
int lcp[MAXN];
long long dp[2 * MAXN][MAXN];
map<pair<int, int>, int> M;
int indx = 0;
int daj_ind(int a, int b) {
  if (M.find(pair<int, int>(a, b)) != M.end()) return M[pair<int, int>(a, b)];
  assert(indx < 2 * MAXN);
  return M[pair<int, int>(a, b)] = indx++;
}
long long rek(int l, int r, int ind, int k) {
  assert(l <= r);
  if (dp[ind][k] != INF) return dp[ind][k];
  if (l == r) {
    dp[ind][0] = dp[ind][1] = 0;
    for (int i = (2); i < (MAXN); i++) dp[ind][i] = -INF;
    return dp[ind][k];
  }
  pair<int, int> mn = {MAXN, MAXN};
  for (int i = (l); i < (r); i++) mn = min(mn, pair<int, int>(lcp[i], i));
  int l_ind = daj_ind(l, mn.second);
  int r_ind = daj_ind(mn.second + 1, r);
  int sz_l = mn.second - l + 1;
  int sz_r = r - mn.second;
  for (int i = 0; i < MAXN; i++) dp[ind][i] = -INF;
  for (int lijevo = 0; lijevo < sz_l + 1; lijevo++) {
    for (int desno = 0; desno < sz_r + 1; desno++) {
      dp[ind][lijevo + desno] =
          max(dp[ind][lijevo + desno], rek(l, mn.second, l_ind, lijevo) +
                                           rek(mn.second + 1, r, r_ind, desno) +
                                           lijevo * desno * mn.first);
    }
  }
  return dp[ind][k];
}
int daj_lc(string &s1, string &s2) {
  int len = (int)min(s1.size(), s2.size()), ret = 0;
  for (; ret < len && s1[ret] == s2[ret]; ret++)
    ;
  return ret;
}
int K;
void load() {
  scanf("%d%d", &n, &K);
  for (int i = 0; i < n; i++) {
    scanf(" %s", ss);
    s[i] = ss;
  }
}
int main() {
  load();
  sort(s, s + n);
  for (int i = 0; i < n - 1; i++) lcp[i] = daj_lc(s[i], s[i + 1]);
  for (int i = 0; i < 2 * MAXN; i++)
    for (int j = 0; j < MAXN; j++) dp[i][j] = INF;
  printf("%lld\n", rek(0, n - 1, daj_ind(0, n - 1), K));
  return 0;
}
