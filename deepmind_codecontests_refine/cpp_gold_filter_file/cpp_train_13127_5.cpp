#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, ne[N][26], la[N][26], g[N];
char s[N];
bool vis[N][26];
inline bool& Vis(int l, int r) { return vis[l][s[r + 1] - 'a']; }
int f[N][26];
inline int& F(int l, int r) { return f[l][s[r + 1] - 'a']; }
int ask_l, ask_r, rm[N << 1];
stack<int> sta;
inline int Calc(int l, int r) {
  if (l > r) return 0;
  if (l > 1 && r < n && ne[l][s[l - 1] - 'a'] > r &&
      la[r][s[r + 1] - 'a'] < l) {
    if (Vis(l, r)) return F(l, r);
    Vis(l, r) = 1;
    int mask = 0;
    for (int i = 0; i < 26; ++i)
      if (ne[l][i] <= r) {
        int sg = 0, pos = l;
        while (ne[pos][i] <= r) {
          sg ^= Calc(pos, ne[pos][i] - 1);
          pos = ne[pos][i] + 1;
        }
        sg ^= Calc(pos, r);
        if (sg < 26) mask |= 1 << sg;
      }
    for (int i = 0; i <= 26; ++i)
      if ((mask >> i & 1) == 0) return F(l, r) = i;
  } else {
    int mask = 0, id;
    if (l == ask_l) {
      id = r;
    } else if (r == ask_r) {
      id = l + n + 1;
    } else
      assert(0);
    if (rm[id] != -1) return rm[id];
    sta.push(id);
    for (int i = 0; i < 26; ++i)
      if (ne[l][i] <= r) {
        int x = ne[l][i], y = la[r][i];
        int sg = Calc(l, x - 1) ^ Calc(y + 1, r) ^ g[y] ^ g[x];
        if (sg < 26) mask |= 1 << sg;
      }
    for (int i = 0; i <= 26; ++i)
      if ((mask >> i & 1) == 0) return rm[id] = i;
  }
  assert(0);
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 0; i < 26; ++i) ne[n + 1][i] = n + 1;
  for (int i = n; i; --i) {
    memcpy(ne[i], ne[i + 1], sizeof ne[i]);
    ne[i][s[i] - 'a'] = i;
  }
  for (int i = 0; i < 26; ++i) la[0][i] = 0;
  for (int i = 1; i <= n; ++i) {
    memcpy(la[i], la[i - 1], sizeof la[i]);
    la[i][s[i] - 'a'] = i;
  }
  for (int i = 1; i <= n; ++i) {
    int d = s[i] - 'a';
    if (la[i - 1][d]) g[i] = g[la[i - 1][d]] ^ Calc(la[i - 1][d] + 1, i - 1);
  }
  scanf("%d", &m);
  memset(rm, -1, sizeof rm);
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    ask_l = x;
    ask_r = y;
    puts(Calc(x, y) ? "Alice" : "Bob");
    while (!sta.empty()) rm[sta.top()] = -1, sta.pop();
  }
  return 0;
}
