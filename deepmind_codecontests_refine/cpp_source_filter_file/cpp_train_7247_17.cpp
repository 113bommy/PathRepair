#include <bits/stdc++.h>
using namespace std;
int dp[1005][105][15];
char s[1005];
int son[105][26], cnt, f[105], val[105], dep[105];
inline void insert(char *s) {
  int len = strlen(s), t = 0;
  for (int i = 0; i < len; ++i) {
    int c = s[i] - 'A';
    if (!son[t][c]) {
      son[t][c] = ++cnt;
      dep[cnt] = dep[t] + 1;
    }
    t = son[t][c];
  }
  val[t] = dep[t];
}
void AC() {
  f[0] = 0;
  queue<int> q;
  for (int i = 0; i < 26; ++i)
    if (son[0][i]) f[son[0][i]] = 0, q.push(son[0][i]);
  while (!q.empty()) {
    int r = q.front();
    q.pop();
    for (int c = 0; c < 26; ++c) {
      int u = son[r][c];
      if (!u) {
        son[r][c] = son[f[r]][c];
        continue;
      }
      q.push(u);
      int v = f[r];
      f[u] = son[v][c];
      val[u] = max(val[u], val[f[u]]);
    }
  }
}
int solve(int n, int pos, int pre) {
  if (dp[n][pos][pre] != -1) return dp[n][pos][pre];
  if (n == 0) return dp[n][pos][pre] = (val[pos] >= pre);
  int ret = 0;
  for (int i = 0; i < 26; ++i) {
    int npos = son[pos][i], npre = val[pos] >= pre ? 1 : pre + 1;
    if (npos && dep[npos] >= npre)
      ret = (ret + solve(n - 1, npos, npre)) % 10007;
  }
  return dp[n][pos][pre] = ret;
}
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    memset(son, 0, sizeof(son));
    memset(f, 0, sizeof(f));
    memset(val, 0, sizeof(val));
    memset(dep, 0, sizeof(dep));
    cnt = 0;
    for (int i = 0; i < k; ++i) {
      scanf("%s", s);
      insert(s);
    }
    AC();
    memset(dp, -1, sizeof(dp));
    cout << solve(n, 0, 0) << endl;
  }
  return 0;
}
