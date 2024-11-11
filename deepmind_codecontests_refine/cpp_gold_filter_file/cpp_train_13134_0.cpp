#include <bits/stdc++.h>
using namespace std;
const int sz = 1e5 + 10, mod = 1e9 + 7;
int p;
int power(int a, int n) {
  if (n == 0) return 1;
  long long x = power(a, n / 2) % p;
  x = (x * x) % p;
  if (n & 1) return (x * a) % p;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, i, x;
  long long res = 0;
  cin >> n >> p >> k;
  unordered_map<int, int> mp;
  for (i = 0; i < n; i++) {
    cin >> x;
    x = (power(x, 4) - (1LL * k * x) % p + p) % p;
    mp[x]++;
  }
  for (auto y : mp) {
    res += 1LL * y.second * (y.second - 1) / 2;
  }
  cout << res;
}
