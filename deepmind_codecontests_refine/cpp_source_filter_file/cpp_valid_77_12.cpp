#include <bits/stdc++.h>
using namespace std;
inline long long md(long long m, long long v) { return ((v % m) + m) % m; }
void solve() {
  long long n, mod;
  cin >> n >> mod;
  vector<long long> psum(n + 2);
  psum[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    long long tmp = psum[i + 1];
    for (long long j = 2; j * i <= n; j++) {
      long long l = i * j, r = min((i + 1) * j - 1, n);
      tmp = md(mod, tmp + psum[l] - psum[r + 1]);
    }
    psum[i] = md(mod, tmp + psum[i + 1]);
  }
  cout << psum[1] - psum[2];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
