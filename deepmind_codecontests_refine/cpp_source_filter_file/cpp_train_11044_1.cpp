#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 2;
int Next[N], Prev[N];
int in[N];
struct Node {
  Node *Left, *Right;
  pair<int, int> val;
  Node() {
    Left = Right = NULL;
    val.first = 1e9;
    val.second = 1e9;
  }
};
Node *update(Node *root, int l, int r, int ind, int val) {
  if (l == r) {
    Node *leaf = new Node();
    leaf->val.first = val;
    leaf->val.second = ind;
    return leaf;
  } else {
    Node *newNode = new Node();
    int mid = (l + r) / 2;
    Node *leftNode = NULL, *rightNode = NULL;
    if (root != NULL) {
      leftNode = root->Left;
      rightNode = root->Right;
    }
    if (ind <= mid) {
      newNode->Left = update(leftNode, l, mid, ind, val);
      newNode->Right = rightNode;
    } else {
      newNode->Left = leftNode;
      newNode->Right = update(rightNode, mid + 1, r, ind, val);
    }
    if (newNode->Left != NULL) {
      newNode->val = newNode->Left->val;
    }
    if (newNode->Right != NULL) {
      newNode->val = min(newNode->val, newNode->Right->val);
    }
    return newNode;
  }
}
pair<int, int> query(Node *node, int l, int r, int ql, int qr) {
  if (qr < l || r < ql || node == NULL) {
    return make_pair(1e9, 0);
  }
  if (l <= ql && qr <= r) {
    return node->val;
  }
  int mid = (l + r) / 2;
  return min(query(node->Left, l, mid, ql, qr),
             query(node->Left, mid + 1, r, ql, qr));
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &in[i]);
  }
  map<int, int> hash;
  vector<pair<int, int> > v;
  for (int i = n; i >= 1; --i) {
    Next[i] = n + 1;
    if (hash.count(in[i])) {
      Next[i] = hash[in[i]];
    }
    v.push_back(make_pair(Next[i], i));
    hash[in[i]] = i;
  }
  hash.clear();
  for (int i = 1; i <= n; ++i) {
    Prev[i] = 0;
    if (hash.count(in[i])) {
      Prev[i] = hash[in[i]];
    }
    hash[in[i]] = i;
  }
  hash.clear();
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  vector<Node *> nodeList;
  Node *PrevNode = new Node();
  for (int i = 0; i < v.size(); ++i) {
    int id = v[i].second;
    Node *cur = update(PrevNode, 1, n, id, Prev[id]);
    nodeList.push_back(cur);
    PrevNode = cur;
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    int x = -1, y = v.size() - 1, mid;
    while (x < y) {
      mid = (x + y + 1) / 2;
      if (r < v[mid].first) {
        x = mid;
      } else {
        y = mid - 1;
      }
    }
    if (x == -1) {
      printf("0\n");
    } else {
      Node *cur = nodeList[x];
      pair<int, int> tmp = query(cur, 1, n, l, r);
      if (tmp.first < l) {
        printf("%d\n", in[tmp.second]);
      } else {
        printf("0\n");
      }
    }
  }
}
int main() { solve(); }
