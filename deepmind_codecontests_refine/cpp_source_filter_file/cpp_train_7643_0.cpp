#include <bits/stdc++.h>
using namespace std;
int n;
const int inf = 99999999, P = 1000000007;
int maxdfn, maxcol, m;
int _last[4000005], _next[4000005], x[4000005], y[4000005], e;
int dfn[400005], low[400005], in[400005];
int sta[400005], col[400005], s[400005], z;
int c[200005];
inline void edge(int u, int v) {
  e++;
  x[e] = u;
  y[e] = v;
  _next[e] = _last[u];
  _last[u] = e;
}
int tarjan(int pos) {
  if (dfn[pos]) {
    if (in[pos]) return dfn[pos];
    return inf;
  }
  dfn[pos] = low[pos] = ++maxdfn;
  in[sta[++z] = pos] = 1;
  for (int j = _last[pos]; j != -1; j = _next[j]) {
    low[pos] = min(low[pos], tarjan(y[j]));
  }
  if (dfn[pos] == low[pos]) {
    int j = z;
    maxcol++;
    if (maxcol == 2) {
      puts("NO");
      exit(0);
    }
    while (sta[j] != pos) {
      j--;
    }
    for (int i = j; i <= z; i++) {
      in[sta[i]] = 0;
      col[sta[i]] = maxcol;
    }
    s[maxcol] = z - j + 1;
    z = j - 1;
  }
  return low[pos];
}
int Min[200005], cnt[200005];
int aledge[200005], ot[200005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) _last[i] = -1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int t;
      scanf("%d", &t);
      if (t) {
        edge(i, j);
      }
    }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
  }
  puts("Yes");
  return 0;
}
