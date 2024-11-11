#include <bits/stdc++.h>
using namespace std;
void addmod(int &a, long long b) {
  a = (a + b);
  if (a >= 1000000007) a -= 1000000007;
}
void mulmod(int &a, long long b) { a = (a * b) % 1000000007; }
template <class T>
bool domin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool domax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int gi() {
  int a;
  scanf("%d", &a);
  return a;
}
long long gll() {
  long long a;
  scanf("%lld", &a);
  return a;
}
class graphal {
 public:
  int n;
  vector<vector<int> > ed;
  vector<bool> vis;
  int t = 0;
  vector<int> tb, te, sz;
  graphal(const int &n) : n(n), ed(n), vis(n, false), tb(n), te(n), sz(n, 0) {}
  void reset(int n) {
    ed.clear();
    this->n = n;
    ed.resize(n);
  }
  void add(int a, int b) { ed[a].push_back(b); }
  void dfs(int v) {
    vis[v] = true;
    tb[v] = ++t;
    sz[v] = 1;
    for (auto i : ed[v]) {
      dfs(i);
      sz[v] += sz[i];
    }
    te[v] = ++t;
  }
  void doit() {
    for (int i = 0; i < n; i++)
      if (!vis[i]) {
        dfs(i);
      }
  }
  bool isanc(int a, int b) {
    if (tb[b] > tb[a] && tb[b] < te[a]) return true;
    return false;
  }
};
int main() {
  int n = gi(), m = gi(), k = gi(), q = gi();
  graphal g(n);
  vector<int> t(100005, -1);
  for (int i = 0; i < k; i++) {
    int a = gi() - 1, b = gi();
    if (t[b] != -1) g.add(t[b], a);
    t[b] = a;
  }
  g.doit();
  for (int i = 0; i < q; i++) {
    int x = gi() - 1, y = gi();
    if (t[y] == -1 || !g.isanc(x, t[y])) {
      cout << 0 << endl;
    } else {
      cout << g.sz[x];
    }
  }
  return 0;
}
