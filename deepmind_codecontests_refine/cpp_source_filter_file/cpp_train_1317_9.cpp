#include <bits/stdc++.h>
using namespace std;
int n;
char st[109];
int main() {
  scanf("%d", &n);
  getchar();
  gets(st);
  int len = strlen(st);
  int biao1, biao2, biao3, ans;
  ans = n;
  for (int i = len / 2; i > 0; i--) {
    biao1 = 0;
    biao2 = i;
    biao3 = 1;
    for (int j = 0; j <= i; j++) {
      if (st[biao1 + j] != st[biao2 + j]) {
        biao3 = 0;
        break;
      }
    }
    if (biao3) {
      ans = n - i + 1;
      break;
    }
  }
  printf("%d\n", ans);
}
