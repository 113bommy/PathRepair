#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  string t;
  while (cin >> t) {
    int a, num[10] = {0}, have[10] = {0};
    string s;
    cin >> s;
    for (int i = 0; i < t.size(); i++) {
      a = t[i] - '0';
      if (a == 9)
        num[6]++;
      else if (a == 5)
        num[2]++;
      else
        num[a]++;
    }
    int ans = 10000000005;
    for (int i = 0; i < s.size(); i++) {
      a = s[i] - '0';
      if (a == 9)
        have[6]++;
      else if (a == 5)
        have[2]++;
      else
        have[a]++;
    }
    for (int i = 0; i < 9; i++) {
      if (i == 5) continue;
      if (num[i] > 0) ans = min(ans, have[i] / num[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
