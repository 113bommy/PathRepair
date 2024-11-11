#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char str1[maxn], str2[maxn], str3[maxn];
char vis[maxn];
int main() {
  scanf("%s%s%s", str1, str2, str3);
  int len = (int)strlen(str1);
  for (int i = 0; i < len; i++) {
    vis[str1[i]] = str2[i];
  }
  int len2 = (int)strlen(str3);
  for (int i = 0; i < len2; i++) {
    if (isdigit(str3[i])) {
      putchar(str3[i]);
    } else if ('A' <= str3[i] && str3[i] <= 'Z') {
      char tmp = vis[str3[i] - 'A' + 'a'];
      tmp = tmp - 'a' + 'A';
      putchar(tmp);
    } else {
      putchar(vis[str3[i - 1]]);
    }
  }
  return 0;
}
