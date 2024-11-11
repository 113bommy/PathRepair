#include <bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 5;
const int MAX_BITS = 5;
int trie[MAX_BITS * nax][2];
int cnt[MAX_BITS * nax];
int dfs(int u = 0) {
  if (cnt[u] < 2) return cnt[u];
  int left = 0, right = 0;
  if (trie[u][0]) left = dfs(trie[u][0]);
  if (trie[u][1]) right = dfs(trie[u][1]);
  return max(left + min(1, right), right + min(1, left));
}
int main() {
  int n;
  cin >> n;
  for (int i = 0, idx = 1; i < n; i++) {
    int num;
    cin >> num;
    int node = 0;
    for (int bits = MAX_BITS; bits-- > 0;) {
      bool bit = (bool)((num >> bits) & 1);
      if (!trie[node][bit]) trie[node][bit] = idx++;
      cnt[node]++;
      node = trie[node][bit];
    }
    cnt[node]++;
  }
  cout << n - dfs() << "\n";
  return 0;
}
