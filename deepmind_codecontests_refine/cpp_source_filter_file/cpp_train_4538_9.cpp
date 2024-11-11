#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C &a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C &a4, C b4) {
  a4 = max(a4, b4);
}
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
vector<long long> factors(long long n) {
  vector<long long> result;
  for (long long p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      while (n % p == 0) {
        n /= p;
      }
      result.push_back(p);
    }
  }
  if (n > 1) {
    result.push_back(n);
  }
  return result;
}
long long almostPhi(long long n) {
  if (n == 1) {
    return 0;
  }
  auto x = factors(n);
  for (long long p : x) {
    (n, p);
    n /= p;
    n *= p - 1;
  }
  return n;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  if (0) cout << fixed << setprecision(6);
  const long long Mod = 1e9 + 7;
  long long N, K;
  cin >> N >> K;
  while (K > 0) {
    if (N == 0) {
      break;
    }
    if (K % 2 == 1) {
      N = almostPhi(N);
    }
    K--;
  }
  cout << N % Mod << "\n";
}
