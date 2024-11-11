#include <bits/stdc++.h>
template <class T, class AddFunc = std::plus<T>>
class BinIndexedTree {
 private:
  std::vector<T> node;
  int size;
  AddFunc func;

 public:
  BinIndexedTree(int _size, const T& _val = T()) : size(_size) {
    node.resize(size + 1, _val);
  }
  template <class RAIter>
  BinIndexedTree(RAIter _begin, RAIter _end) : size(_end - _begin) {
    for (int i = 1; _begin != _end; ++i, ++_begin) add(*_begin, i);
  }
  template <class Iter>
  BinIndexedTree(int _size, Iter _begin) : size(_size) {
    for (int i = 1; i <= size; ++i, ++_begin) add(*_begin, i);
  }
  void add(const T& _val, int _pos) {
    for (; _pos <= size; up(_pos)) node[_pos] = func(node[_pos], _val);
  }
  T query(int _pos) {
    T res = T();
    for (; _pos; down(_pos)) res = func(res, node[_pos]);
    return res;
  }

 private:
  void up(int& x) { x += (x & -x); }
  void down(int& x) { x -= (x & -x); }
};
inline void accelerateIO() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
}
const int maxN = 1000005;
struct Query {
  int left, right;
  int idx;
  int disXor = 0;
  friend std::istream& operator>>(std::istream& ist, Query& obj) {
    ist >> obj.left >> obj.right;
    return ist;
  }
};
int n, q;
int val[maxN];
int pref[maxN];
int ans[maxN];
Query qry[maxN];
void input() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", val + i);
  pref[0] = 0;
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] ^ val[i];
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) scanf("%d%d", &qry[i].left, &qry[i].right);
  for (int i = 1; i <= q; i++) qry[i].idx = i;
}
struct Xor {
  int operator()(int x, int y) { return x ^ y; }
};
void initQry() {
  auto cmpRight = [](const Query& A, const Query& B) -> bool {
    return A.right < B.right;
  };
  BinIndexedTree<int, Xor> bitree(n);
  std::unordered_map<int, int> mp;
  std::sort(qry, qry + q, cmpRight);
  for (int i = 1, curq = 1; i <= n && curq <= q; ++i) {
    if (!mp.count(val[i]))
      mp.insert(std::pair<int, int>(val[i], i));
    else {
      bitree.add(val[i], mp.at(val[i]));
      mp.at(val[i]) = i;
    }
    bitree.add(val[i], i);
    for (; curq <= q && qry[curq].right == i; curq++)
      qry[curq].disXor =
          bitree.query(qry[curq].right) ^ bitree.query(qry[curq].left - 1);
  }
}
void solve() {
  initQry();
  for (int i = 1; i <= q; i++) {
    Query& cur = qry[i];
    ans[cur.idx] = pref[cur.right] ^ pref[cur.left - 1] ^ cur.disXor;
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
}
int main() {
  input();
  solve();
  return 0;
}
