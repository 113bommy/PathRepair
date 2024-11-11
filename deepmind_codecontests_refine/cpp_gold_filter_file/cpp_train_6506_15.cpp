#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char s[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  long long ans = 0;
  int now = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] != s[i - 1]) ans += n * (m - 1);
    if (i > 1 && s[i] != s[i - 1] && s[i] == s[i - 2]) {
      now++;
    } else if (i > 1 && s[i] != s[i - 1]) {
      now = 2;
    } else {
      now = 1;
    }
    ans -= now - 1;
  }
  printf("%lld\n", ans);
  return 0;
}
