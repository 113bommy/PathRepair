#include <bits/stdc++.h>
using namespace std;
int n, m, la, lala, ch, sl, lcp;
long long ans;
char s[100005];
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  sl = strlen(s + 1);
  ans = (long long)n * (m - 1);
  la = s[1];
  for (int i = 2; i <= sl; i++) {
    ch = s[i];
    if (ch == lala)
      lcp++;
    else
      lcp = 0;
    if (ch != la) ans += (long long)n * (m - 1) - lcp - 1;
    lala = la;
    la = ch;
  }
  printf("%lld\n", ans);
  return 0;
}
