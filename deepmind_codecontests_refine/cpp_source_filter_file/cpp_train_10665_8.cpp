#include <bits/stdc++.h>
using namespace std;
const int maxnode = 100000 + 10;
const int maxm = 1000;
const int sigma_size = 26;
char a[maxm];
struct Trie {
  int ch[maxnode][sigma_size];
  int sz;
  void clear() {
    memset(ch[0], 0, sizeof(ch[0]));
    sz = 1;
  }
  int idx(char c) { return c - 'a'; }
  void insert(const char *s) {
    int n = strlen(s), u = 0;
    for (int i = 0; i < n; i++) {
      int c = idx(s[i]);
      if (!ch[u][c]) {
        memset(ch[sz], 0, sizeof(ch[sz]));
        ch[u][c] = sz++;
      }
      u = ch[u][c];
    }
  }
  int dfs(int u) {
    bool flag = true;
    int ans = 0;
    for (int i = 0; i < sigma_size; i++) {
      if (ch[u][i]) {
        flag = false;
        ans |= dfs(ch[u][i]);
      }
    }
    if (flag) ans = 1;
    return 3 - ans;
  }
} trie;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  trie.clear();
  for (int i = 0; i < n; i++) {
    scanf("%s", a);
    trie.insert(a);
  }
  int ans = trie.dfs(0);
  if (ans < 2)
    printf("Second\n");
  else if (ans == 2)
    printf("%s\n", k & 1 ? "First" : "Second");
  else
    printf("First\n");
  return 0;
}
