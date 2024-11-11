#include <bits/stdc++.h>
using namespace std;
struct trie {
  int ch[100020][26], p[100020];
  bool is[100020], ok[100020];
  int sz;
  int creat() {
    memset(ch[sz], -1, sizeof(ch[sz]));
    is[sz] = 1;
    return sz++;
  }
  void init() {
    memset(ch[0], -1, sizeof(ch[0]));
    is[0] = 1;
    sz = 1;
  }
  void insert(char *s) {
    int t = 0;
    for (int i = 0; s[i]; ++i) {
      int c = s[i] - 'a';
      if (ch[t][c] == -1) {
        ch[t][c] = creat();
        p[sz - 1] = t;
      }
      is[t] = 0;
      t = ch[t][c];
    }
  }
  bool wd(int t) {
    if (is[t]) return 0;
    for (int i = 0; i < 26; ++i) {
      if (ch[t][i] == -1) continue;
      if (!wd(ch[t][i])) return 1;
    }
    return 0;
  }
  bool want_win() {
    if (wd(0)) return 1;
    return 0;
  }
  bool ld(int t) {
    if (is[t]) return 0;
    for (int i = 0; i < 26; ++i) {
      if (ch[t][i] == -1) continue;
      if (ld(ch[t][i])) return 0;
    }
    return 1;
  }
  bool want_lost() {
    if (!ld(0)) return 1;
    return 0;
  }
  int dfs(int t) {
    if (is[t]) return -1;
    int now = 0;
    for (int i = 0; i < 26; ++i) {
      if (ch[t][i] == -1) continue;
      int u = dfs(ch[t][i]);
      if (u == 0) return 0;
      if (now == 0) {
        now = u;
        continue;
      }
      if (now + u == 0) return 0;
    }
    return -now;
  }
  int check() { return dfs(0); }
} ac;
int n, k;
char s[100020];
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    ac.init();
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s);
      ac.insert(s);
    }
    bool f1 = ac.want_win();
    bool f2 = ac.want_lost();
    int f3 = ac.check();
    if (f3) {
      if (f3 == 1) {
        if (k & 1)
          puts("First");
        else
          puts("Second");
      } else
        puts("Second");
      continue;
    }
    if (!f1 && !f2) {
      puts("Second");
      continue;
    }
    if (!f1 && f2) {
      puts("Second");
      continue;
    }
    if (f1 && !f2) {
      if (k & 1)
        puts("First");
      else
        puts("Second");
      continue;
    }
    puts("First");
  }
  return 0;
}
