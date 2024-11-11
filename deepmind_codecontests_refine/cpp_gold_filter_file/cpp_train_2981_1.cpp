#include <bits/stdc++.h>
#pragma GCC target("sse2")
#pragma GCC optimization("O2")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize "trapv"
using namespace std;
const int maxn = 1000500;
inline int g() {
  int x;
  cin >> x;
  return x;
}
inline long long gl() {
  long long x;
  cin >> x;
  return x;
}
inline char gc() {
  char x;
  cin >> x;
  return x;
}
inline string gs() {
  string s;
  cin >> s;
  return s;
}
template <typename T>
inline vector<T> gv(int len) {
  vector<T> a(len);
  for (auto &it : a) cin >> it;
  return a;
}
inline vector<int> gv(int len) {
  vector<int> a(len);
  for (auto &it : a) cin >> it;
  return a;
}
inline vector<pair<int, int>> gv_andPairCnt(int len) {
  vector<pair<int, int>> a(len);
  int i = 1;
  for (auto &it : a) {
    it.second = i;
    i++;
    cin >> it.first;
  }
  return a;
}
double power_log(double power, double val) { return log(val) / log(power); }
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto it : v) os << it << ", ";
  os << "\n";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &v) {
  os << "deque:{";
  for (auto it : v) os << it << " ";
  os << "}\n";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "set:{";
  for (auto it : v) os << it << " ";
  os << "}";
  return os;
}
template <typename T, typename T2>
ostream &operator<<(ostream &os, const map<T, T2> &v) {
  os << "map:{\n";
  for (auto it : v) os << "    {" << it.first << " <> " << it.second << "}\n";
  os << "}\n";
  return os;
}
template <typename T, typename T2>
ostream &operator<<(ostream &os, const pair<T, T2> &v) {
  os << "{" << v.first << ", " << v.second << "}";
  return os;
}
template <typename T, typename H>
inline vector<pair<T, H>> gv_andBiPair(int len) {
  vector<pair<T, H>> a(len);
  for (auto &it : a) {
    cin >> it.first >> it.second;
  }
  return a;
}
template <typename T>
inline set<T> vector_to_set(const vector<T> &vec) {
  set<T> s;
  for (auto &it : vec) s.insert(it);
  return s;
}
const long long md = 1e9 + 7;
struct Node {
  Node *l = nullptr, *r = nullptr;
  int sign = -1, cnt = 0, lvl = -1;
};
bool isNull(Node *src) { return src == nullptr || src->cnt == 0; }
bool isOne(int msk, int val) { return (msk & (1 << val)) > 0; }
void add(Node *root, int val) {
  root->cnt++;
  for (int i = 30; i >= 0; i--) {
    if (isOne(val, i)) {
      if (root->r == nullptr) {
        root->r = new Node();
      }
      root = root->r;
      root->sign = 1;
    } else {
      if (root->l == nullptr) {
        root->l = new Node();
      }
      root->sign = 0;
      root = root->l;
    }
    root->lvl = i;
    root->cnt++;
  }
}
long long ans = 0;
int sol(Node *tree1, Node *tree2) {
  int s = INT_MAX;
  if (isNull(tree1) || isNull(tree2)) {
    return 0;
  }
  if (!isNull(tree1) && tree1->lvl == 0) {
    return 0;
  }
  if (!isNull(tree2) && tree2->lvl == 0) {
    return 0;
  }
  if (!isNull(tree1->l) && !isNull(tree2->l)) {
    s = min(s, sol(tree1->l, tree2->l));
  }
  if (!isNull(tree1->r) && !isNull(tree2->r)) {
    s = min(s, sol(tree1->r, tree2->r));
  }
  if (s != INT_MAX) {
    return s;
  }
  if (!isNull(tree1->l) && !isNull(tree2->r)) {
    assert(tree1->l->lvl == tree2->r->lvl);
    s = min(s, (1 << tree1->l->lvl) + sol(tree1->l, tree2->r));
  }
  if (!isNull(tree1->r) && !isNull(tree2->l)) {
    assert(tree1->r->lvl == tree2->l->lvl);
    s = min(s, (1 << tree1->r->lvl) + sol(tree1->r, tree2->l));
  }
  return s;
}
void solve(Node *root) {
  if (isNull(root)) {
    return;
  }
  if (root->lvl == 0) {
    return;
  }
  solve(root->l);
  solve(root->r);
  if (!isNull(root->l) && !isNull(root->r)) {
    ans += (1 << ((root->lvl) - 1)) + sol(root->l, root->r);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Node *root = new Node();
  root->lvl = 31;
  int n = g();
  auto v = gv(n);
  auto st = vector_to_set(v);
  for (auto &it : st) {
    add(root, it);
  }
  solve(root);
  cout << ans;
}
