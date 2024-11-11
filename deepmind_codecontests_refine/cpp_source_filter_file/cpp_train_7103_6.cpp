#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans;
    for (int i = 0; i < k / 2; i++) {
      int cnt[26] = {0};
      for (int st = 0; st + k - 1 < n; st += k) {
        int i1 = st + i;
        int i2 = st + (k - i - 1);
        cnt[s[i1] - 'a']++;
        cnt[s[i2] - 'a']++;
      }
      int req = 2 * (n / k);
      int mx = *max_element(cnt, cnt + 26);
      ans += req - mx;
    }
    if (k & 1) {
      int cnt[26] = {0};
      for (int i = k / 2; i < n; i += k) {
        cnt[s[i] - 'a']++;
      }
      int req = (n / k);
      int mx = *max_element(cnt, cnt + 26);
      ans += req - mx;
    }
    cout << ans << endl;
  }
  return 0;
}
