#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int main() {
  while (scanf("%s", s) == 1) {
    long long cnt1 = 0, cnt2 = 0, cnt3 = 0;
    long long ans = 0;
    bool flag1 = false, flag2 = false, flag3 = false;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
      if (!flag1 && !flag2) {
        if (isalpha(s[i])) {
          cnt1++;
          flag3 = true;
        } else if (s[i] == '@') {
          if (flag3) flag1 = true;
          flag3 = false;
        } else if (isdigit(s[i]))
          flag3 = true;
        else if (s[i] == '_')
          flag3 = true;
        else if (s[i] == '.') {
          cnt1 = 0;
          flag3 = false;
        }
      } else if (flag1 && !flag2) {
        if (isdigit(s[i]))
          flag3 = true;
        else if (isalpha(s[i])) {
          cnt2++;
          flag3 = true;
        } else if (s[i] == '@') {
          cnt1 = cnt2;
          cnt2 = 0;
          if (flag3)
            flag1 = true;
          else
            flag1 = false;
          flag3 = false;
        } else if (s[i] == '_') {
          cnt1 = cnt2;
          cnt2 = 0;
          flag1 = false;
          flag3 = false;
        } else if (s[i] == '.') {
          if (flag3)
            flag2 = true;
          else {
            cnt1 = cnt2 = cnt3 = 0;
            flag1 = flag2 = false;
          }
          flag3 = false;
        }
      } else if (flag1 && flag2) {
        if (isalpha(s[i])) {
          cnt3++;
          flag3 = true;
        } else if (isdigit(s[i])) {
          ans += cnt1 * cnt3;
          cnt1 = cnt3;
          cnt3 = cnt2 = 0;
          flag3 = true;
          flag1 = false;
          flag2 = false;
        } else if (s[i] == '@') {
          ans += cnt1 * cnt3;
          cnt1 = cnt3;
          cnt3 = cnt2 = 0;
          if (flag3)
            flag1 = true;
          else
            flag1 = false;
          flag2 = flag3 = false;
        } else if (s[i] == '_') {
          ans += cnt1 * cnt3;
          cnt1 = cnt3;
          cnt3 = cnt2 = 0;
          flag3 = true;
          flag1 = false;
          flag2 = false;
        } else if (s[i] == '.') {
          ans += cnt1 * cnt3;
          cnt1 = cnt2 = cnt3 = 0;
          flag1 = flag2 = flag3 = false;
        }
      }
    }
    if (flag1 && flag2 && flag3) ans += cnt1 * cnt3;
    cout << ans << endl;
  }
  return 0;
}
