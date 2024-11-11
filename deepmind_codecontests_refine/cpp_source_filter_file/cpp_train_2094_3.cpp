#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000002;
const int MOD2 = 998244353;
const int MOD = 1000000007;
const int INF = 1e8;
const long double EPS = 1e-7;
long long int mul(long long int x, long long int y) {
  return (x * 1ll * y) % MOD;
}
long long int fastpow(long long int x, long long int y) {
  long long int z = 1;
  while (y) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}
long long int modinv(long long int n, long long int p) {
  return fastpow(n, p - 2);
}
struct Comp {
  bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.first != b.first) {
      return a.first < b.first;
    }
    return a.second > b.second;
  }
};
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  {
    long long int n, m, k;
    cin >> n >> m >> k;
    if ((2 * n * m) % k == 0) {
      long long int u = k;
      cout << "YES\n";
      multiset<long long int> m2;
      long long int flag = 0;
      if (k % 2 == 0) {
        k /= 2;
        flag = 1;
      }
      for (int i = 2; i <= sqrt(k); i++) {
        while (u % i == 0) {
          m2.insert(i);
          u /= i;
        }
      }
      if (u > 1) m2.insert(u);
      long long int x = n, y = m;
      multiset<long long int> m1;
      for (auto f : m2) {
        if (n % f == 0) {
          n /= f;
          m1.insert(f);
        }
      }
      for (auto f : m1) {
        auto it = m2.find(f);
        m2.erase(it);
      }
      for (auto f : m2) m /= f;
      if (flag == 0) {
        if (n * 2 <= x)
          n *= 2;
        else
          m *= 2;
      }
      cout << 0 << " " << 0 << "\n";
      cout << n << " " << 0 << "\n";
      cout << 0 << " " << m << "\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
