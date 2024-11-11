#include <bits/stdc++.h>
using namespace std;
char s[5005];
int l, l1, a, ans;
int main() {
  scanf("%s", s + 1);
  l = strlen(s + 1);
  for (int i = 1; i <= l; i++) {
    l1 = a = 0;
    for (int j = i; j <= l; j++) {
      if (s[j] == '(')
        l1++;
      else if (s[j] == ')')
        l1--;
      else
        l1--, a++;
      if (!l1) ans++;
      if (l1 < 0 && a)
        l1 += 2, a--;
      else if (l < 0 && !a)
        break;
    }
  }
  printf("%d", ans);
  return 0;
}
