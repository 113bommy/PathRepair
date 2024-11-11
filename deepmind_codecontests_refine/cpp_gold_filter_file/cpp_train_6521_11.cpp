#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T biton(T n, T pos) {
  return n | ((T)1 << pos);
}
template <class T>
inline T bitoff(T n, T pos) {
  return n & ~((T)1 << pos);
}
template <class T>
inline T ison(T n, T pos) {
  return (bool)(n & ((T)1 << pos));
}
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
inline int nxt() {
  int aaa;
  scanf("%d", &aaa);
  return aaa;
}
inline long long lxt() {
  long long aaa;
  scanf("%lld", &aaa);
  return aaa;
}
inline double dxt() {
  double aaa;
  scanf("%lf", &aaa);
  return aaa;
}
template <class T>
inline void vinput(T n, vector<T>& v) {
  for (T in, i = 0; i < n; i++) {
    cin >> in;
    v.push_back(in);
  }
}
template <class T>
inline void vout(vector<T> v) {
  for (auto it : v) cout << it << " ";
  cout << endl;
}
const long long M = 1e9 + 7;
int cs = 0;
vector<int> v;
vector<int> primes;
void sieve(int n) {
  vector<bool> check(n + 1, false);
  primes.push_back(2);
  for (int i = 3; i * i <= n; i += 2) {
    for (int j = i * i; j <= n; j += i * 2) {
      check[j] = true;
    }
  }
  for (int i = 3; i <= n; i += 2) {
    if (!check[i]) primes.push_back(i);
  }
}
int NOD(int n) {
  int sqrtn = sqrt(n);
  int res = 1;
  for (int i = 0; i < primes.size() && primes[i] <= sqrtn; i++) {
    if (n % primes[i] == 0) {
      int cnt = 0;
      while (n % primes[i] == 0) {
        n /= primes[i];
        cnt++;
      }
      sqrtn = sqrt(n);
      cnt++;
      res *= cnt;
    }
  }
  if (n != 1) {
    res *= 2;
  }
  return res;
}
vector<long long> nod(1e6 + 5, 0);
void genDiv() {
  for (int i = 1; i <= 1e6; i++) {
    nod[i] = NOD(i);
  }
}
struct data {
  long long val;
  int mx;
  data(long long _val, int _mx) {
    val = _val;
    mx = _mx;
  }
  data() { val = 0, mx = 0; }
};
data tree[4 * 300010];
void buildTree(long long node, long long s, long long e) {
  if (s == e) {
    tree[node].val = v[s - 1];
    tree[node].mx = v[s - 1];
    return;
  }
  long long mid = (s + e) / 2;
  long long left = 2 * node;
  long long right = left + 1;
  buildTree(left, s, mid);
  buildTree(right, mid + 1, e);
  tree[node].val = tree[left].val + tree[right].val;
  tree[node].mx = max(tree[left].mx, tree[right].mx);
}
void update(long long node, long long s, long long e, long long l,
            long long r) {
  if (s > e) return;
  if (s > r || e < l) return;
  if (tree[node].mx <= 2) return;
  if (s == e) {
    tree[node].mx = nod[tree[node].val];
    tree[node].val = nod[tree[node].val];
    return;
  }
  long long mid = (s + e) / 2;
  long long left = 2 * node;
  long long right = left + 1;
  update(left, s, mid, l, r);
  update(right, mid + 1, e, l, r);
  tree[node].val = tree[left].val + tree[right].val;
  tree[node].mx = max(tree[left].mx, tree[right].mx);
}
long long query(long long node, long long s, long long e, long long i,
                long long j) {
  if (j < s || i > e) {
    return 0;
  }
  if (i <= s && j >= e) {
    return tree[node].val;
  }
  long long mid = (s + e) / 2;
  long long left = 2 * node;
  long long right = left + 1;
  long long x = query(left, s, mid, i, j);
  long long y = query(right, mid + 1, e, i, j);
  return x + y;
}
void solve() {
  int n, q;
  cin >> n >> q;
  vinput(n, v);
  buildTree(1, 1, n);
  while (q--) {
    int choice, l, r;
    cin >> choice >> l >> r;
    if (choice == 1) {
      update(1, 1, n, l, r);
    } else {
      cout << query(1, 1, n, l, r) << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(2);
  int tc = 1;
  sieve(1000005);
  genDiv();
  while (tc--) solve();
  return 0;
}
