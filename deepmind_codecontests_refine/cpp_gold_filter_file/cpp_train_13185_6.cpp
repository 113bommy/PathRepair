#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, maxnode = 1e5 + 10, z = 26, inf = 1e9 + 10;
vector<int> ocr[maxn];
char s[maxn], t[maxn];
int n, m, ted[maxn], sz[maxn], ans[maxn];
struct Trie {
  int to[maxnode][z], last = 1, val[maxnode], f[maxnode], Q[maxnode],
                      par[maxnode];
  void add(int ii, char s[maxn], int size) {
    int id = 0;
    for (int i = 0; i < size; i++) {
      if (to[id][s[i] - 'a'] == 0) {
        to[id][s[i] - 'a'] = last++;
      }
      id = to[id][s[i] - 'a'];
    }
    val[id] = ii + 1;
  }
  void bfs() {
    int l = 0, r = 0;
    Q[r++] = 0;
    while (l < r) {
      int a = Q[l++];
      if (val[a] > 0) {
        if (val[f[a]] == 0) {
          par[a] = 0;
        } else {
          par[a] = f[a];
        }
      } else {
        val[a] = val[f[a]];
        par[a] = par[f[a]];
      }
      for (int i = 0; i < z; i++) {
        if (to[a][i] == 0) {
          to[a][i] = to[f[a]][i];
        } else {
          f[to[a][i]] = (a > 0) ? to[f[a]][i] : 0;
          Q[r++] = to[a][i];
        }
      }
    }
  }
  void solve() {
    int id = 0;
    for (int i = 0; i < m; i++) {
      id = to[id][s[i] - 'a'];
      int ii = id;
      while (val[ii] > 0) {
        ocr[val[ii] - 1].push_back(i);
        ii = par[ii];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = ted[i] - 1; j < int(ocr[i].size()); j++) {
        if (ans[i] == -1 ||
            ans[i] > ocr[i][j] - ocr[i][j - ted[i] + 1] + sz[i]) {
          ans[i] = ocr[i][j] - ocr[i][j - ted[i] + 1] + sz[i];
        }
      }
    }
  }
} trie;
int32_t main() {
  memset(ans, -1, sizeof ans);
  scanf("%s%d", s, &n);
  m = strlen(s);
  for (int i = 0; i < n; i++) {
    scanf("%d%s", ted + i, t);
    sz[i] = strlen(t);
    trie.add(i, t, sz[i]);
  }
  trie.bfs();
  trie.solve();
  for (int i = 0; i < n; i++) {
    printf("%d\n", ans[i]);
  }
}
