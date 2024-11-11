#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
char s[3 * (int)1e5 + 5];
int main() {
  scanf("%lld %lld %lld", &n, &x, &y);
  scanf("%s", s);
  long long one = 0, zero = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '0') {
      while (s[i] == '0') {
        i++;
      }
      --i;
      ++zero;
    } else if (s[i] == '1') {
      while (s[i] == '1') {
        i++;
      }
      --i;
      ++one;
    }
  }
  long long ans = zero * y;
  if (s[0] == '0') ans = min(ans, (zero - 1LL) * x + y);
  if (s[0] == '1') ans = min(ans, (one - 1LL) * x + y);
  if (s[strlen(s) - 1] == '0') ans = min(ans, (zero - 1LL) * x + y);
  if (s[strlen(s) - 1] == '1') ans = min(ans, (one - 1LL) * x + y);
  if (s[0] == '1' && s[strlen(s) - 1] == '1')
    ans = min(ans, (zero - 1LL) * x + y);
  printf("%lld\n", ans);
  return 0;
}
