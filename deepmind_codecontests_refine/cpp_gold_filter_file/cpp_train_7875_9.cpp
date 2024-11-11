#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int> divs[maxn];
struct node {
  struct node *ch[2];
  int val;
  node() {}
};
node *new_node() {
  node *temp = new node;
  temp->val = 1e9;
  temp->ch[0] = temp->ch[1] = NULL;
  return temp;
}
node *trie[maxn];
void add(node *root, int x) {
  node *y = root;
  y->val = min(y->val, x);
  for (int i = 18; i >= 0; i--) {
    bool bit = bool(x & (1 << i));
    if (y->ch[bit] == NULL) y->ch[bit] = new_node();
    y = y->ch[bit];
    y->val = min(y->val, x);
  }
}
int query(node *root, int x, int s) {
  if (root->val + x > s) return -1;
  node *y = root;
  int ans = 0;
  for (int i = 18; i >= 0; i--) {
    bool bit = bool(x & (1 << i));
    if (y->ch[!bit] != NULL && y->ch[!bit]->val + x <= s) {
      ans += ((!bit) << i);
      y = y->ch[!bit];
    } else if (y->ch[bit] != NULL) {
      ans += (bit << i);
      y = y->ch[bit];
    }
  }
  return ans;
}
int main() {
  for (int i = 1; i < maxn; i++) {
    for (int j = i; j < maxn; j += i) {
      divs[j].push_back(i);
    }
  }
  for (int i = 1; i < maxn; i++) {
    trie[i] = new_node();
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int u;
      scanf("%d", &u);
      for (auto &t : divs[u]) {
        add(trie[t], u);
      }
    } else {
      int x, k, s;
      scanf("%d %d %d", &x, &k, &s);
      if (x % k) {
        puts("-1");
        continue;
      }
      printf("%d\n", query(trie[k], x, s));
    }
  }
  return 0;
}
