#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[200011];
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  long long ans = n * (m - 1);
  for (int i = 2; i <= n; i++)
    if (s[i] != s[i - 1]) ans += n * (m - 1);
  int len = 1;
  for (int i = 2; i <= n; i++) {
    if (len == 1)
      if (s[i - 1] != s[i])
        len++;
      else {
      }
    else if (s[i - 2] == s[i])
      len++;
    else {
      ans -= 1ll * len * (len - 1) / 2;
      if (s[i] == s[i - 1])
        len = 1;
      else
        len = 2;
    }
  }
  ans -= 1ll * len * (len - 1) / 2;
  printf("%lld\n", ans);
  return 0;
}
