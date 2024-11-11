#include <bits/stdc++.h>
using namespace std;
const int N = 4005, M = 1000005;
int n, kk, trie[M][26], ptr, cnt[M], sz[N];
char s[N];
void insert(char *s) {
  int l = strlen(s), cur = 0;
  for (int i = 0; i < l; i++) {
    if (!trie[cur][s[i] - 'a']) trie[cur][s[i] - 'a'] = ++ptr, ++sz[cur];
    cur = trie[cur][s[i] - 'a'];
  }
  ++cnt[cur];
}
vector<int> v[N];
int dep[N], cc[N], idx;
void dfs1(int pos, int dd, int lst) {
  if (pos == 1 || sz[pos] > 1 || cnt[pos])
    dep[++idx] = dd, v[lst].push_back(idx), lst = idx, cc[idx] = cnt[pos];
  for (int i = 0; i < 26; i++)
    if (trie[pos][i]) dfs1(trie[pos][i], dd + 1, lst);
}
int dp[N][N];
void dfs2(int pos, int fa) {
  for (auto &i : v[pos]) {
    dfs2(i, pos);
    cc[pos] += cc[i];
    for (int j = min(cc[pos], kk); j > 0; --j)
      for (int k = min(cc[i], j); k > 0; --k)
        dp[pos][j] = max(dp[pos][j], dp[i][k] + dp[pos][j - k]);
  }
  for (int i = 1; i <= cc[pos]; i++)
    dp[pos][i] += i * (i - 1) / 2 * (dep[pos] - dep[fa]);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> kk;
  for (int i = 1; i <= n; i++) cin >> s, insert(s);
  dfs1(0, 0, 0);
  dfs2(1, 0);
  cout << dp[1][kk] << endl;
  return 0;
}
