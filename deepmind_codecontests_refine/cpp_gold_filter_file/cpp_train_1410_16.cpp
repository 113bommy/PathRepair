#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b, long long MOD) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
const int maxn = 1e5 + 10;
struct Node {
  int val;
  Node *left, *right, *fa;
};
struct cmp {
  bool operator()(const Node* p1, const Node* p2) const {
    return p1->val < p2->val;
  }
};
Node tree[maxn];
set<Node*, cmp> S;
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n + 1; ++i) scanf("%d", &tree[i].val);
  tree[0].val = 0;
  tree[n + 1].val = 1e9 + 100;
  S.insert(&tree[0]);
  S.insert(&tree[n + 1]);
  for (int i = 1; i < n + 1; ++i) {
    auto c = S.insert(&tree[i]).first;
    Node* p = *c;
    Node* p1 = *(--c);
    ++c, ++c;
    Node* p2 = (c == S.end()) ? 0 : *c;
    if (p1 && !p1->right) {
      p1->right = p;
      p->fa = p1;
    } else if (p2 && !p2->left) {
      p2->left = p;
      p->fa = p2;
    }
  }
  printf("%d", tree[2].fa->val);
  for (int i = 3; i < n + 1; ++i) printf(" %d", tree[i].fa->val);
  printf("\n");
}
