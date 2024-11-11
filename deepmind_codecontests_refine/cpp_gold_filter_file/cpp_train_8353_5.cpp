#include <bits/stdc++.h>
using namespace std;
int sc[26];
long long t, n, k;
int solve(int k) {
  int ans = 0;
  for (int m = 1; m * k <= n; m++) {
    int used = 0;
    for (int i = 0; i < 26; i++) {
      if (sc[i] / m + used < k) {
        used += sc[i] / m;
      } else {
        ans = max(ans, m * k);
        break;
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> t;
  while (t--) {
    fill(sc, sc + 26, 0);
    cin >> n >> k;
    cin >> s;
    if (k % n == 0) {
      cout << n << "\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      sc[s[i] - 'a']++;
    }
    sort(sc, sc + 26, greater<int>());
    int mx = 0;
    for (int i = 1; i <= k; i++) {
      if (k % i == 0) {
        mx = max(mx, solve(i));
      }
    }
    cout << mx << "\n";
  }
}
