#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long double PI = acosl(-1);
const long long inf = 1e15;
const int nmax = 2e5 + 5;
struct node {
  bool white, black;
  bool whiteisleaf, blackisleaf;
  int childs[2];
  node() {
    childs[0] = childs[1] = -1;
    white = black = false;
    whiteisleaf = blackisleaf = false;
  }
};
node trie[34 * nmax];
int cnt = 1;
bool vor(int id, unsigned int mask, int sz, char c) {
  if (c == '+')
    trie[id].white = true;
  else
    trie[id].black = true;
  bool ret = true;
  if (c == '+' and trie[id].blackisleaf) ret = false;
  if (c == '-' and trie[id].whiteisleaf) ret = false;
  if (sz == 0) {
    if (c == '+')
      trie[id].whiteisleaf = true;
    else
      trie[id].blackisleaf = true;
    if (trie[id].black && c == '+') return false;
    if (trie[id].white && c == '-') return false;
    return true;
  }
  int x = (mask & (1 << 31)) ? 1 : 0;
  if (trie[id].childs[x] == -1) {
    trie[id].childs[x] = cnt++;
  }
  return ret && vor(trie[id].childs[x], mask << 1, sz - 1, c);
}
vector<pair<unsigned int, int> > output;
int dfs(int id, int len, unsigned int mask) {
  if (id == -1) return 0;
  if (trie[id].black && !trie[id].white) {
    output.push_back({mask, len});
    return 1;
  }
  if (trie[id].white && !trie[id].black) return 0;
  int ans = 0;
  ans += dfs(trie[id].childs[0], len + 1, mask);
  ans += dfs(trie[id].childs[1], len + 1, mask | (1 << (31 - len)));
  return ans;
}
int main() {
  int n;
  scanf("%d%*c", &n);
  bool possible = true;
  for (int i = 0; i < n; i++) {
    int part, sz = 32;
    unsigned int x = 0;
    char c, d;
    scanf("%c", &c);
    scanf("%d%*c", &part);
    x |= (part << 24);
    scanf("%d%*c", &part);
    x |= (part << 16);
    scanf("%d%*c", &part);
    x |= (part << 8);
    scanf("%d%c", &part, &d);
    x |= (part);
    if (d == '/') scanf("%d%*c", &sz);
    possible = possible && vor(0, x, 32, c);
  }
  if (!possible) {
    printf("-1");
    return 0;
  }
  int ans = dfs(0, 0, 0);
  printf("%d\n", ans);
  for (auto p : output) {
    unsigned int mask = p.first;
    printf("%u.", mask >> 24);
    printf("%u.", (mask << 8) >> 24);
    printf("%u.", (mask << 16) >> 24);
    printf("%u/", (mask << 24) >> 24);
    printf("%d\n", p.second);
  }
}
