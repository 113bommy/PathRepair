#include <bits/stdc++.h>
using namespace std;
const long long maxs = 1e6 + 321;
long long mpow(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long t = mpow(a * a % p, b / 2, p);
  if (b % 2) t = t * a % p;
  return t;
}
long long fact[maxs], invf[maxs];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, a, q;
  cin >> n >> m >> a >> q;
  a %= q;
  long long ord = 1;
  long long ac = a;
  while (ac != 1) {
    ac = ac * a;
    ac %= q;
    ++ord;
  }
  invf[0] = fact[0] = 1;
  for (int i = 1; i < maxs; ++i) {
    fact[i] = fact[i - 1] * i % ord;
    invf[i] = mpow(fact[i], ord - 2, ord);
  }
  vector<long long> sol;
  long long acum = 0;
  for (int i = 0; i < min(n, m + 1); ++i) {
    acum = (acum + fact[m] * invf[m - i] % ord * invf[i]) % ord;
    sol.push_back(acum);
  }
  while (sol.size() < n) {
    sol.push_back(sol.back());
  }
  reverse(sol.begin(), sol.end());
  for (int i = 0; i < n; ++i) {
    cout << (i ? " " : "") << mpow(a, sol[i], q);
  }
  cout << endl;
}
