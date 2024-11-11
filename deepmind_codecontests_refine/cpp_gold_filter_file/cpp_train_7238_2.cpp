#include <bits/stdc++.h>
using namespace std;
struct trie {
  trie* child[2];
  int cnt;
  trie() {
    child[0] = child[1] = NULL;
    cnt = 0;
  }
} * root;
int n, k, sum;
long long res;
void add(int val) {
  trie* node = root;
  for (int i = 29; i >= 0; i--) {
    int j = (val >> i) & 1;
    if (!node->child[j]) node->child[j] = new trie;
    node = node->child[j];
    node->cnt++;
  }
}
void get(trie* node, int i, int val, int remain) {
  if (i == -1) return;
  if (remain > (1 << (i + 1)) - 1) return;
  int j = (val >> i) & 1;
  if (node->child[j ^ 1]) {
    if ((1 << i) >= remain)
      res += node->child[j ^ 1]->cnt;
    else
      get(node->child[j ^ 1], i - 1, val, remain - (1 << i));
  }
  if (node->child[j]) get(node->child[j], i - 1, val, remain);
}
int main(int argc, char const* argv[]) {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  root = new trie;
  add(0);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    sum ^= a;
    get(root, 29, sum, k);
    add(sum);
  }
  cout << res;
  return 0;
}
