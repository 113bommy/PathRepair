#include <bits/stdc++.h>
using namespace std;
int len, num, slow, ans, i;
char peo[1000001];
int main() {
  scanf("%s", peo + 1), len = strlen(peo + 1);
  for (i = 1; (peo[i] == 'F') && (i <= len); ++i)
    ;
  for (; i <= len; ++i) {
    if (peo[i] == 'F')
      ans = max(ans, i - num - 1 + slow), ++slow, ++num;
    else
      slow ? --slow : 0;
  }
  printf("%d\n", ans);
}
