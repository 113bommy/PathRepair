#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int mpow(int a, int n) {
  int r = 1;
  while (n) {
    if (n & 1) r = (1LL * r * a) % MOD;
    a = (1LL * a * a) % MOD;
    n >>= 1;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n, k;
  cin >> n >> k;
  int hash = 0, sum = 0;
  for (int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    sum = min(n + 1, sum + b);
    hash = (hash + 1LL * a * b) % MOD;
  }
  if (sum < n) return cout << 1 << '\n', 0;
  if (sum > n) return cout << -1 << '\n', 0;
  int h2 = (1LL * (n) * (n + 1) / 2) % MOD;
  if (hash == h2)
    cout << 1 << '\n';
  else
    cout << -1 << '\n';
}
