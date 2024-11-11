#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int maxn = 0;
vector<long long> mprime;
vector<long long> arr, brr;
class BitDicTree {
 private:
  vector<int> vp;
  vector<vector<int>> cp;

 public:
  BitDicTree() {
    cp.push_back(vector<int>(2, -1));
    vp.push_back(0);
  }
  void add(int x) {
    int pos = 0;
    for (int i = 31; i >= 0; i--) {
      int c = (x >> i) & 1;
      if (cp[pos][c] == -1) {
        cp.push_back(vector<int>(2, -1));
        vp.push_back(0);
        cp[pos][c] = vp.size() - 1;
      }
      vp[cp[pos][c]] += 1;
      pos = cp[pos][c];
    }
  }
  void remove(int x) {
    int pos = 0;
    for (int i = 31; i >= 0; i--) {
      int c = (x >> i) & 1;
      vp[cp[pos][c]] -= 1;
      pos = cp[pos][c];
    }
  }
  int query(int x) {
    int pos = 0;
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
      int c = ((x >> i) & 1);
      if (cp[pos][1 - c] != -1 && vp[cp[pos][1 - c]] > 0) {
        ans += (1 << i);
        pos = cp[pos][1 - c];
      } else
        pos = cp[pos][c];
    }
    return ans;
  }
};
class UF {
 public:
  vector<long long> tree;
  int nodes;
  UF(int n) {
    nodes = n;
    tree = vector<long long>(n);
    iota(begin(tree), end(tree), 0);
  }
  int find(int st) {
    if (tree[st] != st) tree[st] = find(tree[st]);
    return tree[st];
  }
  bool connect(int a, int b) {
    int ua = find(a);
    int ub = find(b);
    if (ua != ub) {
      tree[ua] = ub;
      nodes -= 1;
    }
    return ua != ub;
  }
  int query() { return nodes; }
};
class Math {
 public:
  vector<long long> fac, inv;
  int MOD;
  Math(int n, int mod) {
    MOD = mod;
    fac = vector<long long>(n);
    inv = vector<long long>(n);
    fac[0] = 1;
    for (int i = 1; i < n; i++) {
      fac[i] = fac[i - 1] * i % MOD;
    }
    inv[n - 1] = QPow(fac[n - 1], MOD - 2);
    for (int i = n - 2; i >= 0; i--) {
      inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
  }
  long long comb(int n, int m) {
    return ((fac[n] * inv[m]) % MOD * inv[n - m]) % MOD;
  }
  long long arrang(int n, int m) { return fac[n] * inv[n - m] % MOD; }
  long long QPow(long long x, long long n) {
    long long ret = 1;
    long long tmp = x % MOD;
    while (n) {
      if (n & 1) {
        ret = (ret * tmp) % MOD;
      }
      tmp = tmp * tmp % MOD;
      n >>= 1;
    }
    return ret;
  }
};
unsigned euler(unsigned x) {
  unsigned i, res = x;
  for (i = 2; i < (int)sqrt(x * 1.0) + 1; i++) {
    if (!(x % i)) {
      res = res / i * (i - 1);
      while (!(x % i)) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    res = res / x * (x - 1);
  }
  return res;
}
void mprime_init() {
  mprime = vector<long long>(maxn, -1);
  for (int i = 2; i < maxn; i++) {
    if (mprime[i] == -1) {
      mprime[i] = i;
      for (int j = 2 * i; j < maxn; j += i) {
        if (mprime[j] == -1) mprime[j] = i;
      }
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  UF uf(n + 1);
  vector<pair<int, int>> es;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    es.push_back({a, b});
    uf.connect(a, b);
  }
  vector<int> cnt(n + 1, 0);
  vector<int> ec(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cnt[uf.find(i)] += 1;
  }
  for (int i = 0; i < m; i++) {
    ec[uf.find(es[i].first)] += 1;
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (cnt[i] == ec[i] + 1 && ec[i]) {
      ans += 1;
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  solve();
  return 0;
}
