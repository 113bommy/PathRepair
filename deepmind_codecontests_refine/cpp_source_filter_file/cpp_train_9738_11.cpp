#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int i = 0, j = 0, ans = 0;
  int freq[2] = {0};
  while (i < n) {
    if (j > n - 1) {
      i++;
      freq[s[i - 1] - 'a']--;
      int kd = min(freq[0], freq[1]);
      if (kd <= k) {
        ans = max(ans, kd + max(freq[0], freq[1]));
      }
      continue;
    }
    freq[s[j] - 'a']++;
    int kd = min(freq[0], freq[1]);
    while (min(freq[0], freq[1]) > k) {
      i++;
      freq[s[i - 1] - 'a']--;
    }
    if (kd == k) {
      ans = max(ans, k + max(freq[0], freq[1]));
    }
    j++;
  }
  cout << ans << "\n";
  return 0;
}
