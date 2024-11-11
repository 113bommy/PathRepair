#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <class T>
bool set_max(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool set_min(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename... Args>
void readln(Args &...args) {
  ((cin >> args), ...);
}
template <typename... Args>
void writeln(Args... args) {
  ((cout << args << " "), ...);
}
template <typename T, typename... Args>
void push_to_vec(vector<T> &v, Args &&...args) {
  (v.push_back(forward<Args>(args)), ...);
}
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename T>
string to_string(T v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
vector<int> primes;
vector<int> inverse_primes;
ll fast_power(ll a, ll p) {
  ll ans = 1;
  while (p) {
    if (p % 2) {
      ans = ans * a % MOD;
    }
    a = a * a % MOD;
    p /= 2;
  }
  return ans;
}
ull get_mask(ull value) {
  ull mask = 0;
  for (std::size_t i = 0; i < primes.size(); i++) {
    if (value % primes[i] == 0) {
      mask |= 1ull << i;
    }
  }
  return mask;
}
struct Lazy_Context {
  Lazy_Context() : value(1), mask(0) {}
  Lazy_Context(ull value, ull mask) : value(value), mask(mask) {}
  void operator+=(const Lazy_Context &lc) {
    value = value * lc.value % MOD;
    mask |= lc.mask;
  }
  ull value;
  ull mask;
};
struct Node {
  Node() {
    value = 1;
    mask = 0;
    size = 0;
  }
  Node(int v) {
    value = static_cast<ull>(v);
    mask = get_mask(v);
    size = 1;
  }
  Node(const Node &l, const Node &r) {
    value = l.value * r.value % MOD;
    mask = l.mask | r.mask;
    size = l.size + r.size;
  }
  void apply(Lazy_Context lz) {
    value = value * fast_power(lz.value, size) % MOD;
    mask |= lz.mask;
  }
  ull get_ans() {
    ll ans = value;
    for (std::size_t j = 0; j < primes.size(); j++) {
      if ((mask >> j) & 1u) {
        ans = ans * inverse_primes[j] % MOD;
      }
    }
    return ans;
  }

 private:
  ull value;
  ull mask;
  std::size_t size;
};
template <class Node, class Value, class lazy_count = int>
class SegmentTree {
 public:
  explicit SegmentTree(vector<Value> &base) {
    n = base.size();
    height = 0;
    while ((1u << static_cast<std::size_t>(height)) < n) {
      height++;
    }
    tree.resize(n * 2);
    is_dirty.assign(n, false);
    lazy.resize(n);
    for (int i = 0; i < n; i++) {
      tree[i + n] = Node(base[i]);
    }
    for (int i = n - 1; i > 0; i--) {
      tree[i] = Node(tree[i * 2], tree[i * 2 + 1]);
      lazy[i] = lazy_count();
    }
  }
  Node query(int l, int r) {
    if (l >= r) {
      return Node();
    }
    l += n, r += n;
    push(l), push(r - 1);
    Node lp, rp;
    while (l < r) {
      if (l % 2) {
        lp = Node(lp, tree[l]);
        l++;
      }
      if (r % 2) {
        r--;
        rp = Node(tree[r], rp);
      }
      l /= 2, r /= 2;
    }
    return Node(lp, rp);
  }
  void update(int l, int r, Lazy_Context lc) {
    if (l >= r) {
      return;
    }
    l += n, r += n;
    push(l), push(r - 1);
    int l0 = l, r0 = r;
    while (l < r) {
      if (l % 2) {
        apply(l, lc);
        l++;
      }
      if (r % 2) {
        r--;
        apply(r, lc);
      }
      l /= 2, r /= 2;
    }
    build(l0), build(r0 - 1);
  }

 private:
  int n, height;
  vector<bool> is_dirty;
  vector<Node> tree;
  vector<lazy_count> lazy;
  void apply(int x, const Lazy_Context &lc) {
    tree[x].apply(lc);
    if (x < n) {
      is_dirty[x] = true;
      lazy[x] += lc;
    }
  }
  void push(int x) {
    for (std::size_t h = height; h > 0; h--) {
      int i = static_cast<uint32_t>(x) >> h;
      if (is_dirty[i]) {
        apply(i * 2, lazy[i]);
        apply(i * 2 + 1, lazy[i]);
        lazy[i] = Lazy_Context();
        is_dirty[i] = false;
      }
    }
  }
  void build(int x) {
    for (x /= 2; x > 0; x /= 2) {
      tree[x] = Node(tree[x * 2], tree[x * 2 + 1]);
      if (is_dirty[x]) {
        tree[x].apply(lazy[x]);
      }
    }
  }
};
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  vector<bool> is_prime(350, true);
  for (int i = 2; i <= 300; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
    for (int j : primes) {
      int k = j * i;
      if (k < 350) {
        is_prime[k] = false;
      }
    }
  }
  for (int j : primes) {
    inverse_primes.push_back(fast_power(j, MOD - 2) * (j - 1) % MOD);
  }
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  SegmentTree<Node, int, Lazy_Context> tree(a);
  while (q--) {
    string str;
    cin >> str;
    if (str[0] == 'T') {
      int l, r;
      cin >> l >> r;
      cout << tree.query(l - 1, r).get_ans() << endl;
    } else {
      int l, r, v;
      cin >> l >> r >> v;
      tree.update(l - 1, r, Lazy_Context(v, get_mask(v)));
    }
  }
  return 0;
}
