#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, C = 26;
int id;
struct Node {
  int link[C];
  int dp;
  void clear() { memset(link, -1, sizeof(link)); }
} u[N];
void insert(char *s) {
  int top = 0;
  for (int i = 0; s[i]; ++i) {
    int c = s[i] - 'a';
    if (u[top].link[c] == -1) {
      u[id].clear();
      u[top].link[c] = id++;
    }
    top = u[top].link[c];
  }
}
void dfs(int x) {
  bool leaf = 1;
  int dp = 1;
  for (int i = 0; i < C; ++i) {
    int to = u[x].link[i];
    if (to == -1) continue;
    dfs(to);
    leaf = 0;
    dp &= u[to].dp;
  }
  if (leaf) {
    u[x].dp = 0;
  } else {
    if (dp == 0)
      u[x].dp = 1;
    else
      u[x].dp = 0;
  }
}
void dfs2(int x) {
  bool leaf = 1;
  int dp = 1;
  for (int i = 0; i < C; ++i) {
    int to = u[x].link[i];
    if (to == -1) continue;
    dfs2(to);
    leaf = 0;
    dp &= u[to].dp;
  }
  if (leaf) {
    u[x].dp = 1;
  } else {
    if (dp == 0)
      u[x].dp = 1;
    else
      u[x].dp = 0;
  }
}
char s[N];
int main() {
  u[(id = 0)++].clear();
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    insert(s);
  }
  dfs(0);
  if (!u[0].dp) {
    puts("Second");
  } else {
    dfs2(0);
    if (u[0].dp)
      puts("First");
    else {
      if (k & 1)
        puts("First");
      else
        puts("Second");
    }
  }
  return 0;
}
