#include <bits/stdc++.h>
using namespace std;
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    map<int, int> freq = {};
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      long long mod = (k - (x % k) + k) % k;
      if (!mod) continue;
      ans = max(ans, mod + (k * freq[mod]));
      freq[mod]++;
    }
    if (ans) ans++;
    cout << ans << endl;
  }
  return 0;
}
