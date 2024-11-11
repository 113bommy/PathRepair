#include <bits/stdc++.h>
using namespace std;
int n, m, hd, el;
char s[1000];
struct E {
  char tag;
  int p[26];
} e[1000000];
void ins() {
  int i, j, k, l;
  for (i = 0, l = hd; s[i]; i++) {
    if (!e[l].p[s[i] - 'a']) e[l].p[s[i] - 'a'] = el++;
    l = e[l].p[s[i] - 'a'];
  }
}
void dfs(int ei) {
  int i, j, c[5] = {0, 0, 0, 0, 0};
  for (i = j = 0; i < 26; i++) {
    if (e[ei].p[i]) {
      j = 1;
      dfs(e[ei].p[i]);
      c[e[e[ei].p[i]].tag]++;
    }
  }
  if (!j)
    e[ei].tag = 1;
  else if (c[4] || (c[1] && c[2]))
    e[ei].tag = 3;
  else if (c[1])
    e[ei].tag = 2;
  else if (c[2])
    e[ei].tag = 1;
  else
    e[ei].tag = 4;
}
void init() {
  int i, j, k, l;
  hd = el = 0;
  el++;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%s", s);
    ins();
  }
  dfs(hd);
}
void solve() {
  if (e[hd].tag == 1 || e[hd].tag == 3)
    puts("Second");
  else if (e[hd].tag == 4)
    puts("First");
  else if (m & 1)
    puts("First");
  else
    puts("Second");
}
int main() {
  init();
  solve();
  return 0;
}
