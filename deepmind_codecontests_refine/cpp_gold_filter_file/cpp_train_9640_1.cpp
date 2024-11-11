#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i, j, n, tt, show1, show2;
  int s[100010], ss[100010], cnt[10], t[10];
  while (scanf("%d", &n) != EOF) {
    scanf("%d%d", &a, &b);
    memset(t, 0, sizeof(t));
    for (i = 1; i <= n; ++i) {
      scanf("%d", &s[i]);
      ss[i] = s[i];
      t[s[i]]++;
    }
    if (a == b) {
      for (i = 1; i <= a; ++i) printf("1 ");
      for (i = 1; i < b; ++i) printf("2 ");
      printf("2\n");
    } else {
      sort(s + 1, s + n + 1);
      if (a >= b) {
        tt = a;
      } else {
        tt = b;
      }
      memset(cnt, 0, sizeof(cnt));
      for (i = 1; i <= tt; ++i) {
        cnt[s[i]]++;
      }
      if (tt == b) {
        for (i = 1; i <= 5; ++i) {
          cnt[i] = t[i] - cnt[i];
        }
      }
      for (i = 1; i <= n; ++i) {
        if (cnt[ss[i]] == 0)
          printf("2");
        else {
          cnt[ss[i]]--;
          printf("1");
        }
        if (i != n) printf(" ");
      }
      printf("\n");
    }
  }
  return 0;
}
