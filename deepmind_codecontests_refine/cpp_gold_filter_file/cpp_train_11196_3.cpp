#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
template <typename T, typename Z>
inline T power(T base, Z exponent) {
  T ret = 1;
  for (; exponent > 0; exponent >>= 1, base *= base)
    if (exponent & 1) ret *= base;
  return ret;
}
template <typename Z>
Z gcd(const Z& a, const Z& b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename Z>
Z extended_gcd(const Z& a, const Z& b, Z& x, Z& y) {
  if (b == 0) return x = 1, y = 0, a;
  Z gcd = extended_gcd(b, a % b, y, x);
  y -= (a / b) * x;
  return gcd;
}
template <typename... T>
void debug(T&&... args) {
  ((cerr << args << " "), ..., (cerr << "\n"));
}
const ll INFL = numeric_limits<ll>::max() / 2;
const ll INF = numeric_limits<int>::max() / 2;
const ll MOD = 1e9 + 7;
const int K = 256;
struct node {
  static int cnt;
  int id = 0;
  int value = 0;
  node* next[K];
  node *link, *parent;
  node(node* _parent = nullptr) : id(cnt++), next(), parent(_parent) {}
};
void add(node* root, const string& s, int value) {
  node* cur = root;
  for (char ch : s) {
    int c = ch - 'a';
    if (cur->next[c] == nullptr) {
      cur->next[c] = new node(cur);
    }
    cur = cur->next[c];
  }
  cur->value += value;
}
vector<node*> push_links(node* const root) {
  vector<node*> ret;
  queue<node*> Q;
  root->link = root;
  Q.push(root);
  while (!Q.empty()) {
    node* cur = Q.front();
    ret.push_back(cur);
    Q.pop();
    if (cur->link != cur) cur->value += cur->link->value;
    for (int c = 0; c < K; c++) {
      node* next = cur->next[c];
      if (next != nullptr) {
        if (cur == root)
          next->link = cur;
        else
          next->link = cur->link->next[c];
        Q.push(next);
      } else {
        if (cur == root) cur->next[c] = root;
        cur->next[c] = cur->link->next[c];
      }
    }
  }
  return ret;
}
int node::cnt = 0;
const int N = 250;
ll m[N][N], t[N][N], ans[N][N];
int a[N];
void solve() {
  int n;
  ll l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) cin >> a[i];
  node* root = new node();
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    add(root, s, a[i]);
  }
  vector<node*> nodes = push_links(root);
  int z = (static_cast<int>(nodes.size()));
  for (int i = 0; i < z; i++)
    for (int j = 0; j < z; j++) t[i][j] = m[i][j] = ans[i][j] = -INF;
  for (const auto v : nodes) {
    for (int c = 0; c < K; c++) {
      int i = v->id, j = v->next[c]->id;
      ans[i][j] = m[i][j] = v->next[c]->value;
    }
  }
  while (l > 0) {
    if (l % 2) {
      for (int k = 0; k < z; k++)
        for (int i = 0; i < z; i++)
          for (int j = 0; j < z; j++) {
            t[i][j] = max(t[i][j], ans[i][k] + m[k][j]);
          }
      for (int i = 0; i < z; i++)
        for (int j = 0; j < z; j++) {
          ans[i][j] = t[i][j];
          t[i][j] = -INF;
        }
    }
    for (int k = 0; k < z; k++)
      for (int i = 0; i < z; i++)
        for (int j = 0; j < z; j++) {
          t[i][j] = max(t[i][j], m[i][k] + m[k][j]);
        }
    for (int i = 0; i < z; i++)
      for (int j = 0; j < z; j++) {
        m[i][j] = t[i][j];
        t[i][j] = -INF;
      }
    l /= 2;
  }
  cout << ans[0][0] << "\n";
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
