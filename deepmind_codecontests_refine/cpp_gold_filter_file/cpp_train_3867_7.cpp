#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int INF = 9e18 + 2e17;
const int inf = 2e9;
const int N = 4e5 + 22;
const double eps = 1e-10;
const double PI = 3.14159265;
int prime[62], prime_inv[62];
int tree[4 * N], lazy_tree[4 * N];
int n, q, L, R, X, a[N];
string s;
long long int mask[4 * N], lazy_mask[4 * N];
bool check[305];
int _mul(int a, int b) { return (1LL * a * b) % mod; }
int _modp(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = _mul(res, a);
    a = _mul(a, a);
    b >>= 1;
  }
  return res;
}
void _prec() {
  for (int i = 2; i * i < 300; i++)
    if (!check[i])
      for (int j = i + i; j < 300; j += i)
        if (!check[j]) check[j] = 1;
  int k = 0;
  for (int i = (int)2; i < (int)300; i++)
    if (!check[i]) prime[k++] = i;
  for (int i = (int)0; i < (int)62; i++)
    prime_inv[i] = _modp(prime[i], mod - 2);
}
long long int _mask(long long int cur_mask, int x) {
  for (int i = (int)0; i < (int)62; i++)
    if (x % prime[i] == 0) cur_mask |= (1LL << i);
  return cur_mask;
}
void _build(int low, int high, int pos) {
  lazy_tree[pos] = 1;
  if (low == high) {
    tree[pos] = a[low];
    mask[pos] = _mask(0, a[low]);
    return;
  }
  int mid = (low + high) / 2;
  _build(low, mid, 2 * pos + 1);
  _build(mid + 1, high, 2 * pos + 2);
  tree[pos] = _mul(tree[2 * pos + 1], tree[2 * pos + 2]);
  mask[pos] = mask[2 * pos + 1] | mask[2 * pos + 2];
}
void _push(int low, int high, int pos) {
  if (lazy_tree[pos] != 1)
    tree[pos] = _mul(tree[pos], _modp(lazy_tree[pos], high - low + 1));
  mask[pos] |= lazy_mask[pos];
  if (low != high) {
    lazy_tree[2 * pos + 1] = _mul(lazy_tree[pos], lazy_tree[2 * pos + 1]);
    lazy_tree[2 * pos + 2] = _mul(lazy_tree[pos], lazy_tree[2 * pos + 2]);
    lazy_mask[2 * pos + 1] |= lazy_mask[pos];
    lazy_mask[2 * pos + 2] |= lazy_mask[pos];
  }
  lazy_tree[pos] = 1;
  lazy_mask[pos] = 0;
}
int _get_mul(int low, int high, int pos) {
  if (L > high || R < low) return 1;
  _push(low, high, pos);
  if (low >= L && high <= R) return tree[pos];
  int mid = (low + high) / 2;
  return _mul(_get_mul(low, mid, 2 * pos + 1),
              _get_mul(mid + 1, high, 2 * pos + 2));
}
void _multiply(int low, int high, int pos) {
  if (L > high || R < low) return;
  _push(low, high, pos);
  if (low >= L && high <= R) {
    lazy_tree[pos] = X;
    lazy_mask[pos] = _mask(0, X);
    return;
  }
  int mid = (low + high) / 2;
  _multiply(low, mid, 2 * pos + 1);
  _multiply(mid + 1, high, 2 * pos + 2);
  tree[pos] = _mul(tree[pos], _modp(X, min(R, high) - max(L, low) + 1));
  mask[pos] = mask[2 * pos + 1] | mask[2 * pos + 2] | lazy_mask[2 * pos + 1] |
              lazy_mask[2 * pos + 2];
}
pair<int, long long int> _totient(int low, int high, int pos) {
  if (L > high || R < low) return {1, 0};
  _push(low, high, pos);
  if (low >= L && high <= R) return {tree[pos], mask[pos]};
  int mid = (low + high) / 2;
  pair<int, long long int> p1, p2;
  p1 = _totient(low, mid, 2 * pos + 1);
  p2 = _totient(mid + 1, high, 2 * pos + 2);
  return {_mul(p1.first, p2.first), p1.second | p2.second};
}
void _solve() {
  _prec();
  cin >> n >> q;
  for (int i = (int)0; i < (int)n; i++) cin >> a[i];
  _build(0, n - 1, 0);
  while (q--) {
    cin >> s >> L >> R;
    L--;
    R--;
    if (s[0] == 'M') {
      cin >> X;
      _multiply(0, n - 1, 0);
    } else {
      pair<int, long long int> p = _totient(0, n - 1, 0);
      int ans = p.first;
      for (int i = (int)0; i < (int)62; i++)
        if ((1LL << i) & p.second)
          ans = _mul(ans, _mul(prime[i] - 1, prime_inv[i]));
      cout << ans << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _solve();
  return 0;
}
