#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int n, k, rptn, ans;
  string s;
  int count[26] = {0};
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cin >> s;
    rptn = n / k;
    ans = 0;
    if (k % 2 == 0) {
      for (int i = 0; i < k / 2; i++) {
        memset(count, 0, sizeof(count));
        for (int j = 0; j < rptn; j++) {
          count[s[i + j * k] - 'a']++;
          count[s[j * k + k - i - 1] - 'a']++;
        }
        sort(count, count + 26);
        ans += (2 * rptn - count[25]);
      }
      cout << ans << endl;
    } else {
      for (int i = 0; i < k / 2; i++) {
        memset(count, 0, sizeof(count));
        for (int j = 0; j < rptn; j++) {
          count[s[i + j * k] - 'a']++;
          count[s[j * k + k - i - 1] - 'a']++;
        }
        sort(count, count + 26);
        ans += (2 * rptn - count[25]);
      }
      memset(count, 0, sizeof(count));
      for (int j = 0; j < rptn; j++) {
        count[s[k / 2 + j * k] - 'a']++;
      }
      sort(count, count + 26);
      ans += (rptn - count[25]);
      cout << ans << endl;
    }
  }
}
