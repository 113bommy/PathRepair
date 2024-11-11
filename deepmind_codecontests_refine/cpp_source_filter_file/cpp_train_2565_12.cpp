#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const int MOD = 998244353;
int add(int a, int b) { return (a += b) >= MOD ? a - MOD : a; }
int sub(int a, int b) { return (a -= b) < 0 ? a + MOD : a; }
int mul(int a, int b) { return (long long)a * b % MOD; }
int power(int a, long long n) {
  int res = 1;
  while (n) {
    if (n & 1LL) res = mul(res, a);
    a = mul(a, a);
    n >>= 1LL;
  }
  return res;
}
int inv(int a) { return power(a, MOD - 2); }
struct NTT {
  int base = 1;
  int maxBase = 0;
  int root;
  vector<int> w = {0, 1};
  vector<int> rev = {0, 1};
  NTT() {
    for (int u = MOD - 1; u % 2 == 0; maxBase++, u >>= 1)
      ;
    root = 2;
    while (power(root, 1 << maxBase) != 1 ||
           power(root, 1 << (maxBase - 1)) == 1) {
      root++;
    }
  }
  void ensure(int curBase) {
    assert(curBase <= maxBase);
    if (curBase <= base) {
      return;
    }
    rev.resize(1 << curBase);
    for (int i = 0; i < (1 << curBase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (curBase - 1));
    }
    w.resize(1 << curBase);
    while (base < curBase) {
      int wc = power(root, 1 << (maxBase - base - 1));
      for (int i = (1 << (base - 1)); i < (1 << base); i++) {
        w[i << 1] = w[i];
        w[i << 1 | 1] = mul(w[i], wc);
      }
      base++;
    }
  }
  void fft(vector<int> &a) {
    int curBase = 0;
    while ((1 << curBase) < a.size()) {
      curBase++;
    }
    int shift = base - curBase;
    for (int i = 0; i < a.size(); i++) {
      if (i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for (int k = 1; k < a.size(); k <<= 1) {
      for (int i = 0; i < k; i++) {
        for (int j = i; j < a.size(); j += k * 2) {
          int foo = a[j];
          int bar = mul(a[j + k], w[i + k]);
          a[j] = add(foo, bar);
          a[j + k] = sub(foo, bar);
        }
      }
    }
  }
  vector<int> mult(vector<int> a, vector<int> b) {
    int sz = a.size() + b.size() - 1;
    int curBase = 0;
    while ((1 << curBase) < sz) {
      curBase++;
    }
    ensure(curBase);
    a.resize(1 << curBase, 0);
    b.resize(1 << curBase, 0);
    fft(a);
    fft(b);
    for (int i = 0; i < (1 << curBase); i++) {
      a[i] = mul(mul(a[i], b[i]), inv(1 << curBase));
    }
    reverse(a.begin() + 1, a.end());
    fft(a);
    a.resize(sz);
    return a;
  }
} ntt;
int n;
long long m;
int fact[N], infact[N], invfra[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  vector<int> a(n + 1);
  vector<int> b(n + 1);
  m %= (MOD - 1);
  for (int i = 0; i <= n; ++i) {
    cin >> a[i];
  }
  fact[0] = infact[0] = 1;
  invfra[0] = invfra[1] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = mul(fact[i - 1], i);
    invfra[i] = inv(i);
    infact[i] = inv(fact[i]);
  }
  for (int i = 0; i <= n; ++i) b[i] = infact[i];
  for (int i = 0; i <= n; ++i) {
    a[i] = mul(a[i], fact[i]);
  }
  reverse(a.begin(), a.end());
  vector<int> c = ntt.mult(a, b);
  c.resize(n + 1);
  reverse(c.begin(), c.end());
  for (int i = 0; i <= n; ++i) {
    c[i] = mul(c[i], power(invfra[i + 1], m));
    if (i & 1) {
      c[i] = sub(MOD, c[i]);
    }
  }
  reverse(c.begin(), c.end());
  vector<int> ans = ntt.mult(c, b);
  ans.resize(n + 1);
  reverse(ans.begin(), ans.end());
  for (int i = 0; i <= n; ++i) {
    ans[i] = mul(ans[i], infact[i]);
    if (i & 1) {
      ans[i] = sub(MOD, ans[i]);
    }
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}
