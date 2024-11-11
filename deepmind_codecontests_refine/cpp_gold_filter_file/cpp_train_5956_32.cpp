#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T>;
const int mod = 998244353;
const int inf = 0x3fffffff;
const int N = 2 * 1e5 + 10;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long b) {
  long long ans = 1;
  a = (a % mod + mod) % mod;
  for (; b; b >>= 1) {
    if (b & 1) ans = (a * ans) % mod;
    a = (a * a) % mod;
  }
  return ans;
}
struct PairHash {
  template <typename T1, typename T2>
  std::size_t operator()(const pair<T1, T2>& p) const {
    return hash<T1>()(p.first) ^ hash<T2>()(p.second);
  }
};
long long sumC(int n, const vector<long long>& inv,
               const vector<long long>& c_half) {
  if (n % 2) {
    return qpow(2, n) * inv[2] % mod;
  }
  return (qpow(2, n) - c_half[n / 2] % mod + mod) % mod * inv[2] % mod;
}
void solve(int ncase) {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  if (k == 1) {
    cout << 0 << endl;
    return;
  }
  int diff = 0;
  for (int i = 0; i < n; i++) {
    diff += (h[i] != h[(i + 1) % n] ? 1 : 0);
  }
  if (diff == 0) {
    cout << 0 << endl;
    return;
  }
  long long same = 1;
  for (int i = 0; i < n - diff; i++) {
    same = same * k % mod;
  }
  vector<long long> inv(n + 10);
  inv[1] = 1;
  for (int i = 2; i <= n + 2; ++i)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  vector<long long> c_half(n / 2 + 1);
  c_half[0] = 1;
  for (int i = 0; i < n / 2; i++) {
    c_half[i + 1] = c_half[i] * (2 * i + 1) % mod * (2 * i + 2) % mod *
                    inv[i + 1] % mod * inv[i + 1] % mod;
  }
  if (k == 2) {
    cout << (same * 1LL * sumC(diff, inv, c_half)) % mod << endl;
    return;
  }
  vector<long long> pow_k(n + 1);
  pow_k[0] = 1;
  for (int i = 1; i <= n; i++) pow_k[i] = pow_k[i - 1] * (k - 2) % mod;
  long long ans = 0;
  long long c_diff_z = 1;
  for (int z = 0; z < diff; z++) {
    ans = (ans +
           (pow_k[z] * c_diff_z % mod * sumC(diff - z, inv, c_half) % mod)) %
          mod;
    c_diff_z = c_diff_z * (diff - z) % mod * inv[z + 1] % mod;
  }
  cout << ans * same % mod << endl;
}
void solve_all_cases() {
  int T = 1;
  int ncase = 0;
  while (T--) {
    solve(++ncase);
  }
}
int main() {
  cout << std::fixed;
  cout << setprecision(9);
  solve_all_cases();
}
