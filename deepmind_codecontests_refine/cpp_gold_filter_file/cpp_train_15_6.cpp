#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793;
const long long I_MAX = 1LL << 60;
long long mod = 1000000007;
const long long maxN = 2E5;
vector<long long> inv(maxN + 5, 1);
vector<long long> fac(maxN + 5, 1);
void ADD(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
}
void MUL(long long &x, long long y) {
  x *= y;
  x = (x % mod + mod) % mod;
}
long long mypow(long long b, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1) MUL(ans, b);
    MUL(b, b);
    e >>= 1;
  }
  return ans;
}
long long modinv(long long n) { return mypow(n, mod - 2); }
void calcInv(long long n) {
  for (int i = 2; i <= n; ++i) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }
}
void calcFac(long long n) {
  for (int i = 2; i <= n; ++i) {
    fac[i] = fac[i - 1] * i % mod;
  }
}
long long cm(long long a, long long b) {
  long long ans = 1;
  if (a < b) return 0;
  MUL(ans, inv[fac[a - b]]);
  MUL(ans, inv[fac[b]]);
  MUL(ans, fac[a]);
  return ans;
}
long long Lucas(long long n, long long m) {
  if (m == 0) return 1;
  return cm(n % mod, m % mod) * Lucas(n / mod, m / mod) % mod;
}
long long doLucas(long long n, long long m) {
  calcInv(mod);
  calcFac(mod);
  return Lucas(n, m);
}
const long long maxn = 2E5 + 5;
long long arr[maxn + 1];
int lowbit(int x) { return x & (-x); }
void change(int x, long long add, int size) {
  for (int i = x; i <= size; i += lowbit(i)) {
    arr[i] += add;
  }
}
long long query(int x, int size) {
  long long ret = 0;
  for (int i = x; i > 0; i -= lowbit(i)) {
    ret += arr[i];
  }
  return ret;
}
void solve() {
  long long n;
  cin >> n;
  bool used[n + 1];
  for (int i = 0; i <= n; ++i) used[i] = false;
  vector<long long> num(n), res(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> num[i];
  }
  for (int i = 1; i <= n; ++i) {
    change(i, i - 1, n);
  }
  for (int i = n - 1; i >= 1; --i) {
    int lo = 1, hi = n, mi;
    while (lo < hi) {
      mi = (lo + hi) >> 1;
      long long tmp = query(mi, n);
      if (tmp < num[i]) {
        lo = mi + 1;
      } else if (tmp == num[i] and used[mi]) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    change(lo + 1, -lo, n);
    used[lo] = true;
    res[i] = lo;
  }
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      res[0] = i;
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}
int main() {
  int t = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
