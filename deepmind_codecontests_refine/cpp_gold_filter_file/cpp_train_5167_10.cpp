#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char s[maxn];
int main() {
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  int minx = len;
  for (int i = 0; i < 26; i++) {
    int pos = 0;
    int ans = 0;
    for (int j = 1; j <= len; j++) {
      if ((s[j] - 'a') == i) {
        ans = max(ans, j - pos);
        pos = j;
      }
    }
    ans = max(len - pos + 1, ans);
    minx = min(minx, ans);
  }
  printf("%d\n", minx);
  return 0;
}
