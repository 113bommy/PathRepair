#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[2000][501];
struct Trie {
  struct Node {
    int c, depth;
    int next[26];
    Node() : c(0), depth(0) { memset(next, -1, sizeof(next)); }
  } P[1000000];
  int sz;
  vector<int> dp[1000000];
  void init() {
    sz = 0;
    P[sz++] = Node();
  }
  void insert(char* s) {
    int p = 0;
    for (char* i = s; *i != '\0'; ++i) {
      int c = *i - 'a';
      if (P[p].next[c] == -1) {
        P[p].next[c] = sz;
        P[sz] = Node();
        P[sz++].depth = P[p].depth + 1;
      }
      p = P[p].next[c];
    }
    ++P[p].c;
  }
  void dfs(int u) {
    int& total = P[u].c;
    for (int i = 0; i < 26; ++i) {
      if (P[u].next[i] != -1) {
        dfs(P[u].next[i]);
        total += P[P[u].next[i]].c;
      }
    }
    total = min(total, m);
    dp[u] = vector<int>(total + 1, 0);
    for (int i = 0; i < 26; ++i) {
      if (P[u].next[i] != -1) {
        int t = P[u].next[i], s = (int)dp[t].size();
        for (int j = total; j >= 0; --j) {
          for (int k = min(total - j, s); k >= 0; --k) {
            dp[u][j + k] = max(dp[u][j + k], dp[u][j] + dp[t][k]);
          }
        }
      }
    }
    if (u != 0) {
      for (int i = 0; i <= total; ++i) {
        dp[u][i] += i * (i - 1) / 2;
      }
    }
  }
  void travel(int u) {
    printf("u = %d\n", u);
    for (int i = 0; i < 26; ++i) {
      if (P[u].next[i] != -1) {
        printf(" %c -> %d\n", i + 'a', P[u].next[i]);
      }
    }
    for (int i = 0; i < 26; ++i) {
      if (P[u].next[i] != -1) {
        travel(P[u].next[i]);
      }
    }
  }
  void gao() {
    dfs(0);
    printf("%d\n", dp[0][m]);
  }
} trie;
int main() {
  trie.init();
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    trie.insert(s[i]);
  }
  trie.gao();
  return 0;
}
