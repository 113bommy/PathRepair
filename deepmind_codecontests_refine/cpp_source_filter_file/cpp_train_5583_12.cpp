#include <bits/stdc++.h>
using namespace std;
int k;
struct Node {
  int rec[2][11], sz;
  Node() {
    for (int i = 0; i < (k); ++i) rec[1][i] = 1000000009;
    sz = 1;
  }
  Node(int val[]) {
    for (int i = 0; i < (k); ++i) {
      rec[0][i] = rec[1][i] = val[i];
    }
    sz = 1;
  }
  void Union(Node node) {
    for (int i = 0; i < (k); ++i) {
      rec[0][i] = max(node.rec[0][i], rec[0][i]);
      rec[1][i] = min(node.rec[0][i], rec[1][i]);
    }
    sz += node.sz;
  }
  bool operator<(const Node node) const {
    for (int i = 0; i < (k); ++i)
      if (rec[0][i] >= node.rec[1][i]) return false;
    return true;
  }
  bool operator==(const Node node) const {
    return (!(*this < node)) && (!(node < *this));
  }
  bool operator<=(const Node node) const {
    return *this < node || *this == node;
  }
};
const int maxn = 100006;
int root, cnt = 1;
struct Treap {
  Node key;
  int pri, sz, son[2];
  void setval(Node x, int z = 1) {
    static int seed = 3312;
    key = x;
    pri = seed = (int)((long long)seed * 48271 % 2147483647);
    sz = z;
    son[0] = son[1] = 0;
  }
} T[maxn];
void Rotate(int &x, int p) {
  int y = T[x].son[!p];
  T[x].son[!p] = T[y].son[p];
  T[y].son[p] = x;
  T[y].sz = T[x].sz;
  T[x].sz = T[T[x].son[0]].sz + 1 + T[T[x].son[1]].sz;
  x = y;
}
void Insert(int &x, Node val) {
  if (x == 0) {
    T[x = cnt++].setval(val);
  } else {
    ++T[x].sz;
    int p = T[x].key < val;
    Insert(T[x].son[p], val);
    if (T[x].pri > T[T[x].son[p]].pri) Rotate(x, !p);
  }
}
void Erase(int &x, Node val) {
  if (T[x].key == val) {
    if (T[x].son[0] && T[x].son[1]) {
      --T[x].sz;
      int p = T[T[x].son[0]].pri < T[T[x].son[1]].pri;
      Rotate(x, p);
      Erase(T[x].son[p], val);
    } else {
      if (!T[x].son[0])
        x = T[x].son[1];
      else
        x = T[x].son[0];
    }
  } else {
    --T[x].sz;
    int p = T[x].key < val;
    Erase(T[x].son[p], val);
  }
}
int Lower_bound(int &x, Node key, int last = -1) {
  if (x == 0) return last;
  if (T[x].key == key) return x;
  if (T[x].key < key) return Lower_bound(T[x].son[1], key, last);
  if (T[x].son[0] == 0) return x;
  return Lower_bound(T[x].son[0], key, x);
}
int Upper_bound(int &x, Node key, int last = -1) {
  if (x == 0) return last;
  if (T[x].key <= key) return Upper_bound(T[x].son[1], key, last);
  if (T[x].son[0] == 0) return x;
  return Upper_bound(T[x].son[0], key, x);
}
int getans(int x) {
  if (x == 0) return 0;
  if (T[x].son[1] == 0) return T[x].key.sz;
  return getans(T[x].son[1]);
}
int main() {
  int n, val[11];
  scanf("%d %d", &n, &k);
  for (int id = 0; id < (n); ++id) {
    for (int i = 0; i < (k); ++i) {
      scanf("%d", &val[i]);
    }
    Node now(val), tmp = now;
    int p1 = Lower_bound(root, tmp), p2 = Upper_bound(root, tmp);
    if (p1 != -1) {
      while (p1 != p2) {
        now.Union(T[p1].key);
        Erase(root, T[p1].key);
        p1 = Lower_bound(root, tmp);
      }
    }
    Insert(root, now);
    printf("%d\n", getans(root));
  }
  return 0;
}
