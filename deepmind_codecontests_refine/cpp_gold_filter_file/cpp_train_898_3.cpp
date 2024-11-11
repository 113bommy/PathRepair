#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnts = 0, cnth = 0;
  scanf("%d\n", &n);
  while (n--) {
    char s[10000], s2[10000];
    scanf("%s%s", s, s2);
    if (s2[0] == 'h') {
      cnth++;
    } else if (s2[0] == 's') {
      cnts++;
    }
  }
  int ans = max(cnth, cnts), tmp = 0, cnt = 1, cou = 0, ttmp = 0;
  while (1) {
    tmp += cnt;
    ttmp++;
    cou++;
    if (ttmp == 2) {
      cnt += 2;
      ttmp = 0;
    }
    if (tmp >= ans) break;
  }
  int ans2 = min(cnth, cnts), cou2 = 1;
  tmp = 0, cnt = 2, ttmp = 0;
  while (ans2 > 0) {
    tmp += cnt;
    ttmp++;
    cou2++;
    if (ttmp == 2) {
      cnt += 2;
      ttmp = 0;
    }
    if (tmp >= ans2) break;
  }
  printf("%d\n", max(cou, cou2));
  return 0;
}
