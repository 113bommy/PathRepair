#include <bits/stdc++.h>
using namespace std;
const int BASE = 261;
const int MOD = 1e9 + 7;
const int SIZE = 5 * 1e6 + 1;
int k_pal[SIZE];
void solve() {
  string s;
  cin >> s;
  long long hash = 0;
  long long rev_hash = 0;
  long long deg = 1;
  int ans = 0;
  for (int i = 1; i <= s.size(); i++) {
    hash = (hash + s[i - 1] * deg) % MOD;
    rev_hash = (rev_hash * BASE + s[i - 1]) % MOD;
    deg = (deg * BASE) % MOD;
    if (hash == rev_hash) {
      k_pal[i] = k_pal[i / 2] + 1;
      ans += k_pal[i];
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
