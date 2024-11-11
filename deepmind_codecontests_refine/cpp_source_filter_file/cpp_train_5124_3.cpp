#include <bits/stdc++.h>
using namespace std;
char s[120];
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%s", s);
    int cnt = 0, ans = 0;
    for (int i = 0; i < n;) {
      if (s[i] == 'A') {
        while (s[++i] == 'P' && i < n) cnt++, i++;
      } else
        i++;
      ans = max(cnt, ans);
      cnt = 0;
    }
    printf("%d\n", ans);
  }
  return 0;
}
