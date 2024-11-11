#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const int N = 1e5 + 5, inf = 1e9 + 5;
long long add(long long x, long long y) {
  x += y;
  if (x >= MOD) return x - MOD;
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) return x + MOD;
  return x;
}
long long mult(long long x, long long y) { return (x * y) % MOD; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  set<pair<int, int>> count;
  vector<int> a(k);
  vector<bool> seen(n + 5);
  for (int i = 0; i < k; i++) cin >> a[i];
  for (int i = 0; i < k; ++i) {
    if (seen[a[i] - 1]) count.insert({a[i - 1], a[i]});
    if (seen[a[i] + 1]) count.insert({a[i + 1], a[i]});
    count.insert({a[i], a[i]});
    seen[a[i]] = true;
  }
  cout << (n * 3 - 2) - count.size() << endl;
}
