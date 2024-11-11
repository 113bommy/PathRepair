#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
mt19937 rng(steady_clock::now().time_since_epoch().count());
void usaco(string filename) {
#pragma message("be careful, freopen may be wrong")
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
const long long mod = 1000000007;
long long madd(long long a, long long b) { return (a + b) % mod; }
long long msub(long long a, long long b) {
  return (((a - b) % mod) + mod) % mod;
}
long long mmul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long mpow(long long base, long long exp) {
  long long res = 1;
  while (exp) {
    if (exp % 2 == 1) {
      res = (res * base) % mod;
    }
    exp >>= 1;
    base = (base * base) % mod;
  }
  return res;
}
long long minv(long long base) { return mpow(base, mod - 2); }
long long mdiv(long long a, long long b) { return mmul(a, minv(b)); }
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  if (y == 0) return x;
  return gcd(y, x % y);
}
bool prime[1000006];
void sieve(int n) {
  for (long long i = 0; i < n + 1; i++) prime[i] = 1;
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  prime[1] = prime[0] = 0;
}
long long n, m, k, q, Q, T, l, r, x, y, z;
long long a[500005];
long long b[500005];
string second, t;
long long ans = 0;
bool d[301][301][301];
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  };
  cin >> n;
  for (int ele = 0; ele < n; ele++) cin >> a[ele];
  ;
  if (n == 1) {
    if (a[0] == 0)
      cout << "BitAryo" << endl;
    else
      cout << "BitLGM" << endl;
  } else if (n == 2) {
    bool dp[301][301];
    int mn = min(a[0], a[1]);
    memset(dp, 0, sizeof(dp));
    for (long long i = 0; i < a[0] + 1; i++) {
      for (long long j = 0; j < a[1] + 1; j++) {
        if (!i && !j) {
          dp[i][j] = 0;
          continue;
        }
        bool first = 1;
        int mn = min(i, j);
        for (long long fac = 1; fac < mn + 1; fac++) {
          first &= dp[i - fac][j - fac];
        }
        for (long long fac = 0; fac < i; fac++) first &= dp[fac][j];
        for (long long fac = 0; fac < j; fac++) first &= dp[i][fac];
        dp[i][j] = !first;
      }
    }
    cout << (dp[a[0]][a[1]] ? "BitLGM" : "BitAryo") << endl;
  } else if (n == 3) {
    int mn = min(a[0], min(a[1], a[2]));
    if (mn > 61) {
      int fac = (mn - 61) / 2;
      a[0] -= 2 * fac;
      a[1] -= 2 * fac;
      a[2] -= 2 * fac;
    }
    memset(d, 0, sizeof(d));
    for (long long i = 0; i < a[0] + 1; i++) {
      for (long long j = 0; j < a[1] + 1; j++) {
        for (long long k = 0; k < a[2] + 1; k++) {
          if (!i && !j && !k) {
            d[i][j][k] = 0;
            continue;
          }
          bool first = 1;
          int mn = min(i, min(j, k));
          for (long long fac = 1; fac < mn + 1; fac++) {
            first &= d[i - fac][j - fac][k - fac];
          }
          for (long long fac = 0; fac < i; fac++) first &= d[fac][j][k];
          for (long long fac = 0; fac < j; fac++) first &= d[i][fac][k];
          for (long long fac = 0; fac < k; fac++) first &= d[i][j][fac];
          d[i][j][k] = !first;
        }
      }
    }
    cout << (d[a[0]][a[1]][a[2]] ? "BitLGM" : "BitAryo") << endl;
  }
}
