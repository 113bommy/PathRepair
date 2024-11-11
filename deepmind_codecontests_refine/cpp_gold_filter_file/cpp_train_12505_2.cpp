#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long fastmod(long long x, long long n, long long mod = 1e9 + 7) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
set<int> getdv(int k) {
  set<int> re;
  for (int i = 1; i <= sqrt(k); i++)
    if (k % i == 0) {
      re.insert(i);
      re.insert(k / i);
    }
  return re;
}
vector<pair<long long, long long> > vp;
int main() {
  int x;
  cin >> x;
  int a, b;
  for (int i = 1; i <= x; i++)
    for (int j = 1; j <= x; j++) {
      if (i > j) continue;
      if (j % i == 0 && i * j > x && j / i < x) {
        cout << j << " " << i << endl;
        return 0;
      }
    }
  cout << -1 << endl;
}
