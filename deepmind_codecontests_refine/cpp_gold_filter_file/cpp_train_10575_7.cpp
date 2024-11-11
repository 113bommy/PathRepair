#include <bits/stdc++.h>
using namespace std;
int trie[650000][26];
int optimizare[300010];
int liber;
int n;
int unite(int x, int y, int& ans);
void dfs(int nod, int level);
int main() {
  ios_base ::sync_with_stdio(0);
  int a, b;
  char c;
  cin >> n;
  for (int i(1); i < n; i++) {
    cin >> a >> b >> c;
    trie[a][c - 'a'] = b;
  }
  dfs(1, 1);
  int optim(1e9), level;
  for (int i(1); i <= n; i++) {
    if (n - optimizare[i] < optim) optim = n - optimizare[i], level = i;
  }
  cout << optim << '\n' << level << '\n';
}
void dfs(int nod, int level) {
  liber = n + 1;
  int loc(n + 1), ans(0);
  for (int i(0); i < 26; i++) loc = unite(loc, trie[nod][i], ans);
  optimizare[level] += ans;
  for (int i(0); i < 26; i++)
    if (trie[nod][i]) dfs(trie[nod][i], level + 1);
}
int unite(int x, int y, int& ans) {
  if (x == 0 || y == 0) return x + y;
  ans++;
  int a(++liber);
  for (int i(0); i < 26; i++) trie[a][i] = unite(trie[x][i], trie[y][i], ans);
  return a;
}
