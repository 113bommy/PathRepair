#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 17) + 1;
template <class T>
struct Node {
  Node *left;
  Node *right;
  T value;
};
int mod(long long a, int b) { return (a % b + b) % b; }
template <class T>
struct Tree {
  int begin;
  int end;
  int delta;
  Node<T> *root;
  void init(int M) {
    end = M;
    begin = 0;
    delta = 0;
    root = NULL;
  }
  void deleteSubTree(Node<T> *t) {
    if (t == NULL) return;
    deleteTree(t->left);
    deleteTree(t->right);
  }
  void insert(int begin, int end, T value) {
    if (0)
      cout << "insert: "
           << "begin"
           << ":" << (begin) << " "
           << "end"
           << ":" << (end) << " "
           << "value"
           << ":" << (value) << " " << endl;
    int b = mod(begin - delta, end);
    int e = mod(end - delta, end);
    if (b < e) {
      root = insert(root, this->begin, this->end, b, e, value);
    } else {
      root = insert(root, this->begin, this->end, 0, e, value);
      root = insert(root, this->begin, this->end, b, end, value);
    }
  }
  void deleteSubtree(Node<T> *node) {
    if (node == NULL) return;
    deleteSubtree(node->left);
    deleteSubtree(node->right);
    delete node;
  }
  Node<T> *insert(Node<T> *root, int rbegin, int rend, int begin, int end,
                  T value, T pvalue = T()) {
    if (begin >= rend or end <= rbegin) return root;
    if (root == NULL) {
      root = new Node<T>();
      root->value = pvalue;
    }
    if (rbegin == begin and rend == end) {
      deleteSubtree(root->left);
      deleteSubtree(root->right);
      root->left = root->right = NULL;
      root->value = value;
      return root;
    }
    int mid = (rbegin + rend) / 2;
    root->left = insert(root->left, rbegin, mid, begin, min(mid, end), value,
                        root->value);
    root->right = insert(root->right, mid, rend, max(begin, mid), end, value,
                         root->value);
    return root;
  }
  T get(int idx) { return get(root, begin, end, mod(idx - delta, end)); }
  T get(Node<T> *root, int rbegin, int rend, int idx) {
    int mid = (rbegin + rend) / 2;
    if (idx < mid) {
      if (root->left == NULL) return root->value;
      return get(root->left, rbegin, mid, idx);
    } else {
      if (root->right == NULL) return root->value;
      return get(root->right, mid, rend, idx);
    }
  }
  void shift(int delta) { this->delta = mod(this->delta - delta, end); }
  void print() {
    if (0)
      cout << "delta"
           << ":" << (delta) << " " << endl;
    print(root, begin, end, 0);
  }
  void print(Node<T> *root, int begin, int end, int indent) {
    if (root != NULL) {
      int mid = (begin + end) / 2;
      print(root->right, mid, end, indent + 1);
      for (int i = (0); i < (indent); ++i)
        if (0) cout << " ";
      if (0)
        cout << "(" << begin << ", " << end << "): " << root->value << endl;
      print(root->left, begin, mid, indent + 1);
    }
  }
  void rprint() {
    for (int i = (0); i < (end); ++i)
      if (0) cout << get(i) << ((i == end - 1) ? '\n' : ' ');
  }
};
int n, g, r, M;
long long len[MAXN];
long long suf[MAXN];
long long pref[MAXN];
long long dist[MAXN];
int nxt[MAXN];
Tree<int> t;
long long hitRed(long long d, int nx) {
  if (nx == n + 1) return d;
  return d + (M - d % M) + dist[nx];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> g >> r;
  M = g + r;
  t.init(M);
  for (int i = (0); i < (n + 1); ++i) cin >> len[i];
  dist[n + 1] = 0;
  pref[0] = 0;
  suf[n + 1] = 0;
  for (int i = (1); i < (n + 2); ++i) pref[i] = len[i - 1] + pref[i - 1];
  for (int i = (n + 1) - 1; i >= (0); --i) suf[i] = len[i] + suf[i + 1];
  t.insert(0, M, n + 1);
  for (int i = (n + 1) - 1; i >= (1); --i) {
    t.shift(len[i]);
    nxt[i] = t.get(0);
    dist[i] = hitRed(suf[i] - suf[nxt[i]], nxt[i]);
    t.insert(g, M, i);
    if (0)
      cout << "i"
           << ":" << (i) << " "
           << "dist[i]"
           << ":" << (dist[i]) << " "
           << "nxt[i]"
           << ":" << (nxt[i]) << " " << endl;
    if (0) t.print();
    if (0) t.rprint();
  }
  t.shift(len[0]);
  if (0) t.print();
  if (0) t.rprint();
  int q;
  cin >> q;
  for (int i = (0); i < (q); ++i) {
    long long b;
    cin >> b;
    long long bb = b % M;
    int nt = t.get(bb);
    if (0)
      cout << "b"
           << ":" << (b) << " "
           << "bb"
           << ":" << (bb) << " "
           << "nt"
           << ":" << (nt) << " " << endl;
    cout << (b / M * M + hitRed(bb + suf[0] - suf[nt], nt)) << endl;
  }
  return 0;
}
