#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::deque;
using std::get;
using std::greater;
using std::ifstream;
using std::ios_base;
using std::less;
using std::list;
using std::lower_bound;
using std::make_pair;
using std::make_tuple;
using std::map;
using std::max;
using std::max_element;
using std::min;
using std::min_element;
using std::multimap;
using std::multiset;
using std::ofstream;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::swap;
using std::tuple;
using std::unordered_map;
using std::unordered_multimap;
using std::unordered_set;
using std::upper_bound;
using std::vector;
[[maybe_unused]] const string endl = "\n";
[[maybe_unused]] const string sep = " ";
[[maybe_unused]] const string yes = "YES\n";
[[maybe_unused]] const string no = "NO\n";
[[maybe_unused]] const string ng = "NG\n";
[[maybe_unused]] const string ok = "OK\n";
[[maybe_unused]] const double pi = acos(-1);
[[maybe_unused]] const unsigned long long modular = 1e9 + 7;
template <class T>
T min(const T &a, const T &b, const T &c) {
  return min(a, min(b, c));
}
template <class T>
T max(const T &a, const T &b, const T &c) {
  return max(a, max(b, c));
}
vector<long long> lca_h, lca_dfs_list, lca_first, lca_tree;
vector<char> lca_dfs_used;
void lca_dfs(const vector<vector<long long>> &g, long long v, long long h = 1) {
  lca_dfs_used[v] = true;
  lca_h[v] = h;
  lca_dfs_list.push_back(v);
  for (auto i = g[v].begin(); i != g[v].end(); ++i)
    if (!lca_dfs_used[*i]) {
      lca_dfs(g, *i, h + 1);
      lca_dfs_list.push_back(v);
    }
}
void lca_build_tree(long long i, long long l, long long r) {
  if (l == r)
    lca_tree[i] = lca_dfs_list[l];
  else {
    long long m = (l + r) >> 1;
    lca_build_tree(i + i, l, m);
    lca_build_tree(i + i + 1, m + 1, r);
    if (lca_h[lca_tree[i + i]] < lca_h[lca_tree[i + i + 1]])
      lca_tree[i] = lca_tree[i + i];
    else
      lca_tree[i] = lca_tree[i + i + 1];
  }
}
void lca_prepare(const vector<vector<long long>> &g, long long root) {
  long long n = (long long)g.size();
  lca_h.resize(n);
  lca_dfs_list.reserve(n * 2);
  lca_dfs_used.assign(n, 0);
  lca_dfs(g, root);
  long long m = (long long)lca_dfs_list.size();
  lca_tree.assign(lca_dfs_list.size() * 4 + 1, -1);
  lca_build_tree(1, 0, m - 1);
  lca_first.assign(n, -1);
  for (long long i = 0; i < m; ++i) {
    long long v = lca_dfs_list[i];
    if (lca_first[v] == -1) lca_first[v] = i;
  }
}
long long lca_tree_min(long long i, long long sl, long long sr, long long l,
                       long long r) {
  if (sl == l && sr == r) return lca_tree[i];
  long long sm = (sl + sr) >> 1;
  if (r <= sm) return lca_tree_min(i + i, sl, sm, l, r);
  if (l > sm) return lca_tree_min(i + i + 1, sm + 1, sr, l, r);
  long long ans1 = lca_tree_min(i + i, sl, sm, l, sm);
  long long ans2 = lca_tree_min(i + i + 1, sm + 1, sr, sm + 1, r);
  return lca_h[ans1] < lca_h[ans2] ? ans1 : ans2;
}
long long lca(long long a, long long b) {
  long long left = lca_first[a], right = lca_first[b];
  if (left > right) swap(left, right);
  return lca_tree_min(1, 0, (long long)lca_dfs_list.size() - 1, left, right);
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long fast_power(long long a, long long pow) {
  if (pow == 0) {
    return 1;
  }
  if (pow % 2 == 0) {
    auto x = fast_power(a, pow / 2);
    return (x * x);
  } else {
    auto x = fast_power(a, pow - 1);
    return (a * x);
  }
}
long long fast_power(long long a, long long pow, long long mod) {
  if (pow == 0) {
    return 1;
  }
  if (pow % 2 == 0) {
    auto x = fast_power(a, pow / 2, mod);
    return (x * x) % mod;
  } else {
    auto x = fast_power(a, pow - 1, mod);
    return (a * x) % mod;
  }
}
void getFactorialsModular(const long long n, const long long mod,
                          vector<long long> &F) {
  F.resize(n + 1);
  F[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    F[i] = (F[i - 1] * i) % mod;
  }
}
void getFactorialsAndInverseModular(const long long n, const long long mod,
                                    vector<long long> &F,
                                    vector<long long> &I) {
  getFactorialsModular(n, mod, F);
  I.resize(n + 1);
  I[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    I[i] = fast_power(F[i], mod - 2, mod);
  }
}
long long CnkMod(long long n, long long k, long long mod, vector<long long> &F,
                 vector<long long> &I) {
  return (((F[n] * I[k]) % mod) * I[n - k]) % mod;
}
long long CnkWithRepetitionMod(long long n, long long k, long long mod,
                               vector<long long> &F, vector<long long> &I) {
  return CnkMod(n + k - 1, k - 1, mod, F, I);
}
template <typename valueType, typename tagType>
class segmentTreeNode {
 public:
  int id, left, right;
  valueType val;
  tagType tag;
};
template <typename valueType, typename tagType,
          valueType (*merge)(valueType, valueType),
          void (*update)(segmentTreeNode<valueType, tagType> &, tagType)>
class segmentTree {
 private:
  std::vector<segmentTreeNode<valueType, tagType>> nodes;
  int leftRange, rightRange;
  valueType valueZero;
  tagType tagZero;
  void push_up(int cur) {
    nodes[cur].val = merge(nodes[cur << 1].val, nodes[cur << 1 | 1].val);
  }
  void push_down(int cur) {
    update(nodes[cur << 1], nodes[cur].tag);
    update(nodes[cur << 1 | 1], nodes[cur].tag);
    nodes[cur].tag = tagZero;
  }
  void build(int cur, int l, int r, const std::vector<valueType> &initValue) {
    nodes[cur].id = cur;
    nodes[cur].left = l;
    nodes[cur].right = r;
    nodes[cur].tag = tagZero;
    if (l == r - 1)
      nodes[cur].val = initValue[l - leftRange];
    else {
      build(cur << 1, l, (l + r) >> 1, initValue);
      build(cur << 1 | 1, (l + r) >> 1, r, initValue);
      push_up(cur);
    }
  }
  void init(const std::vector<valueType> &_initValue,
            const valueType &_valueZero, const tagType &_tagZero) {
    valueZero = _valueZero;
    tagZero = _tagZero;
    nodes.resize((rightRange - leftRange) << 2);
    build(1, leftRange, rightRange, _initValue);
  }
  void modify(int cur, int l, int r, int L, int R, const tagType &tag) {
    if (l >= R || r <= L) return;
    if (L <= l && r <= R)
      update(nodes[cur], tag);
    else {
      push_down(cur);
      modify(cur << 1, l, (l + r) >> 1, L, R, tag);
      modify(cur << 1 | 1, (l + r) >> 1, r, L, R, tag);
      push_up(cur);
    }
  }
  valueType query(int cur, int l, int r, int L, int R) {
    if (l >= R || r <= L) return valueZero;
    if (L <= l && r <= R) return nodes[cur].val;
    push_down(cur);
    return merge(query(cur << 1, l, (l + r) >> 1, L, R),
                 query(cur << 1 | 1, (l + r) >> 1, r, L, R));
  }

 public:
  segmentTree() {}
  segmentTree(int _leftRange, int _rightRange,
              const std::vector<valueType> &_initValue,
              const valueType &_valueZero, const tagType &_tagZero) {
    leftRange = _leftRange;
    rightRange = _rightRange;
    init(_initValue, _valueZero, _tagZero);
  }
  segmentTree(int size, const std::vector<valueType> &_initValue,
              const valueType &_valueZero, const tagType &_tagZero) {
    leftRange = 1;
    rightRange = size + 1;
    init(_initValue, _valueZero, _tagZero);
  }
  void modify(int l, int r, const tagType &tag) {
    modify(1, leftRange, rightRange, l, r, tag);
  }
  void modify(int p, const tagType &tag) { modify(p, p + 1, tag); }
  valueType query(int l, int r) {
    return query(1, leftRange, rightRange, l, r);
  }
  valueType query(int p) { return query(p, p + 1); }
};
template <class T,
          class Compare = less<typename std::iterator_traits<T>::value_type>>
void merge(T begin, T middle, T end,
           Compare cmp = less<typename std::iterator_traits<T>::value_type>()) {
  vector<typename std::iterator_traits<T>::value_type> Temp(end - begin);
  auto it_1 = begin;
  auto it_2 = middle;
  while (it_1 < middle && it_2 < end) {
    if (cmp(*it_1, *it_2)) {
      Temp[(it_1 - begin) + (it_2 - middle)] = *it_1;
      ++it_1;
    } else {
      Temp[(it_1 - begin) + (it_2 - middle)] = *it_2;
      ++it_2;
    }
  }
  while (it_1 < middle) {
    Temp[(it_1 - begin) + (it_2 - middle)] = *it_1;
    ++it_1;
  }
  while (it_2 < end) {
    Temp[(it_1 - begin) + (it_2 - middle)] = *it_2;
    ++it_2;
  }
  for (auto it = begin; it != end; ++it) {
    *it = Temp[it - begin];
  }
}
template <class T,
          class Compare = less<typename std::iterator_traits<T>::value_type>>
void merge_sort(
    T begin, T end,
    Compare cmp = less<typename std::iterator_traits<T>::value_type>()) {
  auto middle = begin + (end - begin) / 2;
  if (end - begin <= 1) {
    return;
  }
  merge_sort(begin, middle, cmp);
  merge_sort(middle, end, cmp);
  merge(begin, middle, end, cmp);
}
template <class T,
          class Compare = less<typename std::iterator_traits<T>::value_type>>
T Partition(
    T begin, T end,
    Compare cmp = less<typename std::iterator_traits<T>::value_type>()) {
  typename std::iterator_traits<T>::value_type x = *(begin + (end - begin) / 2);
  T left = begin;
  T right = end - 1;
  while (left < right) {
    while (cmp(*left, x)) {
      ++left;
    }
    while (cmp(x, *right)) {
      --right;
    }
    if (left >= right) {
      break;
    }
    swap(*left, *right);
    ++left;
    --right;
  }
  return left;
}
template <class T,
          class Compare = less<typename std::iterator_traits<T>::value_type>>
void qsort(T begin, T end,
           Compare cmp = less<typename std::iterator_traits<T>::value_type>()) {
  if (end - begin <= 1) {
    return;
  }
  T border = Partition(begin, end, cmp);
  qsort(begin, border, cmp);
  qsort(border, end, cmp);
}
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  cout.precision(15);
  long long tests;
  cin >> tests;
  while (tests--) {
    long long n;
    cin >> n;
    vector<long long> A(n + 1);
    for (int i = 0; i < n; ++i) {
      cin >> A[i + 1];
    }
    qsort(A.begin(), A.end());
    for (long long i = n; i >= 0; --i) {
      if (A[i] <= i) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
}
