#include <bits/stdc++.h>
using namespace std;
char s[200005];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    s[i + len] = s[i];
  }
  int l = 0, r = 1, ans = 0;
  while (l < len * 2 && r < len * 2) {
    while (r < len * 2 && r - l < len && s[r] != s[r - 1]) ++r;
    ans = max(r - l, ans);
    l = r;
    r = l + 1;
  }
  printf("%d\n", ans);
  return 0;
}
