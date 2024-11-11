#include <bits/stdc++.h>
using namespace std;
bool sortBySecond(const pair<long long, long long> &a,
                  const pair<long long, long long> b) {
  return a.second > b.second;
}
int ncr[1001][1001];
bool vis_ncr[1001][1001];
long long NCR(int n, int r) {
  if (n < r) return 0;
  if (vis_ncr[n][r]) return ncr[n][r];
  if (r == 0) return 1;
  if (r == 1) return n;
  if (n == 0) return 0;
  ncr[n][r] = NCR(n - 1, r) + NCR(n - 1, r - 1);
  vis_ncr[n][r] = true;
  return ncr[n][r];
}
struct segmentTree {
  int N;
  vector<long long> tree;
  void init(int n) {
    N = n;
    tree.resize(4 * n + 1, 0);
  }
  void assemble(vector<long long> &v, int l, int r, int node) {
    if (l > r) return;
    if (l == r) {
      tree[node] = v[l];
      return;
    }
    int mid = (l + r) / 2;
    assemble(v, l, mid, 2 * node + 1);
    assemble(v, mid + 1, r, 2 * node + 2);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
  }
  void update(int idx, int node, int l, int r, long long val) {
    if (l > r) return;
    if (l == r) {
      tree[node] = val;
      return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
      update(idx, 2 * node + 1, l, mid, val);
    else
      update(idx, 2 * node + 2, mid + 1, r, val);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
  }
  long long rangeQuery(int node, int l, int r, int ql, int qr) {
    if (l > r || l > qr || r < ql || ql > qr) return 0;
    if (l >= ql && r <= qr) return tree[node];
    int mid = (l + r) / 2;
    return rangeQuery(2 * node + 1, l, mid, ql, qr) +
           rangeQuery(2 * node + 2, mid + 1, r, ql, qr);
  }
  void changeTree(int idx, long long val) {
    idx--;
    update(idx, 0, 0, N - 1, val);
  }
  long long getSum(int l, int r) {
    l--, r--;
    return rangeQuery(0, 0, N - 1, l, r);
  }
};
template <typename K, typename V>
void printMapMultipleValue(map<K, V> const &mp, string name) {
  cout << name << ":\n";
  for (auto const &pa : mp) {
    cout << pa.first << " : ";
    cout << "{";
    for (auto const &x : pa.second) cout << x << ',';
    cout << "}\n";
  }
}
template <typename K, typename V>
void printMap(map<K, V> const &mp, string name) {
  cout << name << ":" << endl;
  for (auto const &pa : mp)
    cout << "{" << pa.first << " : " << pa.second << "}" << endl;
}
bool isPrime[100006];
void _seive() {
  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;
  isPrime[0] = false;
  for (int i = 2; i * i <= 100005; i++) {
    for (int j = i * i; j <= 100005; j += i) {
      isPrime[j] = false;
    }
  }
}
long long expo(int a, int b) {
  if (b == 0)
    return 1;
  else if (b == 1)
    return a;
  else if (b % 2 == 0) {
    long long ret = expo(a, b / 2);
    ret = (ret % 1000000007 * ret % 1000000007) % 1000000007;
    return ret;
  } else {
    long long ret = expo(a, b / 2);
    ret = (ret % 1000000007 * ret % 1000000007) % 1000000007;
    ret = (ret % 1000000007 * a % 1000000007) % 1000000007;
    return ret;
  }
}
long long inverseMod(long long a, long long m) { return expo(a, m - 2) % m; }
long long fact[100005];
void factorial() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i < 100005; i++)
    fact[i] = (fact[i - 1] % 1000000007 * i % 1000000007) % 1000000007;
}
long long GCD(long long a, long long b) {
  if (a == 0) return b;
  return GCD(b % a, a);
}
long long mult(long long a, long long b) {
  return (a % 1000000007 * b % 1000000007) % 1000000007;
}
long long add(long long a, long long b) {
  a += b;
  if (a >= 1000000007) return a - 1000000007;
  return a;
}
long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) return a + 1000000007;
  return a;
}
void _run(int test) {
  string s, t;
  cin >> s >> t;
  reverse(s.begin(), s.end());
  if (t == s)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int test = 1;
  for (int i = 1; i <= test; i++) _run(i);
  return 0;
}
