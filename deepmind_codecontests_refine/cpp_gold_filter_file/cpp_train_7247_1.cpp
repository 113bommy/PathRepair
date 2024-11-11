#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int maxn = 1010;
struct item {
  int to[4];
  int go[4];
  int p, pch;
  int isterm;
  int end;
  int len;
  int maxterm;
  int link;
};
item t[maxn];
int mem = 0;
int root;
int getnode() {
  memset(t[mem].to, -1, sizeof(t[mem].to));
  memset(t[mem].go, -1, sizeof(t[mem].go));
  t[mem].p = -1;
  t[mem].pch = -1;
  t[mem].isterm = -1;
  t[mem].end = 0;
  t[mem].len = -1;
  t[mem].maxterm = -1;
  t[mem].link = -1;
  return mem++;
}
void addstring(string s) {
  int cur = root;
  for (int i = 0; i < (int)s.length(); ++i) {
    int ch = 0;
    if (s[i] == 'G') ch = 1;
    if (s[i] == 'T') ch = 2;
    if (s[i] == 'C') ch = 3;
    if (t[cur].to[ch] != -1)
      cur = t[cur].to[ch];
    else {
      int nn = getnode();
      t[nn].p = cur;
      t[nn].pch = ch;
      t[nn].len = t[cur].len + 1;
      t[cur].to[ch] = nn;
      cur = nn;
    }
  }
  t[cur].end = 1;
}
int go(int st, int ch);
int getlink(int st) {
  if (t[st].link == -1) {
    if (t[st].p == root)
      t[st].link = root;
    else
      t[st].link = go(getlink(t[st].p), t[st].pch);
  }
  return t[st].link;
}
int go(int st, int ch) {
  if (t[st].go[ch] == -1) {
    if (t[st].to[ch] != -1)
      t[st].go[ch] = t[st].to[ch];
    else if (st == root)
      t[st].go[ch] = root;
    else
      t[st].go[ch] = go(getlink(st), ch);
  }
  return t[st].go[ch];
}
bool isterm(int st) {
  if (t[st].isterm == -1) {
    if (t[st].end)
      t[st].isterm = 1;
    else
      t[st].isterm = isterm(getlink(st));
  }
  return t[st].isterm;
}
int maxterm(int st) {
  if (t[st].maxterm == -1) {
    if (!isterm(st))
      t[st].maxterm = 0;
    else if (t[st].end)
      t[st].maxterm = t[st].len;
    else
      t[st].maxterm = maxterm(getlink(st));
  }
  return t[st].maxterm;
}
const int mod = 1000000009;
int dp[maxn][110][12] = {};
int main() {
  root = getnode();
  t[root].isterm = 0;
  t[root].link = 0;
  t[root].len = 0;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    addstring(s);
  }
  dp[0][root][0] = 1;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j < mem; ++j)
      for (int k = 0; k <= 10; ++k) {
        for (int ch = 0; ch < 4; ++ch) {
          int tost = go(j, ch);
          int tobad = k + 1;
          if (maxterm(tost) >= tobad) tobad = 0;
          int tolen = i + 1;
          (dp[tolen][tost][tobad] += dp[i][j][k]) %= mod;
        }
      }
  int ans = 0;
  for (int i = 0; i < mem; ++i) (ans += dp[n][i][0]) %= mod;
  printf("%d\n", ans);
  return 0;
}
