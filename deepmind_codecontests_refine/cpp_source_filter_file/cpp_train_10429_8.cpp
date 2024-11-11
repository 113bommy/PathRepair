#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const unsigned long long infull = numeric_limits<unsigned long long>::max();
void fix(int &x, long long MOD) {
  x = (x % MOD);
  if (x < 0) x += MOD;
  return;
}
long long lgput(long long a, long long b, long long MOD) {
  long long ret = 1;
  a %= MOD;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
long long inv(long long a, long long MOD) { return lgput(a, MOD - 2, MOD); }
struct f {
  int a, b;
  f(int _a = 0, int _b = 0) : a(_a), b(_b) {}
  long long eval(int x) { return 1ll * x * a + b; }
};
int binarySearch(int x, vector<int> &v) {
  int pos = 0;
  int l = 1, r = (int)((v).size());
  while (l <= r) {
    int m = l + r >> 1;
    if (v[m] <= x) {
      pos = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return pos;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(12);
  srand(time(NULL));
  int n, k;
  cin >> n >> k;
  if (n == 1) return puts("3"), 0;
  vector<int> phi(n + 1);
  iota((phi).begin(), (phi).end(), 0);
  for (int i = 2; i <= n; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) {
        phi[j] = (phi[j] / i) * (i - 1);
      }
    }
  }
  k += 2;
  sort((phi).begin(), (phi).end());
  cout << accumulate(phi.begin() + 1, phi.begin() + k + 1, 0ll) << '\n';
}
