#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000005];
int in[1000005];
int out[1000005];
int ans[1000005];
int t;
void dfs(int k, int f, int Min) {
  in[k] = t++;
  ans[in[k]] = min(Min, k);
  for (int i = 0; i < v[k].size(); i++) {
    if (v[k][i] != f) dfs(v[k][i], k, ans[in[k]]);
  }
  out[k] = t;
}
struct Node {
  Node *l, *r;
  int tag, Min, a, b;
  Node(int c, int d) : a(c), b(d), l(NULL), r(NULL) {
    if (c == d) Min = ans[c];
    tag = 1e9;
  }
} * root;
void push(Node *n) {
  if (!n->l) {
    n->l = new Node(n->a, (n->a + n->b) / 2);
    n->r = new Node((n->a + n->b) / 2 + 1, n->b);
  }
  n->l->tag = min(n->l->tag, n->tag);
  n->r->tag = min(n->r->tag, n->tag);
}
void revise(Node *n, int l, int r, int a) {
  if (l > r) return;
  if (n->a == l && n->b == r) {
    n->tag = min(n->tag, a);
    return;
  }
  push(n);
  revise(n->l, l, min(n->l->b, r), a);
  revise(n->r, max(n->r->a, l), r, a);
}
int ask(Node *n, int first) {
  if (n->a == first && n->b == first) return min(n->tag, n->Min);
  push(n);
  if (first > (n->a + n->b) / 2)
    return ask(n->r, first);
  else
    return ask(n->l, first);
}
int main() {
  t = 1;
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  root = new Node(1, n);
  q--;
  int op, k, last = 0;
  scanf("%d %d", &op, &k);
  k = k % n + 1;
  dfs(k, 0, 1e9);
  while (q--) {
    scanf("%d", &op);
    if (op == 1) {
      int first;
      scanf("%d", &first);
      first = (first + last) % n + 1;
      revise(root, 1, in[first] - 1, ans[in[first]]);
      revise(root, out[first] + 1, n, ans[in[first]]);
    } else {
      int first;
      scanf("%d", &first);
      first = (first + last) % n + 1;
      last = ask(root, in[first]);
      printf("%d\n", last);
    }
  }
}
