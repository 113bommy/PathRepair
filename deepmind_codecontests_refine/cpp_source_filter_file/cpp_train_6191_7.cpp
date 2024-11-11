#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7FFFFFFF;
const double PI = 3.1415926535897932384626433832795;
template <class T, int N = 1024>
class Pool {
  struct Item : public T {
    Item* next;
  };
  struct Chunk {
    Item items[N];
    int used;
    Chunk* next;
  };
  Chunk* chunks;
  Item* freed;

 public:
  Pool() : chunks(NULL), freed(NULL) {}
  ~Pool() {
    while (chunks) {
      Chunk* next = chunks->next;
      delete chunks;
      chunks = next;
    }
  }
  T* alloc() {
    if (freed) {
      T* result = freed;
      freed = freed->next;
      return result;
    }
    if (!chunks || chunks->used >= N) {
      Chunk* ch = new Chunk;
      ch->used = 0;
      ch->next = chunks;
      chunks = ch;
    }
    return &chunks->items[chunks->used++];
  }
  void free(T* ptr) {
    ((Item*)ptr)->next = freed;
    freed = (Item*)ptr;
  }
};
struct Path;
struct Node {
  Node* parent;
  vector<Node*> children;
  int size;
  int depth;
  int index;
  int pindex;
  int cut;
  multiset<int> prices;
  Path* path;
  int price() { return *prices.begin(); }
  Node() : parent(NULL), path(NULL), size(1) {}
};
Pool<Node> npool;
bool nodecomp(Node* a, Node* b) { return a->depth < b->depth; }
struct Path {
  Node* parent;
  vector<Node*> nodes;
  int size;
  vector<int> tree;
  Path() : parent(NULL) {}
  void build();
  int get(Node* a, Node* b);
  void update(Node* n);
};
Pool<Path> ppool;
const int MAXN = 131072;
int vis[MAXN];
int tin[MAXN];
int fup[MAXN];
int iscut[MAXN];
vector<int> ve[MAXN];
int timer = 0;
Node* vnode[MAXN];
int value[MAXN];
vector<int> vstack;
Node* root;
void cutvertex(int v, int u0) {
  iscut[v] = 1;
  if (!vnode[v]) {
    vnode[v] = npool.alloc();
    vnode[v]->cut = 1;
    vnode[v]->prices.insert(value[v]);
  }
  Node* mid = npool.alloc();
  mid->parent = vnode[v];
  mid->prices.insert(INF);
  vnode[v]->children.push_back(mid);
  while (true) {
    int u = vstack.back();
    vstack.pop_back();
    if (vnode[u]) {
      vnode[u]->parent = mid;
      mid->children.push_back(vnode[u]);
    } else {
      vnode[u] = mid;
    }
    mid->prices.insert(value[u]);
    if (u == u0) break;
  }
}
void dfs1(int v, int p = -1) {
  vis[v] = 1;
  tin[v] = fup[v] = timer++;
  vstack.push_back(v);
  int children = 0;
  for (int u : ve[v]) {
    if (u == p) continue;
    if (vis[u]) {
      fup[v] = min(fup[v], tin[u]);
    } else {
      dfs1(u, v);
      fup[v] = min(fup[v], fup[u]);
      if (fup[u] >= tin[v]) {
        cutvertex(v, u);
      }
    }
  }
  if (p < 0) {
    if (!vnode[v]) {
      vnode[v] = npool.alloc();
      vnode[v]->prices.insert(value[v]);
    } else if (vnode[v]->children.size() == 1) {
      vnode[v] = vnode[v]->children[0];
      vnode[v]->parent = NULL;
      vnode[v]->prices.insert(value[v]);
    }
    root = vnode[v];
  }
}
const int MAXO = MAXN * 4;
Node* otree[MAXO * 2];
Node** norder = otree + MAXO;
int ncount = 0;
void lcabuild() {
  for (int i = (ncount); i < (MAXO); i++) otree[i + MAXO] = otree[i - 1 + MAXO];
  for (int i = (MAXO)-1; i >= 1; i--)
    otree[i] =
        (otree[i + i]->depth < otree[i + i + 1]->depth ? otree[i + i]
                                                       : otree[i + i + 1]);
}
Node* lca(Node* a, Node* b) {
  int l = a->index + MAXO;
  int r = b->index + MAXO;
  if (l > r) swap(l, r);
  Node* result = (otree[l]->depth < otree[r]->depth ? otree[l] : otree[r]);
  while (l < r - 1) {
    if (!(l & 1) && otree[l + 1]->depth < result->depth) result = otree[l + 1];
    if ((r & 1) && otree[r - 1]->depth < result->depth) result = otree[r - 1];
    l /= 2;
    r /= 2;
  }
  return result;
}
Path* dfs3(Node* v, int d = 0) {
  v->depth = d;
  v->index = ncount;
  norder[ncount++] = v;
  Node* heavy = NULL;
  for (Node* u : v->children) {
    dfs3(u, d + 1);
    norder[ncount++] = v;
    v->size += u->size;
    if (!heavy || u->size > heavy->size) {
      heavy = u;
    }
  }
  if (heavy && heavy->size + heavy->size >= v->size) {
    v->path = heavy->path;
  } else {
    v->path = ppool.alloc();
  }
  v->path->nodes.push_back(v);
  for (Node* u : v->children) {
    if (u->path != v->path) {
      u->path->parent = v;
      u->path->build();
    }
  }
  return v->path;
}
void Path::build() {
  sort(nodes.begin(), nodes.end(), nodecomp);
  size = 1;
  while (size < nodes.size()) size *= 2;
  tree.resize(size * 2);
  for (int i = (0); i < (nodes.size()); i++)
    tree[i + size] = nodes[i]->price(), nodes[i]->pindex = i;
  for (int i = (nodes.size()); i < (size); i++) tree[i + size] = 0;
  for (int i = (size)-1; i >= 1; i--)
    tree[i] = min(tree[i + i], tree[i + i + 1]);
}
int Path::get(Node* a, Node* b) {
  int l = (a ? a->pindex : 0) + size;
  int r = b->pindex + size;
  int res = min(tree[l], tree[r]);
  while (l < r - 1) {
    if (!(l & 1)) res = min(res, tree[l + 1]);
    if (r & 1) res = min(res, tree[r - 1]);
    l /= 2;
    r /= 2;
  }
  return res;
}
void Path::update(Node* n) {
  int i = n->pindex + size;
  tree[i] = n->price();
  for (i /= 2; i; i /= 2) tree[i] = min(tree[i + i], tree[i + i + 1]);
}
void init() {
  dfs1(0, -1);
  dfs3(root)->build();
  lcabuild();
}
void change(int v, int w) {
  int old = value[v];
  value[v] = w;
  vnode[v]->prices.erase(vnode[v]->prices.find(old));
  vnode[v]->prices.insert(w);
  vnode[v]->path->update(vnode[v]);
  if (iscut[v] && vnode[v]->parent && !vnode[v]->parent->cut) {
    vnode[v]->parent->prices.erase(vnode[v]->parent->prices.find(old));
    vnode[v]->parent->prices.insert(value[v]);
    vnode[v]->parent->path->update(vnode[v]->parent);
  }
}
int answer(int a, int b) {
  if (a == b) return value[a];
  Node* x = vnode[a];
  Node* y = vnode[b];
  Node* z = lca(x, y);
  if (!z->cut && z->parent) {
    z = z->parent;
  }
  int answer = min(value[a], value[b]);
  for (Node* cur = x; cur != z->path->parent; cur = cur->path->parent) {
    answer = min(answer, cur->path->get(cur->path == z->path ? z : NULL, cur));
  }
  for (Node* cur = y; cur != z->path->parent; cur = cur->path->parent) {
    answer = min(answer, cur->path->get(cur->path == z->path ? z : NULL, cur));
  }
  return answer;
}
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = (0); i < (n); i++) scanf("%d", &value[i]);
  for (int i = (0); i < (m); i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    ve[a].push_back(b);
    ve[b].push_back(a);
  }
  init();
  for (int i = (0); i < (q); i++) {
    char qt[4];
    int a, b;
    scanf("%s%d%d", qt, &a, &b);
    if (qt[0] == 'C') {
      change(a - 1, b);
    } else if (qt[0] == 'A') {
      printf("%d\n", answer(a - 1, b - 1));
    }
  }
}
