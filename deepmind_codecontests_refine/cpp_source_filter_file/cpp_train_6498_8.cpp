#include <bits/stdc++.h>
using namespace std;
char s[5100];
int ans, l, now = 1;
int main() {
  scanf("%s", s + 1);
  l = strlen(s + 1);
  for (int i = 1; i + 3 <= l; ++i)
    if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] <= 'r')
      ans += (l - i - 2) * (i - now + 1), now = i + 1;
  printf("%d\n", ans);
}
