#include <bits/stdc++.h>
using namespace std;
const int maxn = 503;
int now[maxn], pre[maxn << 1], son[maxn << 1], v[maxn << 1], tot;
void add(int a, int b, int c) {
  pre[++tot] = now[a];
  now[a] = tot;
  son[tot] = b;
  v[tot] = c;
}
void cc(int a, int b, int c) {
  add(a, b, c);
  add(b, a, c);
}
long long Dis[maxn][maxn];
void GetDis(int st, int x, int fa) {
  for (int p = now[x]; p; p = pre[p])
    if (son[p] != fa)
      Dis[st][son[p]] = Dis[st][x] + v[p], GetDis(st, son[p], x);
}
vector<int> sons[maxn];
int Fa[maxn][maxn];
int sz[maxn], col[maxn], Dep[maxn];
void GetOrd(int x, int fa) {
  sz[x] = !col[x];
  Fa[x][Dep[x]] = x;
  for (int i = 1; i < Dep[x]; ++i) Fa[x][i] = Fa[fa][i];
  sons[x].push_back(x);
  for (int p = now[x]; p; p = pre[p])
    if (son[p] != fa) {
      Dep[son[p]] = Dep[x] + 1;
      GetOrd(son[p], x);
      for (int y : sons[son[p]]) sons[x].push_back(y);
      sz[x] += sz[son[p]];
    }
  sort(sons[x].begin(), sons[x].end(), [&](int a, int b) {
    return make_pair(Dis[x][a], a) < make_pair(Dis[x][b], b);
  });
}
struct Value {
  unsigned char x;
  Value() {}
  Value(int x) : x(x) {}
} V0(0), V1(1), V2(2);
Value operator+(Value a, Value b) {
  if (!a.x || !b.x) return Value(0);
  int t = a.x + b.x - 1;
  if (t > 253) t = 253;
  return Value(t);
}
inline Value max(Value a, Value b) { return a.x > b.x ? a : b; }
int n, Lim;
Value F[maxn][maxn][maxn], G[maxn][maxn][maxn];
void Dp(int x, int fa) {
  for (int p = now[x]; p; p = pre[p])
    if (son[p] != fa) Dp(son[p], x);
  static int S[maxn];
  int N = 0;
  for (int p = now[x]; p; p = pre[p])
    if (son[p] != fa) S[++N] = son[p];
  static Value f[maxn][maxn];
  {
    for (int i = 1; i <= N; ++i) {
      int s = S[i];
      memset(f[s], 0, sizeof(f[s]));
      for (int ss : sons[s])
        for (int j = 0; j <= sz[s]; ++j) f[s][j] = max(f[s][j], F[s][ss][j]);
      for (int ss : sons[s])
        if (Dis[x][ss] <= Lim)
          for (int j = 0; j <= sz[s]; ++j) {
            f[s][j] = max(f[s][j], G[s][ss][j]);
          }
    }
    F[x][x][!col[x]] = V1;
    for (int i = 1, sum = 1; i <= N; ++i) {
      int s = S[i];
      sum += sz[s];
      for (int is = sum; is >= 0; --is)
        for (int i1 = 0; i1 <= sz[s] && i1 <= is; ++i1) {
          if (!i1)
            F[x][x][is] = F[x][x][is - i1] + f[s][i1];
          else
            F[x][x][is] = max(F[x][x][is], F[x][x][is - i1] + f[s][i1]);
        }
    }
  }
  {
    {
      {
        for (int i = 1; i <= N; ++i) {
          int s = S[i];
          memset(f[s], 0, sizeof(f[s]));
          for (int ss : sons[s])
            if (Dis[x][ss] > Lim)
              for (int j = 0; j <= sz[s]; ++j)
                f[s][j] = max(f[s][j], F[s][ss][j]);
        }
        G[x][x][0] = col[x] ? V2 : V1;
        for (int i = 1, sum = 0; i <= N; ++i) {
          int s = S[i];
          sum += sz[s];
          for (int is = sum; is >= 0; --is)
            for (int i1 = 0; i1 <= sz[s] && i1 <= is; ++i1) {
              if (!i1)
                G[x][x][is] = G[x][x][is - i1] + f[s][i1];
              else
                G[x][x][is] = max(G[x][x][is], G[x][x][is - i1] + f[s][i1]);
            }
        }
      }
      for (int i = 1; i <= N; ++i) memset(f[S[i]], 0, sizeof(f[0]));
      int w = (int)sons[x].size() - 1;
      for (int y : sons[x])
        if (x != y) {
          int s = Fa[y][Dep[x] + 1];
          while (w >= 0 && Dis[x][sons[x][w]] > Lim - Dis[x][y]) {
            int ty = sons[x][w--], ts = Fa[ty][Dep[x] + 1];
            for (int j = 0; j <= sz[ts]; ++j)
              f[ts][j] = max(f[ts][j], F[ts][ty][j]);
          }
          if (!col[x])
            for (int j = 0; j <= sz[s]; ++j) G[x][y][j] = G[s][y][j];
          else
            for (int j = 0; j <= sz[s]; ++j) G[x][y][j] = G[s][y][j] + V2;
          for (int i = 1, sum = sz[s]; i <= N; ++i)
            if (S[i] != s) {
              int s = S[i];
              sum += sz[s];
              for (int is = sum; is >= 0; --is)
                for (int i1 = 0; i1 <= sz[s] && i1 <= is; ++i1) {
                  if (!i1)
                    G[x][y][is] = G[x][y][is - i1] + f[s][i1];
                  else
                    G[x][y][is] = max(G[x][y][is], G[x][y][is - i1] + f[s][i1]);
                }
            }
          for (int j = 0; j <= sz[s]; ++j) f[s][j] = max(f[s][j], G[s][y][j]);
        }
    }
    {
      for (int i = 1; i <= N; ++i) memset(f[S[i]], 0, sizeof(f[0]));
      reverse(sons[x].begin(), sons[x].end());
      int w = (int)sons[x].size() - 1;
      for (int y : sons[x])
        if (y != x) {
          int s = Fa[y][Dep[x] + 1];
          while (w >= 0 && Dis[x][sons[x][w]] < Lim - Dis[x][y]) {
            int ty = sons[x][w--], ts = Fa[ty][Dep[x] + 1];
            for (int j = 0; j <= sz[ts]; ++j)
              f[ts][j] = max(f[ts][j], G[ts][ty][j]);
          }
          if (Dis[x][y] <= Lim) {
            if (!col[x])
              for (int j = 0; j <= sz[s]; ++j) F[x][y][j] = F[s][y][j];
            else
              for (int j = 0; j <= sz[s]; ++j) F[x][y][j] = F[s][y][j] + V2;
            for (int i = 1, sum = sz[s]; i <= N; ++i)
              if (S[i] != s) {
                int s = S[i];
                sum += sz[s];
                for (int is = sum; is >= 0; --is)
                  for (int i1 = 0; i1 <= sz[s] && i1 <= is; ++i1) {
                    if (!i1)
                      F[x][y][is] = F[x][y][is - i1] + f[s][i1];
                    else
                      F[x][y][is] =
                          max(F[x][y][is], F[x][y][is - i1] + f[s][i1]);
                  }
              }
          }
          for (int j = 0; j <= sz[s]; ++j) f[s][j] = max(f[s][j], F[s][y][j]);
        }
    }
  }
}
int main() {
  scanf("%d%d", &n, &Lim);
  for (int i = 1; i <= n; ++i) scanf("%d", col + i);
  tot = 1;
  for (int i = 1, a, b, c; i < n; ++i) scanf("%d%d%d", &a, &b, &c), cc(a, b, c);
  for (int i = 1; i <= n; ++i) {
    Dis[i][i] = 0;
    GetDis(i, i, 0);
  }
  Dep[1] = 1;
  GetOrd(1, 0);
  memset(F, 0, sizeof(F));
  memset(G, 0, sizeof(G));
  Dp(1, 0);
  for (int L = 0; L <= sz[1]; ++L)
    for (int x = 1; x <= n; ++x)
      if (F[1][x][L].x >= L + 1) {
        printf("%d\n", L);
        exit(0);
      }
  puts("-1");
}
