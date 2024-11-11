#include <bits/stdc++.h>
const int N = 110000;
char s[N];
int flag, ans, e1, s2, e2;
int main() {
  scanf(" %s", s + 1);
  int n = strlen(s + 1), ans = 0;
  flag = 0;
  for (int i = 1; i <= n; ++i) s[i] -= '0';
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 0) continue;
    int j = i;
    int s1 = i;
    if (s[i + 1] == 0) {
      while (j < n && s[j + 1] == 0) j++;
    }
    if (!e1)
      e1 = j, ans++;
    else {
      if (j - s1 + 1 > e1)
        e1 = j, ans = 1;
      else if (j - s1 + 1 < e1)
        e1 = j, ans++;
      else if (j - s1 + 1 == e1) {
        for (int l = 1, k = s1; k <= j; ++k, ++l) {
          if (s[l] > s[k]) {
            ans++, e1 = j;
            break;
          }
          if (s[l] < s[k]) {
            ans = 1;
            e1 = j;
            break;
          }
          if (k == j) {
            ans++;
            e1 = j;
          }
        }
      }
    }
  }
  printf("%d", ans);
  return 0;
}
