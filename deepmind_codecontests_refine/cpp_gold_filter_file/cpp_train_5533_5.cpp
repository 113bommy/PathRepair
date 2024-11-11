#include <bits/stdc++.h>
using namespace std;
long long inv(long long a, long long mod) {
  long long b = mod;
  long long p = 1, q = 0;
  while (b) {
    long long c = a / b;
    long long d = a;
    a = b;
    b = d % b;
    d = p;
    p = q;
    q = d - c * q;
  }
  return (p + mod) % mod;
}
vector<int> divsp(int x) {
  vector<int> res;
  for (int i = 2; i * i <= x; i++) {
    if (x % i != 0) continue;
    res.push_back(i);
    while (x % i == 0) {
      x /= i;
    }
  }
  if (x != 1) res.push_back(x);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m;
  cin >> m;
  long long mod = 1000000007;
  long long res = 0;
  vector<long long> memo(m + 1);
  for (int i = 2; i <= m; i++) {
    vector<int> divp = divsp(i);
    int pr = 1;
    for (int j : divp) pr *= j;
    if (i != pr) continue;
    long long k = m / i;
    long long aa = k * inv(m, mod) % mod;
    long long bb = aa * inv(1 + mod - aa, mod) % mod;
    if (divp.size() & 1)
      res = (res + bb) % mod;
    else
      res = (res - bb + mod) % mod;
  }
  res = (res + 1) % mod;
  cout << res << "\n";
  return 0;
}
