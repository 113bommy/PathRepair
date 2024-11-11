#include <bits/stdc++.h>
using namespace std;
typedef struct Trie* Arbore;
struct Trie {
  int g = 0;
  Arbore fii[27];
  Trie() {
    for (int i(0); i < 27; i++) fii[i] = 0;
  }
};
int dp[300010];
Arbore coresp[300010];
vector<pair<int, char>> adia[300010];
int optimizare[300010];
int add(Arbore x, Arbore& n);
int weight(Arbore x, Arbore y);
Arbore mk_trie(int nod);
void calc_dp(int nod);
int maxim(int nod, int level);
int main() {
  int n, a, b;
  char c;
  ios_base ::sync_with_stdio(0);
  cin >> n;
  while (--n) {
    cin >> a >> b >> c;
    adia[a].push_back({b, c});
  }
  Arbore k = mk_trie(1);
  calc_dp(1);
  int q(maxim(1, 1));
  cout << k->g - optimizare[q] << '\n' << q;
  return 0;
}
int maxim(int nod, int level) {
  optimizare[level] += dp[nod];
  int g(level);
  for (auto i : adia[nod]) {
    int q(maxim(i.first, level + 1));
    if (optimizare[q] > optimizare[g]) g = q;
  }
  return g;
}
void calc_dp(int nod) {
  Arbore x(coresp[nod]);
  int gmax = -1, fiumax;
  for (int i(0); i < 27; i++) {
    if (x->fii[i] != 0 && x->fii[i]->g > gmax) gmax = x->fii[i]->g, fiumax = i;
  }
  if (gmax == -1) {
    dp[nod] = 1;
    return;
  }
  Arbore suma = 0;
  for (int i(0); i < 27; i++) {
    if (i != fiumax && x->fii[i] != 0) add(x->fii[i], suma);
  }
  dp[nod] = x->g - weight(suma, x->fii[fiumax]);
  for (auto i : adia[nod]) calc_dp(i.first);
}
Arbore mk_trie(int nod) {
  Arbore x = new Trie();
  x->g = 1;
  for (auto i : adia[nod]) {
    x->fii[i.second - 'a'] = mk_trie(i.first);
    x->g += x->fii[i.second - 'a']->g;
  }
  coresp[nod] = x;
  return x;
}
int weight(Arbore x, Arbore y) {
  if (x == 0 && y == 0) return 0;
  if (x == 0) return y->g;
  if (y == 0) return x->g;
  int ans(1);
  for (int i(0); i < 27; i++) ans += weight(x->fii[i], y->fii[i]);
  return ans;
}
int add(Arbore x, Arbore& n) {
  if (x == 0) return 0;
  int ans(0);
  if (n == 0) {
    n = new Trie();
    ans = 1;
  }
  for (int i(0); i < 27; i++) ans += add(x->fii[i], n->fii[i]);
  n->g += ans;
  return ans;
}
