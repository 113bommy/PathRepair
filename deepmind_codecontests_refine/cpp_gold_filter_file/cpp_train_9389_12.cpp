#include <bits/stdc++.h>
struct node {
  int len, link, s;
  std::map<char, int> urm;
} sa[2 * 100000 + 1];
int last, sz;
long long ans;
std::vector<int> g[2 * 100000 + 1];
inline void init() {
  last = 0;
  sa[0].len = 0;
  sa[0].link = -1;
  sz = 1;
}
inline void baga(char x) {
  int cur = sz++;
  sa[cur].len = sa[last].len + 1;
  int p = last;
  while (p != -1 && sa[p].urm[x] == 0) {
    sa[p].urm[x] = cur;
    p = sa[p].link;
  }
  if (p == -1)
    sa[cur].link = 0;
  else {
    int q = sa[p].urm[x];
    if (sa[q].len == sa[p].len + 1)
      sa[cur].link = q;
    else {
      int clone = sz++;
      sa[clone].len = sa[p].len + 1;
      sa[clone].link = sa[q].link;
      sa[clone].urm = sa[q].urm;
      while (p != -1 && sa[p].urm[x] == q) {
        sa[p].urm[x] = clone;
        p = sa[p].link;
      }
      sa[q].link = sa[cur].link = clone;
    }
  }
  last = cur;
  sa[cur].s = 1;
}
void dfs(int x) {
  for (auto &y : g[x]) {
    dfs(y);
    sa[x].s += sa[y].s;
  }
}
int main() {
  init();
  char ch = fgetc(stdin);
  while (ch != '\n') {
    baga(ch);
    ch = fgetc(stdin);
  }
  for (int i = 1; i < sz; i++) g[sa[i].link].push_back(i);
  dfs(0);
  long long ans = 0;
  for (int i = 1; i < sz; i++)
    ans += 1LL * (sa[i].len - sa[sa[i].link].len) *
           (1LL * sa[i].s * (sa[i].s + 1) / 2);
  fprintf(stdout, "%I64d\n", ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
