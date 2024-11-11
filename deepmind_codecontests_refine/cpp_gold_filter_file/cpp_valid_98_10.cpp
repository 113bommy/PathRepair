#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
 private:
 public:
  void solve() {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int prefix1[n + 1], prefix2[n + 1];
    prefix1[0] = 0;
    prefix2[0] = 0;
    if (s[0] == 'a')
      prefix1[1] = 1;
    else
      prefix2[1] = 1;
    for (long long int i = 1; i <= n; i++) {
      if (s[i - 1] == 'a') {
        prefix1[i] = prefix1[i - 1] + 1;
        prefix2[i] = prefix2[i - 1];
      } else {
        prefix2[i] = prefix2[i - 1] + 1;
        prefix1[i] = prefix1[i - 1];
      }
    }
    long long int x = -1, y = -1;
    for (long long int i = 1; i <= n; i++) {
      for (long long int j = i + 1; j <= n; j++) {
        if (prefix1[j] - prefix1[i - 1] == prefix2[j] - prefix2[i - 1]) {
          x = i, y = j;
          break;
        }
      }
    }
    cout << x << " " << y << "\n";
  }
};
int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  Solution sol;
  long long int t;
  t = 1;
  cin >> t;
  while (t--) sol.solve();
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
