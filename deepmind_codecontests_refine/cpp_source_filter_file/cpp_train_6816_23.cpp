#include <bits/stdc++.h>
using namespace std;
struct TrieNode {
  int child[5];
  void config(int x) { memset(child, -1, sizeof(child)); }
};
TrieNode nodePool[2000000];
class Trie {
  int cnt;
  TrieNode *ptr;

 public:
  Trie() {
    nodePool[0].config(0);
    ptr = nodePool;
    cnt = 1;
  }
  void addWord(const char *key) {
    int len = strlen(key);
    int i;
    int indx = 0;
    for (i = 0; i < len; i++) {
      if (ptr[indx].child[key[i] - 'a'] == -1) {
        nodePool[cnt].config(0);
        ptr[indx].child[key[i] - 'a'] = cnt;
        indx = cnt;
        cnt++;
      } else {
        indx = ptr[indx].child[key[i] - 'a'];
      }
    }
  }
  bool check(char *w, int indx, bool had) {
    if (*w == 'd') {
      if (ptr[indx].child['d' - 1] != -1 && had) {
        return true;
      } else {
        return false;
      }
    } else {
      bool f = false;
      int i;
      for (i = 0; i < 3 && !f; i++) {
        if (ptr[indx].child[i] == -1) continue;
        if (i == (*w - 'a')) {
          f |= check(w + 1, ptr[indx].child[i], had);
        } else if (!had) {
          f |= check(w + 1, ptr[indx].child[i], true);
        }
      }
      return f;
    }
  }
};
char ln[1000000];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Trie x;
  int i, j;
  for (i = 0; i < n; i++) {
    scanf("%s", ln);
    int len = strlen(ln);
    ln[len] = 'd';
    ln[len + 1] = '\0';
    x.addWord(ln);
  }
  for (i = 0; i < m; i++) {
    scanf("%s", ln);
    int len = strlen(ln);
    ln[len] = 'd';
    ln[len + 1] = '\0';
    bool f = x.check(ln, 0, 0);
    if (f) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
