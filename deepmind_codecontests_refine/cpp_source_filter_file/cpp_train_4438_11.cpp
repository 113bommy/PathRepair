#include <bits/stdc++.h>
const int MAXL = 2000000;
const int AUX_SIZE = 10;
struct Trie {
  int cover[MAXL], ch[MAXL][AUX_SIZE];
  int cnt;
  inline int idx(const char c) { return c - '0'; }
  inline void insert(const char* s) {
    int cur = 0;
    for (int i = 0; s[i]; i++) {
      int t = idx(s[i]);
      if (ch[cur][t]) {
        cur = ch[cur][t];
        cover[cur]++;
      } else {
        assert(cnt < MAXL);
        ch[cur][t] = ++cnt;
        cur = ch[cur][t];
        cover[cur] = 1;
      }
    }
  }
  inline void del(const char* s) {
    int cur = 0;
    for (int i = 0; s[i]; i++) {
      int t = idx(s[i]);
      cur = ch[cur][t];
      if (cur) cover[cur]--;
    }
  }
  inline bool query(const char* s) {
    int cur = 0;
    for (int i = 0; s[i]; i++) {
      int t = idx(s[i]), o = ch[cur][t];
      if (!o || !cover[o])
        return 0;
      else
        cur = o;
    }
    return 1;
  }
} T;
const int MAXSIZE = 13;
const int MAXN = 7000 + 5;
char s[MAXN][MAXSIZE], tmp[MAXSIZE];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; s[i][j]; j++) {
      T.insert(s[i] + j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; s[i][j]; j++) {
      T.del(s[i] + j);
    }
    int lx = strlen(s[i]);
    for (int len = 1; len <= lx; len++) {
      bool ok = 0;
      for (int start = 0; start + len - 1 < lx; start++) {
        for (int x = start; x <= start + len - 1; x++) {
          tmp[x - start] = s[i][x];
        }
        tmp[len] = '\0';
        if (!T.query(tmp)) {
          printf("%s\n", tmp);
          ok = 1;
          break;
        }
      }
      if (ok) break;
    }
    for (int j = 0; s[i][j]; j++) {
      T.insert(s[i] + j);
    }
  }
}
