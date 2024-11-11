#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 1, maxc = 26, mod = (int)1e9 + 7;
int len[maxn], link[maxn], to[maxn][maxc + 1];
int slink[maxn], diff[maxn], f[maxn], g[maxn];
int sz, last, n;
char buf[maxn], s[maxn];
inline int get_link(int v) {
  for (; s[n - len[v] - 2] != s[n - 1]; v = link[v])
    ;
  return v;
}
void add_letter(char c) {
  s[n++] = c -= 'a';
  last = get_link(last);
  if (!to[last][(int)c]) {
    len[sz] = len[last] + 2;
    link[sz] = to[get_link(link[last])][c];
    diff[sz] = len[sz] - len[link[sz]];
    if (diff[sz] == diff[link[sz]])
      slink[sz] = slink[link[sz]];
    else
      slink[sz] = link[sz];
    to[last][c] = sz++;
  }
  last = to[last][c];
}
inline void mod_inc(int &x, int y) { (x += y) >= mod && (x -= mod); }
int main() {
  scanf("%s", s);
  int n = strlen(s);
  if (n & 1) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < n >> 1; ++i) buf[i << 1] = s[i];
  for (int i = 0; i < n >> 1; ++i) buf[i << 1 | 1] = s[n - 1 - i];
  s[::n++] = -1;
  link[0] = 1;
  len[1] = -1;
  sz = 2;
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    add_letter(buf[i - 1]);
    for (int v = last; len[v] > 0; v = slink[v]) {
      g[v] = f[i - (len[slink[v]] + diff[v])];
      if (diff[v] == diff[link[v]]) mod_inc(g[v], g[link[v]]);
      if (!(i & 1)) mod_inc(f[i], g[v]);
    }
  }
  printf("%d\n", f[n]);
  return 0;
}
