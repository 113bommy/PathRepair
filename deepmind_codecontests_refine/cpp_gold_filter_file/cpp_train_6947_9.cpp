#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(int a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(int a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  write(a);
  puts("");
}
inline int rnd(int x) { return rand() % x; }
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 200005;
int n, m, sss, sum[N], x[N], y[N], s[N], vis[N], b[N], c[N];
map<int, int> M[N];
vector<int> v[N], e[N];
void ins(int a, int b) {
  int t = min(s[a], -s[b]);
  sum[a] += t;
  sum[b] -= t;
  s[a] -= t;
  s[b] += t;
}
void dfs(int p) {
  vis[p] = 1;
  for (unsigned i = 0; i < v[p].size(); i++) {
    if (!vis[v[p][i]]) {
      e[p].push_back(v[p][i]);
      dfs(v[p][i]);
    }
  }
}
void ddd(int p) {
  for (unsigned i = 0; i < e[p].size(); i++) {
    ddd(e[p][i]);
    M[e[p][i]][p] = sum[e[p][i]];
    sum[p] += sum[e[p][i]];
  }
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    s[i] = read();
  }
  m = read();
  for (int i = 1; i <= m; i++) {
    x[i] = read();
    y[i] = read();
    v[x[i]].push_back(y[i]);
    v[y[i]].push_back(x[i]);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    if (s[i] > 0)
      b[++b[0]] = i;
    else
      c[++c[0]] = i;
    sss += s[i];
  }
  if (sss) {
    puts("Impossible");
    return 0;
  }
  puts("Possible");
  for (int i = 1; i <= b[0]; i++) {
    while (s[c[c[0]]] && s[b[i]]) {
      ins(b[i], c[c[0]]);
      while (s[c[c[0]]] == 0 && c[0]) c[0]--;
    }
  }
  ddd(1);
  for (int i = 1; i <= m; i++) writeln(-(M[x[i]][y[i]] - M[y[i]][x[i]]));
}
