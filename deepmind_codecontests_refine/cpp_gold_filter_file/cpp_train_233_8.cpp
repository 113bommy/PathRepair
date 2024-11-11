#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
vector<long long> fact(N);
template <typename T1, typename T2>
void add_self(T1& a, T2 b) {
  a += b;
  if (a >= 998244353) {
    a -= 998244353;
  }
}
long long pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % 998244353;
    }
    b >>= 1;
    a = (a * a) % 998244353;
  }
  return res;
}
long long modInverse(long long a) { return pow(a, (long long)998244353 - 2); }
long long nCr(long long n, long long r) {
  if (r > n) {
    return 0;
  }
  if (n < r) {
    swap(n, r);
  }
  long long ways = 0;
  ways = (modInverse(fact[r]) * modInverse(fact[n - r])) % 998244353;
  ways = (ways * fact[n]) % 998244353;
  return ways;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout.precision(10);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % 998244353;
  }
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) { return l[i] < l[j]; });
  long long sol = 0;
  multiset<int> s;
  for (int i : order) {
    while (!s.empty() and *s.begin() < l[i]) {
      s.erase(s.begin());
    }
    int len = (int)s.size();
    add_self(sol, nCr(len, k - 1));
    s.insert(r[i]);
  }
  cout << sol;
  return 0;
}
