#include <bits/stdc++.h>
using namespace std;
template <class T>
class SegmentTree {
 public:
  SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
  SegmentTree(T ar[], long long n, T value, T (*combine)(T obj1, T obj2));
  T query(long long l, long long r);
  void update(long long idx, T val);

 private:
  T *tree;
  void buildTree(std::vector<T> data);
  long long segTreeSize;
  T valueForExtraNodes;
  T (*combine)(T obj1, T obj2);
  long long calculateSize(long long n);
  T queryHelper(long long l, long long r, long long st, long long ed,
                long long node);
};
template <class T>
SegmentTree<T>::SegmentTree(std::vector<T> data, T value,
                            T (*combine)(T obj1, T obj2)) {
  this->combine = combine;
  valueForExtraNodes = value;
  segTreeSize = calculateSize(data.size());
  buildTree(data);
}
template <class T>
SegmentTree<T>::SegmentTree(T ar[], long long n, T value,
                            T (*combine)(T obj1, T obj2)) {
  this->combine = combine;
  valueForExtraNodes = value;
  segTreeSize = calculateSize(n);
  std::vector<T> data;
  for (long long i = 0; i < n; i++) data.push_back(ar[i]);
  buildTree(data);
}
template <class T>
long long SegmentTree<T>::calculateSize(long long n) {
  long long pow2 = 1;
  while (pow2 < n) {
    pow2 = pow2 << 1;
  }
  return 2 * pow2 - 1;
}
template <class T>
T SegmentTree<T>::query(long long l, long long r) {
  long long st = 0, ed = segTreeSize / 2;
  return queryHelper(l, r, st, ed, 0);
}
template <class T>
T SegmentTree<T>::queryHelper(long long l, long long r, long long st,
                              long long ed, long long node) {
  if ((r < st) || (l > ed) || (l > r)) return valueForExtraNodes;
  if (st >= l && ed <= r) return tree[node];
  T leftVal = queryHelper(l, r, st, (st + ed) / 2, (2 * node + 1));
  T rightVal = queryHelper(l, r, (st + ed) / 2 + 1, ed, (2 * node + 2));
  return combine(leftVal, rightVal);
}
template <class T>
void SegmentTree<T>::buildTree(std::vector<T> data) {
  long long n = data.size();
  tree = new T[segTreeSize];
  long long extraNodes = (segTreeSize / 2 + 1) - n;
  for (long long i = segTreeSize - 1; i >= 0; i--) {
    if (extraNodes > 0) {
      tree[i] = valueForExtraNodes;
      extraNodes--;
    } else if (n > 0) {
      tree[i] = data[n - 1];
      n--;
    } else
      tree[i] = combine(tree[(2 * i + 1)], tree[(2 * i + 2)]);
  }
}
template <class T>
void SegmentTree<T>::update(long long idx, T val) {
  long long segTreeIdx = (segTreeSize / 2) + idx;
  tree[segTreeIdx] = val;
  while (((segTreeIdx - 1) / 2) >= 0) {
    segTreeIdx = ((segTreeIdx - 1) / 2);
    if ((2 * segTreeIdx + 2) < segTreeSize)
      tree[segTreeIdx] =
          combine(tree[(2 * segTreeIdx + 1)], tree[(2 * segTreeIdx + 2)]);
    if (segTreeIdx == 0) break;
  }
}
struct node {
  long long ans;
  long long tot;
  long long pref;
  long long suf;
  node() {}
  node(long long val) { tot = ans = pref = suf = val; }
};
node combine(node x, node y) {
  node *ptr = new node();
  ptr->ans = max(x.ans, y.ans);
  ptr->ans = max(ptr->ans, y.pref + x.suf);
  ptr->pref = max(x.tot + y.pref, x.pref);
  ptr->suf = max(y.tot + x.suf, y.suf);
  ptr->tot = x.tot + y.tot;
  return *ptr;
}
long long andd(long long x, long long y) { return (x & y); }
struct cmp {
  bool operator()(long long a, long long b) { return (a > b); }
};
long long ceil(const long long &a, const long long &b) {
  if (a % b == 0) return a / b;
  return a / b + 1;
}
long long mod = 1000000007;
const long long N = 100005;
vector<long long> a(N);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, pair<long long, long long>>> v;
  for (long long i = 0; i < m; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    v.push_back({z, {x, y}});
  }
  for (long long i = 30 - 1; i >= 0; i--) {
    long long z = (1 << i);
    long long p[n + 5];
    memset(p, 0, sizeof(p));
    for (long long i = 0; i < m; i++) {
      long long x = v[i].first;
      long long l = v[i].second.first;
      long long r = v[i].second.second;
      if ((x & z)) {
        p[l - 1]++;
        p[r]--;
      }
    }
    for (long long i = 1; i <= n; i++) {
      p[i] += p[i - 1];
    }
    for (long long i = 0; i < n; i++) {
      if (p[i]) {
        a[i] += z;
      }
    }
  }
  SegmentTree<long long> range(a, 2147483647, andd);
  long long f = 1;
  for (long long i = 0; i < m; i++) {
    long long x = v[i].first;
    long long l = v[i].second.first;
    long long r = v[i].second.second;
    node as = range.query(l - 1, r - 1);
    if (as.ans != x) {
      f = 0;
      break;
    }
  }
  if (f) {
    cout << "YES\n";
    for (long long i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
  } else {
    cout << "NO\n";
  }
  return 0;
}
