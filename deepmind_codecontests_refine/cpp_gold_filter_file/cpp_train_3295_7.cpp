#include <bits/stdc++.h>
using namespace std;
const int maxn = 101010;
int n, p, idx, nxt, bit, ret, a[3 * maxn], trie[50 * maxn][2], sz[50 * maxn];
int go(int num, int pos) { return (num & (1 << pos) ? 1 : 0); }
void insert(int num) {
  nxt = 1;
  for (int i = 29; i >= 0; --i) {
    bit = go(num, i);
    if (!trie[nxt][bit]) trie[nxt][bit] = ++idx;
    ++sz[nxt], nxt = trie[nxt][bit];
  }
  ++sz[nxt];
}
int get(int num) {
  nxt = 1, ret = 0;
  for (int i = 29; i >= 0; --i) {
    bit = go(num, i), --sz[nxt];
    if (trie[nxt][bit] && sz[trie[nxt][bit]])
      nxt = trie[nxt][bit];
    else
      ret |= (1 << i), nxt = trie[nxt][!bit];
  }
  --sz[nxt];
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n, idx = 1;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> p, insert(p);
  for (int i = 0; i < n; ++i) cout << get(a[i]) << " ";
  cout << endl;
  return 0;
}
