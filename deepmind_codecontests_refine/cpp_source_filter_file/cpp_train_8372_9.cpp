#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mx = 1000005;
char s[mx];
int main() {
  gets(s);
  int i, j, len = strlen(s), lastat = -1;
  long long ans = 0LL, cnt1 = 0LL, cnt2 = 0LL;
  for (i = 0; i < len; ++i) {
    if (s[i] == '@' && i) {
      cnt1 = 0;
      for (j = i - 1; j >= 0; --j) {
        if (s[j] == '@' || s[j] == '.') break;
        if (isalpha(s[j])) cnt1++;
      }
      lastat = i;
    } else if (s[i] == '.' && i && cnt1) {
      cnt2 = 0;
      for (j = i + 1; j < len; ++j) {
        if (!isalpha(s[j])) break;
        ++cnt2;
      }
      for (j = lastat + 1; j < i; ++j) {
        if (!isalpha(s[j]) && !isdigit(s[j])) {
          cnt2 = 0;
          break;
        }
      }
      if (lastat + 1 == i) cnt2 = 0;
    }
    if (cnt1 || cnt2) ans += cnt1 * cnt2, cnt1 = cnt2 = 0;
  }
  printf("%I64d\n", ans);
  return 0;
}
