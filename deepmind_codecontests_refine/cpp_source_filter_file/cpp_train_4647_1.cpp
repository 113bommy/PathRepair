#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 44;
const int N = 27;
struct Node {
  char s[N];
  int len;
} g[M];
struct Chr {
  int id, val, vis;
} chr[27];
char str[M];
int n, lstr, plc[N];
int fa[N], val[N], vis[N];
bool cmp(Chr a, Chr b) { return a.id < b.id; }
int findd(int x) {
  if (fa[x] == -1) return x;
  int tmp = findd(fa[x]);
  val[x] += val[fa[x]];
  return fa[x] = tmp;
}
bool solve() {
  int i, j, k, pa, pb, a, b, c, pi;
  memset(val, 0, sizeof(val));
  memset(vis, 0, sizeof(vis));
  for (i = 0; i < 26; i++) fa[i] = -1;
  for (i = 1; i <= n; i++) {
    for (j = 0; j < g[i].len; j++) {
      vis[g[i].s[j] - 'a'] = 1;
      for (k = j + 1; k < g[i].len; k++) {
        a = g[i].s[j] - 'a';
        b = g[i].s[k] - 'a';
        c = k - j;
        pa = findd(a);
        pb = findd(b);
        if (pa != pb) {
          fa[pb] = pa;
          val[pb] = val[a] - val[b] + c;
        } else {
          if (val[b] - val[a] != c) return false;
        }
      }
    }
  }
  for (i = 0; i < 26; i++)
    for (j = 0; j < 26; j++)
      if (findd(i) == findd(j) && val[i] == val[j]) return false;
  for (i = 0; i < 26; i++) {
    pi = findd(i);
    chr[i].id = val[i] + pi * 30;
    chr[i].val = i;
    chr[i].vis = vis[i];
  }
  sort(chr, chr + 26, cmp);
  for (i = 0; i < 26; i++)
    if (chr[i].vis) printf("%c", chr[i].val + 'a');
  printf("\n");
  return true;
}
int main() {
  bool flag = true;
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%s", str);
    lstr = strlen(str);
    if (lstr > 26) {
      flag = false;
      continue;
    }
    for (j = 0; j < lstr; j++) g[i].s[j] = str[j];
    g[i].len = lstr;
    for (j = 0; j < 26; j++) plc[j] = -1;
    for (j = 0; j < lstr; j++) {
      if (plc[g[i].s[j] - 'a'] == -1)
        plc[g[i].s[j] - 'a'] = j;
      else
        flag = false;
    }
  }
  if (flag == false) {
    puts("NO");
    return 0;
  }
  if (solve() == 0) puts("NO");
  return 0;
}
