#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001100, MAXS = 10;
struct Trie {
  int ch[MAXN][MAXS], sz, val[MAXN * 10];
  int id(char c) { return c - '0'; }
  void init() { sz = 0, newnode(); }
  int newnode() {
    memset(ch[sz], 0, sizeof(ch[sz])), val[sz] = 0;
    return sz++;
  }
  void insert(char *s) {
    int u = 0;
    for (int i = 0; s[i]; ++i) {
      int c = id(s[i]);
      if (!ch[u][c]) ch[u][c] = newnode();
      u = ch[u][c];
      val[u]++;
    }
  }
  void Delete(char *s) {
    int u = 0;
    for (int i = 0; s[i]; ++i) {
      int c = id(s[i]);
      u = ch[u][c];
      val[u]--;
    }
  }
  int query(char *s) {
    int len = 0, u = 0;
    for (int i = 0; s[i]; ++i) {
      int c = id(s[i]);
      u = ch[u][c];
      if (val[u] == 0) return i + 1;
    }
    return -1;
  }
} trie;
char s[70055][MAXS + 2];
int N;
int main() {
  scanf("%d", &N);
  trie.init();
  for (int i = 0; i < (N); ++i) {
    scanf("%s", s[i]);
    for (int ii = 0; ii < (9); ++ii) trie.insert(s[i] + ii);
  }
  for (int i = 0; i < (N); ++i) {
    int best = 9, best_pos = 0;
    for (int ii = 0; ii < (9); ++ii) trie.Delete(s[i] + ii);
    for (int st = 0; st < (9); ++st) {
      int len = trie.query(s[i] + st);
      if (len != -1 && len < best) {
        best = len, best_pos = st;
      }
    }
    for (int ii = 0; ii < (9); ++ii) trie.insert(s[i] + ii);
    s[i][best_pos + best] = 0;
    printf("%s\n", s[i] + best_pos);
  }
}
