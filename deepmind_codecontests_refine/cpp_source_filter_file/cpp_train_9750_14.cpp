#include <bits/stdc++.h>
char s[125001], t[125001];
int n, m;
int bl[6], ans[125001], nt[125001];
void work(int lv) {
  nt[0] = nt[1] = 0;
  int k = 0;
  for (int i = 1; i < m; i++) {
    while (k && bl[(t[i]) - 'a'] != bl[(t[k]) - 'a']) k = nt[k];
    nt[i + 1] = (bl[(t[i]) - 'a'] == bl[(t[k]) - 'a'] ? ++k : 0);
  }
  k = 0;
  for (int i = 0; i < n; i++) {
    while (k && k != m && bl[(s[i]) - 'a'] != bl[(t[k]) - 'a']) k = nt[k];
    if (bl[(s[i]) - 'a'] == bl[(t[k]) - 'a']) k++;
    if (k == m && lv < ans[i - m + 1]) ans[i - m + 1] = lv;
  }
}
void dfs(int d, int c) {
  if (d == 6) {
    work(6 - c);
    return;
  }
  for (int i = 0; i < c; i++) {
    bl[d] = i;
    dfs(d + 1, c);
  }
  bl[d] = c;
  dfs(d + 1, c + 1);
}
int main() {
  memset(ans, 8, sizeof(ans));
  scanf("%s%s", s, t);
  n = strlen(s);
  m = strlen(t);
  dfs(0, 0);
  for (int i = 0; i < n - m + 1; i++) printf("%d ", ans[i]);
  puts("");
}
