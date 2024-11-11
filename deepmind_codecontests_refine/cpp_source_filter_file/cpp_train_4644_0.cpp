#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
struct trie {
  int s, ch[2];
} t[3000005];
int cnt = 1, rt = 1;
inline void add(int x) {
  int pos = 1, i, tg;
  t[pos].s++;
  for (i = 26; i >= 0; i--) {
    if (x & (1 << i)) {
      tg = 1;
    } else {
      tg = 0;
    }
    if (!t[pos].ch[tg]) {
      t[pos].ch[tg] = ++cnt;
    }
    pos = t[pos].ch[tg];
    t[pos].s++;
  }
  return;
}
inline void del(int x) {
  int pos = 1, i, tg;
  t[pos].s--;
  for (i = 26; i >= 0; i--) {
    if (x & (1 << i)) {
      tg = 1;
    } else {
      tg = 0;
    }
    pos = t[pos].ch[tg];
    t[pos].s--;
  }
  return;
}
inline void ask(int x, int tar) {
  int ans = 0, pos = 1, i, nt = 0, ok;
  for (i = 26; i >= 0; i--) {
    if (nt + (1 << i) - 1 < tar) {
      ok = 1;
      nt = (nt + (1 << i)) - 1;
    } else {
      ok = 0;
    }
    int p = x & (1 << i), tag;
    if (p > 0) {
      tag = 0;
    } else {
      tag = 1;
    }
    if (!ok) {
      tag ^= 1;
    } else {
      ans += t[t[pos].ch[tag ^ 1]].s;
    }
    pos = t[pos].ch[tag];
  }
  printf("%d\n", ans);
  return;
}
int main() {
  int p, q, l, opt;
  q = read();
  while (q--) {
    opt = read();
    if (opt == 1) {
      p = read();
      add(p);
    }
    if (opt == 2) {
      p = read();
      del(p);
    }
    if (opt == 3) {
      p = read();
      l = read();
      ask(p, l);
    }
  }
  return 0;
}
