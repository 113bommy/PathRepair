#include <bits/stdc++.h>
using namespace std;
const int maxn = 8e4 + 10;
const long long mod = 998244353, modg = 3, modi = 332748118;
int a[maxn], b[maxn];
int pow_mod(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (long long)ans * a % mod;
    a = (long long)a * a % mod, b >>= 1;
  }
  return ans;
}
int add(int a, int b) {
  a += b;
  if (a > mod) return a - mod;
  return a;
}
int sub(int a, int b) {
  a -= b;
  if (a < 0) return a + mod;
  return a;
}
class nubmer {
 public:
  int rev[maxn], len, pw;
  long long wt[2][maxn];
  void init_0() {
    int len = 1;
    while (len <= maxn / 2) len <<= 1;
    for (int mid = 1; mid < len; mid <<= 1) {
      long long wn1 = pow_mod(modg, (mod - 1) / (mid << 1));
      long long wn2 = pow_mod(modi, (mod - 1) / (mid << 1));
      wt[0][mid] = wt[1][mid] = 1;
      long long wt1 = wn1, wt2 = wn2;
      for (int j = 1; j <= mid; ++j) {
        wt[0][mid + j] = wt1;
        wt1 = wt1 * wn1 % mod;
        wt[1][mid + j] = wt2;
        wt2 = wt2 * wn2 % mod;
      }
    }
  }
  void init(int n) {
    len = 1;
    pw = 0;
    while (len <= n) len <<= 1, pw++;
    for (int i = 0; i <= len - 1; ++i)
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (pw - 1));
  }
  void transform(int *a, int flag) {
    int f = flag == 1 ? 0 : 1;
    for (int i = 0; i <= len - 1; ++i)
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int mid = 1; mid < len; mid <<= 1) {
      for (int r = mid << 1, j = 0; j < len; j += r) {
        long long *p = wt[f] + mid;
        int *p1 = a + j, *p2 = a + j + mid;
        for (int k = 0; k < mid; ++k, ++p, ++p1, ++p2) {
          int x = *p1, y = (*p) * (*p2) % mod;
          *p1 = add(x, y), *p2 = sub(x, y);
        }
      }
    }
    if (flag == -1) {
      long long inv = pow_mod(len, mod - 2);
      for (int i = 0; i <= len; i++) {
        a[i] = a[i] * inv % mod;
        if (a[i] < 0) a[i] += mod;
      }
    }
  }
} ntt;
int n, k;
int s1[maxn], s2[maxn];
vector<int> solve(int l, int r) {
  if (l == r) {
    return vector<int>{1, s2[l]};
  }
  int mid = (l + r) >> 1;
  vector<int> x = solve(l, mid), y = solve(mid + 1, r);
  ntt.init(x.size() + y.size());
  for (int i = 0; i <= ntt.len + 5; i++) a[i] = 0, b[i] = 0;
  for (int i = 0; i < x.size(); i++) a[i] = x[i];
  for (int i = 0; i < y.size(); i++) b[i] = y[i];
  ntt.transform(a, 1);
  ntt.transform(b, 1);
  for (int i = 0; i < ntt.len; i++) a[i] = (long long)a[i] * b[i] % mod;
  ntt.transform(a, -1);
  int len = x.size() + y.size();
  int mi = min(ntt.len, min(k + 1, len));
  vector<int> ans(mi);
  for (int i = 0; i < mi; i++) {
    ans[i] = a[i];
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ntt.init_0();
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s1[i];
  }
  int T;
  cin >> T;
  vector<int> tmp;
  while (T--) {
    int flag;
    cin >> flag;
    if (flag == 1) {
      int q, i, d;
      cin >> q >> i >> d;
      for (int j = 1; j <= n; j++) s2[j] = sub(q, s1[j]);
      s2[i] = sub(q, d);
      tmp = solve(1, n);
      cout << tmp[k] << "\n";
    } else {
      int q, l, r, d;
      cin >> q >> l >> r >> d;
      for (int j = 1; j <= n; j++) {
        if (j >= l && j <= r)
          s2[j] = sub(sub(q, s1[j]), d);
        else
          s2[j] = sub(q, s1[j]);
      }
      tmp = solve(1, n);
      cout << tmp[k] << "\n";
    }
  }
  return 0;
}
