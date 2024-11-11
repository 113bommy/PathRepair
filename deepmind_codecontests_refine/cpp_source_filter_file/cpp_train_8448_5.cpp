#include <bits/stdc++.h>
using namespace std;
long long mod;
struct Pair {
  long long length, sum;
  Pair(long long length, long long sum) : length(length), sum(sum) {}
  Pair oddMap() { return Pair(length, ((sum * 2 - length) % mod + mod) % mod); }
  Pair evenMap() { return Pair(length, sum * 2 % mod); }
};
Pair operator+(const Pair &a, const Pair &b) {
  return Pair(a.length + b.length, (a.sum + b.sum) % mod);
}
Pair solve(long long n, long long l, long long r, long long u, long long v) {
  if (r < 1 || n < l || v < 1 || n < u || v < u) {
    return Pair(0, 0);
  }
  if (l <= 1 && n <= r) {
    long long a = max(u, 1LL);
    long long b = min(v, n);
    long long length = b - a + 1;
    return Pair(length,
                ((length % (mod * 2)) * ((a + b) % (mod * 2)) / 2) % mod);
  }
  int odd = n + 1 >> 1;
  return solve(odd, l, r, u + 2 >> 1, v + 1 >> 1).oddMap() +
         solve(n - odd, l - odd, r - odd, u + 1 >> 1, v >> 1).evenMap();
}
int main() {
  long long n, m;
  cin >> n >> m >> mod;
  for (int i = 0; i < m; ++i) {
    long long l, r, u, v;
    cin >> l >> r >> u >> v;
    cout << solve(n, l, r, u, v).sum << endl;
  }
  return 0;
}
