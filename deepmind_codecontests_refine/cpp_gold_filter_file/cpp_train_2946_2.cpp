#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
const double eps = 1e-9;
const int mod = 1000000007;
struct node {
  int rev;
  int n4, n7, n47, n74;
  node* l;
  node* r;
  node() {
    n4 = n7 = n47 = n74 = rev = 0;
    l = r = NULL;
  }
};
typedef node* pt;
string s;
void build(pt nroot, int L, int R) {
  if (L == R - 1) {
    if (s[L] == '4')
      nroot->n4 = 1;
    else
      nroot->n7 = 1;
    return;
  }
  int m = (L + R) >> 1;
  nroot->l = new node();
  nroot->r = new node();
  build(nroot->l, L, m);
  build(nroot->r, m, R);
  nroot->n4 = nroot->l->n4 + nroot->r->n4;
  nroot->n7 = nroot->l->n7 + nroot->r->n7;
  nroot->n47 =
      max(nroot->l->n4 + nroot->r->n47,
          max(nroot->l->n4 + nroot->r->n7, nroot->l->n47 + nroot->r->n7));
  nroot->n74 =
      max(nroot->l->n7 + nroot->r->n74,
          max(nroot->l->n7 + nroot->r->n4, nroot->l->n74 + nroot->r->n4));
}
void push(pt nroot) {
  if (nroot->rev) {
    swap(nroot->n4, nroot->n7);
    swap(nroot->n47, nroot->n74);
    nroot->rev = 0;
    if (nroot->l) nroot->l->rev ^= 1;
    if (nroot->r) nroot->r->rev ^= 1;
  }
}
void _switch(pt nroot, int L, int R, int l, int r) {
  push(nroot);
  if (R <= l || L >= r) return;
  if (l <= L && r >= R) {
    nroot->rev ^= 1;
    push(nroot);
    return;
  }
  int m = (L + R) >> 1;
  _switch(nroot->l, L, m, l, r);
  _switch(nroot->r, m, R, l, r);
  nroot->n4 = nroot->l->n4 + nroot->r->n4;
  nroot->n7 = nroot->l->n7 + nroot->r->n7;
  nroot->n47 =
      max(nroot->l->n4 + nroot->r->n47,
          max(nroot->l->n4 + nroot->r->n7, nroot->l->n47 + nroot->r->n7));
  nroot->n74 =
      max(nroot->l->n7 + nroot->r->n74,
          max(nroot->l->n7 + nroot->r->n4, nroot->l->n74 + nroot->r->n4));
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  cin >> s;
  pt root = new node();
  build(root, 0, n);
  for (int i = 0; i < m; i++) {
    string q;
    cin >> q;
    if (q == "count") {
      cout << max(root->n47, max(root->n4, root->n7)) << endl;
    } else {
      int l, r;
      cin >> l >> r;
      _switch(root, 0, n, l - 1, r);
    }
  }
  return 0;
}
