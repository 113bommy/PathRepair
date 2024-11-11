#include <bits/stdc++.h>
using namespace std;
int amount;
int message[300005];
int per_key[300005];
int node = 0;
struct Trie {
  int child[2];
  int passed = 0;
} tree[300005];
int add_node() {
  node++;
  tree[node].child[0] = tree[node].child[1] = 0;
  tree[node].passed = 0;
  return node;
}
void add_num(int num) {
  int root = 1;
  for (int i = 30; i >= 0; i--) {
    int bit = (num >> i) & 1;
    if (!tree[root].child[bit]) tree[root].child[bit] = add_node();
    root = tree[root].child[bit];
    tree[root].passed++;
  }
}
int get_num(int num) {
  int root = 1;
  int res = 0;
  for (int i = 30; i >= 0; i--) {
    int bit = (num >> i) & 1;
    if (!tree[root].child[bit] || !tree[tree[root].child[bit]].passed) {
      res += (1 << i);
      root = tree[root].child[1 - bit];
    } else
      root = tree[root].child[bit];
    tree[root].passed--;
  }
  return res;
}
void solve() {
  add_node();
  for (int i = 1; i <= amount; i++) add_num(per_key[i]);
  for (int i = 1; i <= amount; i++) printf("%d ", get_num(message[i]));
}
int main() {
  scanf("%d", &amount);
  for (int i = 1; i <= amount; i++) scanf("%d", &message[i]);
  for (int i = 1; i <= amount; i++) scanf("%d", &per_key[i]);
  solve();
}
