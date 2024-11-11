#include <bits/stdc++.h>
using namespace std;
int add(int a, int b) {
  int res = a + b;
  if (res >= 998244353) return res - 998244353;
  return res;
}
int mul(int a, int b) {
  long long res = a;
  res *= b;
  if (res >= 998244353) return res % 998244353;
  return res;
}
int sub(int a, int b) {
  int res = a - b;
  if (res < 0) return res + 998244353;
  return res;
}
int modpow(long long a, long long b) {
  a %= 998244353;
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int modinv(long long a) { return modpow(a, 998244353 - 2); }
int N = 0;
struct NTT {
  int root, root_1, root_pw = 1, c;
  NTT(int n, bool init = true) {
    while (root_pw < n) root_pw <<= 1, N++;
    if (init) {
      vector<int> pf;
      int n = 998244353 - 1, phi = n;
      for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
          pf.push_back(i);
          while (n % i == 0) n /= i;
        }
      }
      if (n > 1) pf.push_back(n);
      for (int r = 2; r <= phi; r++) {
        bool ok = true;
        for (auto& x : pf) {
          if (modpow(r, phi / x) == 1) {
            ok = false;
            break;
          }
        }
        if (ok) {
          c = (998244353 - 1) >> N;
          root = modpow(r, c), root_1 = modinv(root);
          break;
        }
      }
    }
  }
  void transform(vector<int>& a, bool invert) {
    int n = a.size();
    assert(n <= root_pw);
    for (int i = 1, j = 0; i < n; i++) {
      int bit = n >> 1;
      for (; j & bit; bit >>= 1) j ^= bit;
      j ^= bit;
      if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
      int wlen = invert ? root_1 : root;
      for (int i = len; i < root_pw; i <<= 1)
        wlen = (int)(1LL * wlen * wlen % 998244353);
      for (int i = 0; i < n; i += len) {
        int w = 1;
        for (int j = 0; j < len / 2; j++) {
          int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % 998244353);
          a[i + j] = u + v < 998244353 ? u + v : u + v - 998244353;
          a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + 998244353;
          w = (int)(1LL * w * wlen % 998244353);
        }
      }
    }
    if (invert) {
      int n_1 = modinv(n);
      for (int& x : a) x = (int)(1LL * x * n_1 % 998244353);
    }
  }
  vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<int> fa(a), fb(b);
    int n = 1, total = a.size() + b.size();
    while (n < total) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    transform(fa, false);
    transform(fb, false);
    for (int i = 0; i < n; i++) fa[i] = (fb[i] * 1LL * fa[i]) % 998244353;
    transform(fa, true);
    fa.resize(total - 1);
    while (!fa.empty() && fa.back() == 0) fa.pop_back();
    return fa;
  }
} ntt(int(8e5) + 100);
void solve() {
  int n, x, y, offset;
  cin >> n >> x >> y;
  offset = x;
  vector<int> a(offset + x + 1), b(offset + x + 1);
  for (int i = 0; i <= n; i++) {
    int z;
    cin >> z;
    a[offset + z]++;
    b[offset - z]++;
  };
  vector<int> c = ntt.multiply(a, b);
  vector<int> pos(x + 5 + y);
  for (int i = 2 * offset + 1; i <= 2 * offset + x; i++) {
    pos[i - 2 * offset + y] += c[i];
  }
  vector<int> ans(int(1e6 + 2e5) + 5, -1);
  for (int i = 1; i <= x + 5 + y; i++) {
    for (int j = i; j <= int(1e6); j += i) {
      if (pos[i]) {
        ans[j] = 2 * i;
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l;
    cin >> l;
    ;
    cout << ans[l / 2] << ' ';
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
}
