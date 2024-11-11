#include <bits/stdc++.h>
using namespace std;
int getint() {
  unsigned int c;
  int x = 0;
  while (((c = getchar()) - '0') >= 10) {
    if (c == '-') return -getint();
    if (!~c) exit(0);
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while (((c = getchar()) - '0') < 10);
  return x;
}
int getstr(char* s) {
  int c, n = 0;
  while ((c = getchar()) <= ' ') {
    if (!~c) exit(0);
  }
  do {
    s[n++] = c;
  } while ((c = getchar()) > ' ');
  s[n] = 0;
  return n;
}
template <class T>
inline bool chmin(T& a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
unsigned int xrand() {
  static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
  int t = x ^ x << 11;
  x = y;
  y = z;
  z = w;
  return w = w ^ w >> 19 ^ t ^ t >> 8;
}
typedef int Kt;
struct Node;
typedef Node* Nptr;
struct Node {
  Nptr p[2];
  int pri;
  Kt key;
  int val;
  int s;
  Node() {}
  Nptr up() {
    if (!this) return this;
    s = 1 + getL()->size() + getR()->size();
    return this;
  }
  long long sum() {
    if (this) return val;
    return 0;
  }
  Nptr getL() {
    if (this) return p[0];
    return 0;
  }
  Nptr getR() {
    if (this) return p[1];
    return 0;
  }
  int size() {
    if (this) return s;
    return 0;
  }
  bool is() { return this != 0; }
  string str() {
    if (!this) return "";
    stringstream ss;
    ss << key << ' ' << val << ' ' << pri << ' ' << s;
    return ss.str();
  }
};
const int MAX_NODE = 333000;
Node nodes[MAX_NODE];
int n_ptr;
inline Nptr single_node() {
  Nptr t = nodes + n_ptr++;
  t->p[0] = t->p[1] = 0, t->pri = xrand(), t->s = 1;
  return t;
}
inline Nptr single_node(const Kt& key, const int& val) {
  Nptr t = single_node();
  t->key = key, t->val = val;
  return t;
}
Nptr rotate(Nptr p, int s) {
  Nptr q = p->p[s ^ 1];
  p->p[s ^ 1] = q->p[s], q->p[s] = p, p->up();
  return q->up();
}
Nptr search(Nptr p, const Kt& key) {
  if (!p) return p;
  if (key < p->key) return search(p->p[0], key);
  if (key > p->key) return search(p->p[1], key);
  return p;
}
Nptr remove(Nptr p, const Kt& key) {
  if (!p) return p;
  if (p->key != key) {
    int s = (key < p->key) ? 0 : 1;
    p->p[s] = remove(p->p[s], key);
    return p->up();
  }
  if (p->p[0] == 0 and p->p[1] == 0)
    return 0;
  else if (p->p[0] == 0)
    p = rotate(p, 0);
  else if (p->p[1] == 0)
    p = rotate(p, 1);
  else {
    int s = (p->p[0]->pri < p->p[1]->pri) ? 1 : 0;
    p = rotate(p, s);
  }
  p = remove(p, key);
  return p->up();
}
Nptr insert(Nptr p, Nptr q) {
  if (!p) return q;
  int s = (q->key < p->key) ? 0 : 1;
  p->p[s] = insert(p->p[s], q);
  if (p->pri > p->p[s]->pri) p = rotate(p, s ^ 1);
  return p->up();
}
Nptr kth_node(Nptr p, int k) {
  if (!p) return p;
  if (k == p->p[0]->size()) return p;
  if (k < p->p[0]->size()) return kth_node(p->p[0], k);
  return kth_node(p->p[1], k - 1 - p->p[0]->size());
}
Nptr go_root(Nptr p, Nptr q) {
  q->pri = p->pri - 1;
  p = remove(p, q->key);
  return insert(p, q);
}
Nptr lower_bound(Nptr p, const Kt& key) {
  if (!p) return p;
  Nptr q;
  if (p->key < key) return lower_bound(p->getR(), key);
  if (p->key > key) {
    q = lower_bound(p->getL(), key);
    if (!q or p->key < q->key) return p;
    return q;
  }
  return p;
}
Nptr previous(Nptr u, Nptr p) {
  if (!u) return 0;
  if (!p) {
    while (p->getR()) p = p->getR();
    return p;
  }
  if (p->key <= u->key) return previous(u->getL(), p);
  Nptr q = previous(u->getR(), p);
  if (!q) return u;
  return q;
}
int n, m, in[333][333];
int fl, up, dn;
int cost(int next, int now) {
  if (next > now) return up;
  if (next < now) return dn;
  return fl;
}
int accR[333][333];
int accL[333][333];
int accU[333][333];
int accD[333][333];
void prepare() {
  int i, j;
  for (i = 0; i < n; i++)
    for (j = m - 2; ~j; --j)
      accR[i][j] = accR[i][j + 1] + cost(in[i][j + 1], in[i][j]);
  for (i = 0; i < n; i++)
    for (j = 1; j < m; j++)
      accL[i][j] = accL[i][j - 1] + cost(in[i][j - 1], in[i][j]);
  for (j = 0; j < m; j++)
    for (i = n - 2; ~i; --i)
      accD[i][j] = accD[i + 1][j] + cost(in[i + 1][j], in[i][j]);
  for (j = 0; j < m; j++)
    for (i = 1; i < n; i++)
      accU[i][j] = accU[i - 1][j] + cost(in[i - 1][j], in[i][j]);
}
int main() {
  int i, j, tcc, tc = 1 << 28;
  for (tcc = 0; tcc < tc; tcc++) {
    n = getint();
    m = getint();
    int total = getint();
    fl = getint(), up = getint(), dn = getint();
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) in[i][j] = getint();
    prepare();
    int res = 1e9;
    int x1 = 44, x2 = 33, y1 = 22, y2 = 11;
    for (int leftCol = 0; leftCol < m; leftCol++) {
      for (int rightCol = leftCol + 2; rightCol < m; rightCol++) {
        n_ptr = 0;
        Nptr costSet = 0;
        for (i = n - 3; ~i; --i) {
          int addRow = i + 2;
          int partsCost = -accD[addRow][rightCol] + accU[addRow][leftCol] +
                          accL[addRow][rightCol] - accL[addRow][leftCol];
          Nptr nnode = single_node(partsCost, addRow);
          costSet = insert(costSet, nnode);
          int nowCost = accD[i][rightCol] - accU[i][leftCol] +
                        accR[i][leftCol] - accR[i][rightCol];
          int want = total - nowCost;
          Nptr it = lower_bound(costSet, want);
          if (it) {
            if (chmin(res, abs(total - it->key - nowCost))) {
              x1 = i, x2 = it->val, y1 = leftCol, y2 = rightCol;
            }
          }
          it = previous(costSet, it);
          if (it) {
            if (chmin(res, abs(total - it->key - nowCost))) {
              x1 = i, x2 = it->val, y1 = leftCol, y2 = rightCol;
            }
          }
        }
      }
    }
    cerr << " res = " << res << endl;
    printf("%d %d %d %d\n", ++x1, ++y1, ++x2, ++y2);
  }
  return 0;
}
