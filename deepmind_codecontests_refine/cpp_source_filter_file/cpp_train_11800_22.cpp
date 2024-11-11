#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9 + 9;
const int MAXN = 2002;
const int MAXL = 505;
const int MAXC = 30;
int n, k;
string s;
struct trie {
  int nxt[MAXC] = {0};
  int end = 0, c = 0;
} tree[MAXN * MAXL];
int treeSZ = 1;
struct node {
  int size[2] = {0, 0};
  int lft = 0, sib = 0;
  int c;
} nodes[MAXN * MAXL];
int nodesSZ = 0;
void add_string() {
  int u = 0;
  for (char c : s) {
    int id = c - 'a';
    if (tree[u].nxt[id] == 0) {
      tree[u].nxt[id] = treeSZ++;
    }
    u = tree[u].nxt[id];
  }
  tree[u].end++;
}
void dfs(int u) {
  for (int *v = tree[u].nxt; *v != 0; v++) {
    int c = 1;
    while (tree[*v].nxt[0] != 0 && tree[*v].nxt[1] == 0 && tree[*v].end == 0) {
      *v = tree[*v].nxt[0];
      c++;
    }
    tree[*v].c = c;
    dfs(*v);
  }
}
void dfs2(int u) {
  int id = nodesSZ++;
  int l = 0;
  for (int *v = tree[u].nxt; *v != 0; v++) {
    if (l == 0)
      nodes[u].lft = nodesSZ;
    else
      nodes[l].sib = nodesSZ;
    l = nodesSZ;
    dfs2(*v);
    *v = l;
    nodes[id].size[0] += nodes[*v].size[0];
  }
  int sz = nodes[id].size[0];
  for (int *v = tree[u].nxt; *v != 0; v++) {
    nodes[*v].size[1] = sz;
    sz -= nodes[*v].size[0];
  }
  nodes[id].c = tree[u].c;
  nodes[id].size[0] += tree[u].end;
}
void preprocess() {
  for (int u = 0; u < treeSZ; u++) {
    int del = 0;
    for (int j = 0; j < MAXC; j++) {
      tree[u].nxt[j - del] = tree[u].nxt[j];
      if (tree[u].nxt[j] == 0) del++;
    }
    tree[u].nxt[MAXC - del] = 0;
  }
  dfs(0);
  dfs2(0);
}
ll mem[MAXN * 3][MAXN];
ll dp(int u, int m) {
  if (mem[u][m] != -1) return mem[u][m];
  if (m > nodes[u].size[1]) exit(-1);
  if (m < 0) exit(-2);
  if (u == 0) return mem[u][m] = 0;
  mem[u][m] = 0;
  int &lft = nodes[u].lft, &sib = nodes[u].sib;
  for (int i = max(m - nodes[sib].size[1], 0); i <= m && i <= nodes[u].size[0];
       i++) {
    mem[u][m] =
        max(mem[u][m], dp(lft, min(i, nodes[lft].size[1])) +
                           i * (i - 1) / 2 * nodes[u].c + dp(sib, m - i));
  }
  return mem[u][m];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s;
    add_string();
  }
  preprocess();
  assert(nodes[0].size[1] == 0);
  assert(nodes[0].size[0] == n);
  assert(nodes[nodes[0].lft].size[1] == n);
  memset(mem, -1, sizeof mem);
  cout << dp(nodes[0].lft, k) << endl;
}
