#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const int C = 3;
const int MOD[C] = {1000000007, 1000000009, 1000000021};
int p2[C][N << 1];
struct Node *null;
struct Node {
  int key;
  int val[C];
  int size, len, hash[C];
  Node *ch[2];
  Node() {
    key = INT_MAX;
    size = 0;
    len = 0;
    for (int i = 0; i < C; ++i) {
      val[i] = hash[i] = 0;
    }
  }
  Node(int _val[C], int _len) {
    len = _len;
    size = 0;
    for (int i = 0; i < C; ++i) {
      val[i] = _val[i];
      hash[i] = val[i];
    }
    key = bigRand();
    ch[0] = ch[1] = null;
  }
  int bigRand() { return rand() * RAND_MAX + rand(); }
  void update() {
    size = ch[0]->size + ch[1]->size + len;
    for (int i = 0; i < C; ++i) {
      hash[i] = (ch[0]->hash[i] + (long long)val[i] * p2[i][ch[0]->size] +
                 (long long)ch[1]->hash[i] * p2[i][ch[0]->size + len]) %
                MOD[i];
    }
  }
};
struct Treap {
  int cmp(const int a[C], const int b[C]) {
    for (int i = 0; i < C; ++i) {
      if (a[i] != b[i]) return a[i] - b[i];
    }
    return 0;
  }
  Node *root;
  int hsh[C];
  int len;
  Treap() {
    root = null;
    len = 2;
    for (int i = 0; i < C; ++i) {
      hsh[i] = 2;
    }
  }
  void update_info() {
    len = root->size + 2;
    for (int i = 0; i < C; ++i) {
      hsh[i] = (root->hash[i] * 2ll + p2[i][len - 1]) % MOD[i];
    }
  }
  void rot(Node *&t, int d) {
    Node *p = t->ch[d];
    t->ch[d] = p->ch[!d];
    p->ch[!d] = t;
    t->update();
    p->update();
    t = p;
  }
  void insert(Node *&t, int val[C], int len) {
    if (t == null) {
      t = new Node(val, len);
      return;
    }
    int dir = cmp(val, t->val) >= 0;
    insert(t->ch[dir], val, len);
    if (t->ch[dir]->key < t->key)
      rot(t, dir);
    else
      t->update();
  }
  void erase(Node *&t, int val[C]) {
    if (t == null) return;
    if (cmp(t->val, val) == 0) {
      int dir = t->ch[1]->key < t->ch[0]->key;
      if (t->ch[dir] == null) {
        delete t;
        t = null;
        return;
      }
      rot(t, dir);
      erase(t->ch[!dir], val);
      t->update();
      return;
    }
    bool dir = (cmp(val, t->val) > 0);
    erase(t->ch[dir], val);
    t->update();
  }
  void insert(int val[C], int len) {
    insert(root, val, len);
    update_info();
  }
  void erase(int val[C]) {
    erase(root, val);
    update_info();
  }
};
int n;
vector<int> adj[N];
Treap *root[N];
int ret, retu;
map<vector<int>, int> freq;
void insert(int vec[C]) {
  vector<int> v(vec, vec + C);
  freq[v]++;
}
void erase(int vec[C]) {
  vector<int> v(vec, vec + C);
  int &u = freq[v];
  --u;
  if (u == 0) {
    freq.erase(v);
  }
}
void get(int u, int f) {
  for (auto v : adj[u]) {
    if (v == f) continue;
    get(v, u);
    root[u]->insert(root[v]->hsh, root[v]->len);
  }
  insert(root[u]->hsh);
}
void dfs(int u, int f) {
  if ((int)freq.size() > ret) {
    ret = freq.size();
    retu = u;
  }
  for (auto v : adj[u]) {
    if (v == f) continue;
    erase(root[u]->hsh);
    root[u]->erase(root[v]->hsh);
    insert(root[u]->hsh);
    erase(root[v]->hsh);
    root[v]->insert(root[u]->hsh, root[u]->len);
    insert(root[v]->hsh);
    dfs(v, u);
    erase(root[v]->hsh);
    root[v]->erase(root[u]->hsh);
    insert(root[v]->hsh);
    erase(root[u]->hsh);
    root[u]->insert(root[v]->hsh, root[v]->len);
    insert(root[u]->hsh);
  }
}
void solve() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    root[i] = new Treap();
  }
  freq.clear();
  get(0, -1);
  ret = -1;
  dfs(0, -1);
  cout << retu + 1 << endl;
}
int main() {
  for (int i = 0; i < C; ++i) {
    p2[i][0] = 1;
    for (int j = 1; j < N * 2; ++j) {
      p2[i][j] = p2[i][j - 1] * 2 % MOD[i];
    }
  }
  null = new Node();
  solve();
  return 0;
}
