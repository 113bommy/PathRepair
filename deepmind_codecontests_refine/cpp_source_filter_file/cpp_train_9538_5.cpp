#include <bits/stdc++.h>
using namespace std;
namespace SHENZHEBEI {
const int L = 2333333;
char SZB[L], *S = SZB, *T = SZB;
inline char gc() {
  if (S == T) {
    T = (S = SZB) + fread(SZB, 1, L, stdin);
    if (S == T) return '\n';
  }
  return *S++;
}
inline long long read() {
  long long x = 0, f = 1;
  char ch = gc();
  for (; !isdigit(ch); ch = gc())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = gc()) x = x * 10 - 48 + ch;
  return x * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline char readchar() {
  char ch = gc();
  for (; isspace(ch); ch = gc())
    ;
  return ch;
}
inline long long readstr(char *s) {
  char ch = gc();
  int cur = 0;
  for (; isspace(ch); ch = gc())
    ;
  for (; !isspace(ch); ch = gc()) s[cur++] = ch;
  s[cur] = '\0';
  return cur;
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
}  // namespace SHENZHEBEI
using namespace SHENZHEBEI;
const long long N = 1000010;
struct data {
  long long nxt, w;
} a[N];
long long f[N], dep[N], head[N], nxt[N], vet[N], n, tot, rt, cnt;
vector<long long> g[N];
void insert(long long x, long long y) {
  nxt[++tot] = head[x];
  head[x] = tot;
  vet[tot] = y;
}
void get_dep(long long x) {
  for (long long i = head[x]; i; i = nxt[i])
    dep[vet[i]] = dep[x] + 1, get_dep(vet[i]);
}
void dfs(long long x) {
  for (long long i = head[x]; i; i = nxt[i]) {
    long long y = vet[i];
    dfs(y);
    if (!a[x].nxt) {
      a[x].nxt = y;
      continue;
    }
    long long z = a[x].nxt;
    for (; y; y = a[y].nxt, z = a[z].nxt) {
      g[cnt].push_back(a[y].w);
      g[cnt].push_back(a[z].w);
      f[cnt] = f[a[y].w] + f[a[z].w];
      dep[cnt] = dep[x];
      a[z].w = cnt++;
      if (!a[z].nxt) {
        a[z].nxt = a[y].nxt;
        break;
      }
    }
  }
}
void DFS(long long x) {
  for (long long i = 0; i < g[x].size(); ++i)
    f[g[x][i]] = f[x] + (dep[g[x][i]] - dep[x]) * f[g[x][i]], DFS(g[x][i]);
}
void Dfs(long long x) {
  for (long long i = head[x]; i; i = nxt[i]) f[vet[i]] += f[x], Dfs(vet[i]);
}
int main() {
  n = read();
  cnt = n + 1;
  for (long long i = 1; i <= n; ++i) {
    long long fa = read();
    if (fa)
      insert(fa, i);
    else
      rt = i;
  }
  dep[rt] = 1;
  get_dep(rt);
  for (long long i = 1; i <= n; ++i) a[i].w = i, f[i] = 1;
  dfs(rt);
  for (long long i = rt; i; i = a[i].nxt) {
    long long x = a[i].w;
    f[x] = dep[x] * f[x];
    DFS(x);
  }
  Dfs(rt);
  for (long long i = 1; i <= n; ++i) printf("%d ", f[i] - dep[i]);
  puts("");
}
