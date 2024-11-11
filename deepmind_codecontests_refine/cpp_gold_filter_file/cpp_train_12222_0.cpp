#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1e9 + 5;
const double eps = 1e-7;
const double PI = acos(-1.0);
inline void debug_vi(vector<int> a) {
  for (long long i = (long long)(0); i < (long long)(a.size()); i++)
    cout << a[i] << " ";
}
inline void debug_vll(vector<long long> a) {
  for (long long i = (long long)(0); i < (long long)(a.size()); i++)
    cout << a[i] << " ";
}
inline void print_case(int tn) { cout << "Case #" << tn << ": "; }
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxpq = priority_queue<T>;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long a, long long m) { return power(a, m - 2, m); }
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t clk = clock();
  string a;
  cin >> a;
  int k;
  cin >> k;
  int sz = a.size();
  long long res = 0;
  for (long long i = (long long)(sz - 1); i >= (long long)(0); i--) {
    if (a[i] == '5' || a[i] == '0') {
      long long curr = power(2, i, MOD);
      curr *= (power(2, 1LL * sz * k, MOD) - 1 + MOD) % MOD;
      curr %= MOD;
      curr *= modInverse((power(2, sz, MOD) - 1 + MOD) % MOD, MOD);
      curr %= MOD;
      res += curr;
      res %= MOD;
    }
  }
  cout << res;
  cerr << "\n"
       << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC
       << "\n";
  return 0;
}
