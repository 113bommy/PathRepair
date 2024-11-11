#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-9;
char s[N];
int main() {
  scanf("%s", s);
  int l, r, ans, i;
  int len = strlen(s);
  for (l = 0; l <= len - 2; l++) {
    if (s[l] == s[l + 1]) break;
  }
  for (r = len - 1; r >= 1; r--) {
    if (s[r] == s[r - 1]) break;
  }
  if (l <= r && s[0] != s[len - 1])
    ans = l - 0 + 1 + len - r;
  else
    ans = max(l + 1, len - r);
  int cnt = 0;
  for (i = l; i <= r; i++) {
    if (s[i] == s[i - 1] || i == r) {
      ans = max(ans, cnt + 1);
      cnt = 0;
    } else
      cnt++;
  }
  printf("%d", ans);
  return 0;
}
