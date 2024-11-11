#include <bits/stdc++.h>
using namespace std;
char s[10010];
int main() {
  int n, m, q;
  scanf("%d", &n);
  getchar();
  gets(s);
  scanf("%d", &q);
  while (q--) {
    char ch;
    scanf("%d%c", &m, &ch);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      if (m <= 0 && s[i] != ch) break;
      if (s[i] != ch) m--;
      r++;
    }
    int ans = r - l;
    for (int i = r; i < n; i++) {
      if (s[i] != ch) {
        ans = max(ans, i - l);
        while (s[l] == ch) l++;
        l++;
      }
    }
    ans = max(ans, n - l);
    printf("%d\n", ans);
  }
  return 0;
}
