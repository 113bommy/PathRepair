#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1e9;
const long double eps = 1e-18;
int main() {
  ios_base::sync_with_stdio(0);
  int n, ans = 0;
  cin >> n;
  if (n == 1000000000) ans++;
  set<int> s;
  for (int i = 0; i < 10; i++) {
    for (int j = i; j < 10; j++) {
      if (i == 0 && j == 0) continue;
      for (int mask = 0; mask < (1 << 9); mask++) {
        int x = 0;
        for (int k = 8; k >= 0; k--) {
          if ((mask & (1 << k)) > 0)
            x = x * 10 + j;
          else
            x = x * 10 + i;
          if (x > 0 && x <= n) {
            s.insert(x);
          }
        }
      }
    }
  }
  ans += s.size();
  cout << ans << '\n';
  return 0;
}
