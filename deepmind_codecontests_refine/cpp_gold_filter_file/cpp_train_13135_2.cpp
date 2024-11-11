#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n;
int a[N];
int vis[1 << 21];
bool trie[1 << 22];
void cover(int x) {
  if (trie[x | (1 << 21)]) return;
  int v = x | (1 << 21);
  while (v) {
    trie[v] = true;
    v >>= 1;
  }
  for (int i = 0; i <= 20; ++i)
    if ((x >> i) & 1) cover(x ^ (1 << i));
}
void dfs1(int x, int i) {
  if (trie[x | (1 << 21)]) return;
  if (vis[x] == i) return;
  if (vis[x]) return cover(x);
  vis[x] = i;
  for (int k = 0; k <= 20; ++k)
    if ((x >> k) & 1) dfs1(x ^ (1 << k), i);
}
int qry(int x) {
  int o = 1;
  for (int i = 20; i >= 0; --i) {
    if ((x >> i) & 1)
      o <<= 1;
    else if (trie[(o << 1) | 1]) {
      x |= 1 << i;
      o = (o << 1) | 1;
    } else
      o <<= 1;
  }
  return x;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = n; i; --i) {
    if (i <= n - 2) ans = max(ans, qry(a[i]));
    dfs1(a[i], i);
  }
  printf("%d\n", ans);
  return 0;
}
