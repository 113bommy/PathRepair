#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int k = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  return k * f;
}
void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
const int N = 5e5 + 10;
char ch[N];
int n, nedge = 0, p[2 * N], nex[2 * N], head[2 * N], a[N];
int fa[N], deep[N], s[N], sx[N], cnt = 0;
int Cnt[N], m, maxdep;
vector<int> e[N], f[N];
inline void addedge(int a, int b) {
  p[++nedge] = b;
  nex[nedge] = head[a];
  head[a] = nedge;
}
inline void dfs(int x, int Fa, int dep) {
  fa[x] = Fa;
  deep[x] = dep;
  s[x] = 1;
  sx[x] = ++cnt;
  maxdep = max(maxdep, dep);
  Cnt[dep]++;
  if (Cnt[dep] == 1) {
    e[dep].push_back(0);
    f[dep].push_back(0);
  }
  int la = f[dep][Cnt[dep] - 1];
  e[dep].push_back(cnt);
  f[dep].push_back((1 << a[x]) ^ la);
  for (int k = head[x]; k; k = nex[k]) {
    dfs(p[k], x, dep + 1);
    s[x] += s[p[k]];
  }
}
int main() {
  n = read();
  m = read();
  for (int i = 2; i <= n; i++) {
    int x = read();
    addedge(x, i);
  }
  scanf("%s", ch + 1);
  for (int i = 1; i <= n; i++) a[i] = ch[i] - 'a';
  dfs(1, 0, 1);
  for (int i = 1; i <= maxdep; i++) e[i].push_back(n + 1);
  for (int i = 1; i <= m; i++) {
    int x = read(), dep = read();
    if (dep > maxdep) {
      puts("No");
      continue;
    }
    int l =
        lower_bound(e[dep].begin(), e[dep].end(), sx[x]) - e[dep].begin() - 1;
    int r = lower_bound(e[dep].begin(), e[dep].end(), sx[x] + s[x]) -
            e[dep].begin() - 1;
    int p = f[dep][r] ^ f[dep][l];
    bool flag = (p == 0);
    if (!flag) {
      for (int i = 0; i < 26; i++)
        if (p == (1 << i)) flag = 1;
    }
    if (flag)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
