#include <bits/stdc++.h>
using namespace std;
const double PI = M_PI;
const int INF = -1 * 1e9;
const long long limit = 1 * 1e12;
const int MOD1 = 1e9 + 711;
const int MOD2 = 1e9 + 933;
const int MOD3 = 1e9 + 993;
const int maxn = 3e8 + 1;
bitset<maxn> p;
int main() {
  cout.tie(0);
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int l, r;
  cin >> l >> r;
  p.set();
  for (int i = 3; i <= r; i += 2) {
    if (p[i]) {
      for (long long j = 1LL * i * i; j <= r; j += i + i) {
        p[j] = false;
      }
    }
  }
  int ans = 0;
  for (int i = 5; i <= r; i += 4) {
    if (p[i] && i >= l) {
      ++ans;
    }
  }
  if (l >= 2 && 2 <= r) {
    ++ans;
  }
  cout << ans;
  cerr << "\n\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}
