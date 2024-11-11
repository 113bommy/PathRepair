#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const int N = 1e5 + 10;
const int M = 2e5 + 10;
struct Node {
  Node *left, *right;
  int a, b;
  int min_v;
};
Node pool[N << 1], *last;
void build(Node*& cur, int a, int b) {
  cur = last++;
  cur->a = a;
  cur->b = b;
  cur->min_v = -1;
  if (a + 1 == b) return;
  build(cur->left, a, (a + b) / 2);
  build(cur->right, (a + b) / 2, b);
}
int A, B;
void insert(Node* cur) {
  if (cur->a + 1 == cur->b) {
    cur->min_v = B;
    return;
  }
  if ((cur->a + cur->b) / 2 > A)
    insert(cur->left);
  else
    insert(cur->right);
  cur->min_v = min(cur->left->min_v, cur->right->min_v);
}
int query(Node* cur) {
  if (cur->a >= A && cur->b <= B) {
    return cur->min_v;
  }
  int ret = INF;
  if ((cur->a + cur->b) / 2 > A) ret = min(ret, query(cur->left));
  if ((cur->a + cur->b) / 2 < B) ret = min(ret, query(cur->right));
  return ret;
}
struct Rect {
  int x1, x2, y1, y2;
  int idx;
  bool flag;
  Rect() {}
  Rect(int x1, int x2, int y1, int y2) : x1(x1), x2(x2), y1(y1), y2(y2) {}
};
bool operator<(const Rect& a, const Rect& b) { return a.x2 < b.x2; }
pair<int, int> a[M];
Rect b[M];
bool ret[M];
void run(int m, int k, int q) {
  sort(a, a + k);
  sort(b, b + q);
  Node* root;
  last = pool;
  build(root, 0, m);
  for (int i = 0, j = 0; i < q; ++i) {
    for (; j < k && a[j].first < b[i].x2; ++j) {
      A = a[j].second;
      B = a[j].first;
      insert(root);
    }
    A = b[i].y1;
    B = b[i].y2;
    b[i].flag |= (query(root) >= b[i].x1);
  }
}
int main() {
  int n, m, k, q;
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < k; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
    --a[i].first;
    --a[i].second;
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d%d", &b[i].x1, &b[i].y1, &b[i].x2, &b[i].y2);
    --b[i].x1;
    --b[i].y1;
    b[i].idx = i;
    b[i].flag = false;
  }
  run(m, k, q);
  for (int i = 0; i < k; ++i) swap(a[i].first, a[i].second);
  for (int i = 0; i < q; ++i) {
    swap(b[i].x1, b[i].y1);
    swap(b[i].x2, b[i].y2);
  }
  run(n, k, q);
  for (int i = 0; i < q; ++i) {
    ret[b[i].idx] = b[i].flag;
  }
  for (int i = 0; i < q; ++i) {
    puts(ret[i] ? "YES" : "NO");
  }
  return 0;
}
