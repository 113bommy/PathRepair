#include <bits/stdc++.h>
using namespace std;
namespace FGF {
int n, m;
const int N = 55, M = N * N, mo = 1e9 + 7;
vector<int> s[M];
vector<int>::iterator it;
vector<int>::reverse_iterator rit;
int g[N][N], is[M], u[M], v[M], w[M], f[N << 1][N][2], cnt, head[N];
queue<int> q;
struct edg {
  int to, nxt, w;
  bool e, s;
} e[M << 1];
void add(int u, int v, bool s, bool ed, int w) {
  e[++cnt].to = v;
  e[cnt].nxt = head[u];
  e[cnt].e = ed, e[cnt].s = s, e[cnt].w = w;
  head[u] = cnt;
}
void work() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    is[i] = -1;
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
    for (int j = 1, x; j <= w[i]; j++) scanf("%d", &x), s[i].push_back(x);
    g[u[i]][v[i]] = i;
    for (int j = 0; j < w[i] - 1; j++)
      if (s[i][j] == u[i] && s[i][j + 1] == v[i]) is[i] = j;
  }
  for (int i = 1; i <= m; i++) {
    if (~is[i]) {
      int len = 1, S, E;
      while (q.size()) q.pop();
      for (int j = is[i] - 1; j >= 0; j--) q.push(s[i][j]);
      S = u[i];
      while (q.size()) {
        int x = q.front();
        q.pop();
        len++;
        if (len > 2 * n) goto END;
        if (!g[x][S]) goto END;
        if (s[g[x][S]].size())
          for (rit = s[g[x][S]].rbegin(); rit != s[g[x][S]].rend(); rit++)
            q.push(*rit);
        S = x;
      }
      while (q.size()) q.pop();
      for (int j = is[i] + 2; j < w[i]; j++) q.push(s[i][j]);
      E = v[i];
      while (q.size()) {
        int x = q.front();
        q.pop();
        len++;
        if (len > 2 * n) goto END;
        if (!g[E][x]) goto END;
        if (s[g[E][x]].size())
          for (it = s[g[E][x]].begin(); it != s[g[E][x]].end(); it++)
            q.push(*it);
        E = x;
      }
      add(S, E, 1, 1, len);
    } else if (s[i].size() && *s[i].rbegin() == u[i]) {
      int len = 1, S = u[i], E = v[i];
      while (q.size()) q.pop();
      for (int j = w[i] - 2; j >= 0; j--) q.push(s[i][j]);
      while (q.size()) {
        int x = q.front();
        q.pop();
        len++;
        if (len > 2 * n) goto END;
        if (!g[x][S]) goto END;
        if (s[g[x][S]].size())
          for (rit = s[g[x][S]].rbegin(); rit != s[g[x][S]].rend(); rit++)
            q.push(*rit);
        S = x;
      }
      add(S, E, 1, 0, len);
    } else if (s[i].size() && *s[i].begin() == v[i]) {
      int len = 1, S = u[i], E = v[i];
      while (q.size()) q.pop();
      for (int j = 1; j < w[i]; j++) q.push(s[i][j]);
      while (q.size()) {
        int x = q.front();
        q.pop();
        len++;
        if (len > 2 * n) goto END;
        if (!g[E][x]) goto END;
        if (s[g[E][x]].size())
          for (it = s[g[E][x]].begin(); it != s[g[E][x]].end(); it++)
            q.push(*it);
        E = x;
      }
      add(S, E, 0, 1, len);
    }
    if (w[i] == 0) add(u[i], v[i], 0, 0, 1);
  END:;
  }
  for (int i = 1; i <= n; i++) f[0][i][0] = 1;
  for (int l = 0; l <= 2 * n; l++)
    for (int x = 1; x <= n; x++)
      for (int i = head[x]; i; i = e[i].nxt)
        (f[l + e[i].w][e[i].to][e[i].e] += f[l][x][e[i].s ^ 1]) %= mo;
  for (int l = 1; l <= 2 * n; l++) {
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + f[l][i][1]) % mo;
    printf("%d\n", ans);
  }
}
}  // namespace FGF
int main() {
  FGF::work();
  return 0;
}
