#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct bor {
  int nx[30];
  bool win;
  bool loose;
} t[250005];
int sz = 1;
int n, len, k;
char s[N];
void add() {
  int v = 1;
  for (int it = 0; it < len; ++it) {
    int to = s[it] - 'a';
    if (!t[v].nx[to]) t[v].nx[to] = ++sz;
    v = t[v].nx[to];
  }
}
void dfs(int v) {
  t[v].win = 0;
  for (int it = 0; it <= 26; ++it) {
    int to = t[v].nx[it];
    if (to) {
      dfs(to);
      if (!t[to].win) t[v].win = 1;
    }
  }
}
void dfs2(int v) {
  t[v].loose = 0;
  bool in = false;
  for (int it = 0; it <= 26; ++it) {
    int to = t[v].nx[it];
    if (to) {
      in = true;
      dfs2(to);
      if (!t[to].loose) t[v].loose = 1;
    }
  }
  if (!in) t[v].loose = 1;
}
bool loose;
int main() {
  scanf("%d%d\n", &n, &k);
  for (int i = 1; i <= n; ++i) {
    gets(s);
    len = strlen(s);
    add();
    scanf("\n");
  }
  dfs(1);
  if (!t[1].win) {
    puts("Second");
    return 0;
  }
  dfs2(1);
  if (t[1].loose) {
    puts("First");
    return 0;
  }
  if (k & 1)
    puts("First");
  else
    puts("Second");
  return 0;
}
