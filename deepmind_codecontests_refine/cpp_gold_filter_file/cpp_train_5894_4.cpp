#include <bits/stdc++.h>
using namespace std;
int const N = 5e5;
int n, m, aa[N];
struct node {
  int nxt[2];
  int prf;
  node() {
    nxt[0] = nxt[1] = -1;
    prf = 0;
  }
};
vector<node> trie;
void insert(int a) {
  int cur = 0;
  for (int i = 19; i > -1; i--) {
    int b = (a >> i) & 1;
    if (trie[cur].nxt[b] == -1) {
      trie[cur].nxt[b] = trie.size();
      trie.push_back(node());
    }
    cur = trie[cur].nxt[b];
    trie[cur].prf++;
  }
}
int query(int a) {
  int cur = 0;
  int res = 0;
  for (int i = 19; i > -1; i--) {
    int b = (a >> i) & 1;
    if (trie[cur].nxt[b] == -1) return res;
    if (trie[trie[cur].nxt[b]].prf == (1 << i)) {
      res += 1 << i;
      if (trie[cur].nxt[!b] == -1) return res;
      cur = trie[cur].nxt[!b];
    } else
      cur = trie[cur].nxt[b];
  }
  return res;
}
int main() {
  trie.push_back(node());
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &aa[i]);
  sort(aa, aa + n);
  n = unique(aa, aa + n) - aa;
  for (int i = 0; i < n; i++) insert(aa[i]);
  int x = 0, xx;
  while (m--) {
    scanf("%d", &xx);
    x ^= xx;
    printf("%d\n", query(x));
  }
  return 0;
}
