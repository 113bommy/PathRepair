#include <bits/stdc++.h>
using namespace std;
char s[100005];
int main() {
  scanf("%s", s + 1);
  int ans = 100005, len = strlen(s + 1);
  for (char c = 'a'; c <= 'z'; c++) {
    int pre = 0, k = -1;
    for (int i = 1; i <= len; i++) {
      while (s[i] != c && i < len) {
        i++;
      }
      k = max(k, i - pre);
      pre = i;
    }
    if (k != -1) ans = min(ans, k);
  }
  printf("%d\n", ans);
  return 0;
}
