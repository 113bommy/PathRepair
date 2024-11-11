#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int MAXM = 1e6 + 6;
const int inf = 0x3f3f3f3f;
char str[MAXN];
int main() {
  scanf("%s", str + 1);
  int len = strlen(str + 1);
  int r = len + 2;
  long long ans = 0;
  for (int i = len - 1; i >= 1; i--) {
    for (int j = 1; i + j * 2 <= len; j++)
      if (str[i] == str[i + j] && str[i] == str[i + j * 2]) {
        r = min(r, i + j * 2);
        break;
      }
    ans += max(len - r + 1, 0);
  }
  printf("%lld\n", ans);
  return 0;
}
