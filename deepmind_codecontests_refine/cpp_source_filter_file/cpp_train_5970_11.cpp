#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
const int N = 1000002;
int a, b, c, d, i, j, n, m, k, tot, now, last;
int nx[N][26], sib[N], pr[N], fir[N];
int cnt[N], en[N];
char str[502];
int num[2][2001];
int dp[2][2001][2001];
vector<int> lev[502];
int dfs(int v, int h = 0) {
  lev[h].push_back(v);
  for (int _n((26) - 1), i(0); i <= _n; i++) {
    if (nx[v][i] != -1) cnt[v] += dfs(nx[v][i], h + 1);
  }
  return cnt[v];
}
inline int g(int v, int c) {
  if (c < 0) return -1000000000;
  if (v == -1 && !c) return 0;
  if (v == -1) return -1000000000;
  if (!c) return 0;
  return dp[last][num[last][v]][c];
}
inline int f(int v, int c) {
  if (c < 0) return -1000000000;
  if (v == -1 && !c) return 0;
  if (v == -1) return -1000000000;
  if (!c) return 0;
  return dp[now][num[now][v]][c];
}
int rec(int v, int c) {
  if (c < 0) return -1000000000;
  if (v == -1 && !c) return 0;
  if (v == -1) return -1000000000;
  if (!c) return 0;
  int ans = 0, fr = cnt[v] - en[v];
  for (int i = (min(cnt[v], c)), _b = (0); i >= _b; i--) {
    int lf = c - i;
    if (lf && sib[v] == -1) break;
    ans = max(ans, i * (i - 1) / 2 + g(fir[v], min(fr, i)) + f(sib[v], lf));
  }
  return dp[now][num[now][v]][c] = ans;
}
int main() {
  memset(nx, -1, sizeof(nx));
  pr[0] = -1;
  k = 1;
  scanf("%d%d", &n, &tot);
  for (int _n((n)-1), i(0); i <= _n; i++) {
    scanf("%s", str);
    m = (int)strlen(str);
    a = 0;
    for (int _n((m)-1), i(0); i <= _n; i++) {
      if (nx[a][str[i] - 'a'] == -1) {
        nx[a][str[i] - 'a'] = k++;
        pr[k - 1] = a;
      }
      a = nx[a][str[i] - 'a'];
    }
    ++cnt[a];
    ++en[a];
  }
  for (int _n((k)-1), i(0); i <= _n; i++) {
    fir[i] = -1;
    for (int j = (25), _b = (0); j >= _b; j--) {
      if (nx[i][j] == -1) continue;
      sib[nx[i][j]] = fir[i];
      fir[i] = nx[i][j];
    }
  }
  dfs(0);
  memset(dp, -1, sizeof(dp));
  now = 0, last = 1;
  for (int h = (500), _b = (1); h >= _b; h--) {
    if (lev[h].empty()) continue;
    now ^= 1;
    last ^= 1;
    for (int _n(((int)((lev[h]).size())) - 1), i(0); i <= _n; i++)
      num[now][lev[h][i]] = i;
    for (int i = ((int)((lev[h]).size()) - 1), _b = (0); i >= _b; i--) {
      int v = lev[h][i], p = pr[v];
      for (int _n((k + 1) - 1), j(0); j <= _n; j++) {
        if (j > cnt[p]) break;
        rec(v, j);
      }
    }
  }
  int ans = dp[now][0][tot];
  printf("%d\n", ans);
}
