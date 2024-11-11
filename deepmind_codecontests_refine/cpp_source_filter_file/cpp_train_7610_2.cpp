#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int INF = 1e9;
char s[N];
int n, id, la, len[N], ch[N][26], lnk[N];
void init() {
  id = la = 1;
  len[1] = lnk[1] = 0;
}
void append(int c) {
  int u = ++id, p = la;
  len[u] = len[la] + 1;
  for (; p && !ch[p][c]; p = lnk[p]) ch[p][c] = u;
  if (!p)
    lnk[u] = 1;
  else {
    int q = ch[p][c];
    if (len[q] == len[p] + 1)
      lnk[u] = q;
    else {
      int q0 = ++id;
      len[q0] = len[p] + 1;
      for (int i = 0; i <= 25; ++i) ch[q0][i] = ch[q][i];
      lnk[q0] = lnk[q];
      lnk[q] = lnk[u] = q0;
      for (; p && ch[p][c] == q; p = lnk[p]) ch[p][c] = q0;
    }
  }
  la = u;
}
int z[N];
bool f[N], g[N], h[N];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  reverse(s + 1, s + n + 1);
  init();
  for (int i = 1; i <= n; ++i) append(s[i] -= 'a');
  int m = sqrt(2 * n) + 0.5;
  if (n <= int(1e5) || 1) {
    for (int i = 1; i <= n; ++i) z[i] = ch[1][s[i]];
    for (int i = 1; i <= n; ++i) f[i] = 1;
    int ans = 1;
    for (int i = 2; i <= m; ++i) {
      copy(f + 1, f + n + 1, g + 1);
      for (int j = 1; j <= id; ++j) h[j] = 0;
      for (int j = 1; j <= n; ++j) {
        if (j - i >= i - 1) h[z[j - i - (i - 1) + 1]] |= g[j - i];
        f[j] = j >= i ? (h[z[j - (i - 1) + 1]] || h[z[j - (i - 1)]]) : 0;
      }
      for (int j = 1; j <= n; ++j)
        if (f[j]) {
          ans = i;
          break;
        }
      if (ans != i) break;
      for (int j = 1; j <= n - i + 1; ++j) z[j] = ch[z[j]][s[j + i - 1]];
    }
    printf("%d\n", ans);
  }
  return 0;
}
