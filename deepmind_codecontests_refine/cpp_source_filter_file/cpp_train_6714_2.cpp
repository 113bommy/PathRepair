#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
const int N = 800010;
int c[N][26], pre[N], q[N], X[N], Y[N], fa[N], n, cnt, gg, use[N];
long long ans;
char s[N];
vector<int> tr[N], del[N];
void insert(int id) {
  int n = strlen(s + 1), now = 0;
  tr[0].push_back(id);
  for (int i = 1; i <= n; ++i) {
    if (!c[now][s[i] - 'a']) c[now][s[i] - 'a'] = ++cnt, pre[cnt] = now;
    now = c[now][s[i] - 'a'];
    tr[now].push_back(id);
  }
}
void dfs(int x, int dep) {
  int son = 0;
  for (int i = 0; i <= 25; ++i)
    if (c[x][i]) dfs(c[x][i], dep + 1);
  int tot = 0;
  for (int i = 0; i < tr[x].size(); i++)
    if (!use[tr[x][i]]) q[++tot] = tr[x][i];
  int l = 1, r = tot;
  while (l < r && (q[l] <= n) && (q[r] > n))
    use[q[l]] = 1, use[q[r]] = 1, X[++gg] = q[l++], Y[gg] = q[r--], ans += dep;
}
int main() {
  n = read();
  for (int i = 1; i <= n * 2; ++i) {
    scanf("%s", s + 1);
    insert(i);
  }
  dfs(0, 0);
  printf("I64d\n", ans);
  for (int i = 1; i <= n; ++i) printf("%dd %d\n", X[i], Y[i] - n);
}
