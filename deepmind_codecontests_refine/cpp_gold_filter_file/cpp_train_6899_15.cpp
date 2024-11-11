#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
long long C(long long n, long long k) {
  if (k > n) return 0;
  if (k * 2 > n) k = n - k;
  if (k == 0) return 1;
  long long result = n;
  for (long long i = 2; i <= k; ++i) {
    result *= (n - i + 1);
    result /= i;
  }
  return result;
}
long long power(long long x, unsigned long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
const long long Nmax = 1e5 + 2;
vector<long long> adj[Nmax];
bool v[Nmax];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  long long n = s.size();
  cout << "3\n";
  cout << "R " << n - 1 << '\n';
  n++;
  cout << "L " << n - 1 << '\n';
  cout << "L 2\n";
  return 0;
}
