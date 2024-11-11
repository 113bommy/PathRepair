#include <bits/stdc++.h>
using namespace std;
char s[1000][8];
int main() {
  int n, i, k, cnt, ret = INT_MIN;
  scanf("%d\n", &n);
  for (i = 0; i < n; i++) scanf("%s", s[i]);
  for (i = 0; i < 8 - 1; i++) {
    cnt = 0;
    for (k = 0; k < n; k++) cnt += s[k][i] - '0';
    ret = max(ret, cnt);
  }
  printf("%d", ret);
  return 0;
}
