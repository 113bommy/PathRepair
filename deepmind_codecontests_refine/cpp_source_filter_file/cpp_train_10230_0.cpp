#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    int num[15];
    bool nu[15];
    memset(num, 0, sizeof(num));
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      num[s[i] - '0']++;
    }
    int maxx = -1;
    int ans = -1;
    for (int i = 0; i < 10; i++) {
      maxx = max(maxx, num[i]);
    }
    if (maxx == 1) {
      cout << len - 2 << endl;
    } else {
      memset(nu, false, sizeof(nu));
      for (int i = 0; i < 10; i++)
        if (num[i] * 2 >= maxx) nu[i] = true;
      for (int i = 0; i < 10; i++) {
        if (!nu[i]) continue;
        for (int j = 0; j < 10; j++) {
          if (!nu[j] || j == i) continue;
          bool f = false;
          int cnt = 0;
          for (int k = 0; k < len; k++) {
            if (s[k] == '0' + j && f) {
              f = false;
              cnt++;
            } else if (s[k] == '0' + i) {
              f = true;
            }
          }
          ans = max(ans, cnt);
        }
      }
      cout << min(len - ans * 2, len - maxx / 2) << endl;
    }
  }
}
