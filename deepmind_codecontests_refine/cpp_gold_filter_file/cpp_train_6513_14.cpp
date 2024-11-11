#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char s[N];
int n, a, b, k;
int len[N], st[N], ans[N];
int main() {
  while (scanf("%d%d%d%d", &n, &a, &b, &k) != EOF) {
    scanf("%s", s + 1);
    int cnt = 0;
    int last = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '1') {
        int t = i - last - 1;
        if (t >= b) {
          len[cnt] = t;
          st[cnt] = last + 1;
          cnt++;
        }
        last = i;
      }
    }
    int t = n + 1 - last - 1;
    if (t >= b) {
      len[cnt] = t;
      st[cnt] = last + 1;
      cnt++;
    }
    int num = 0;
    for (int i = 0; i < cnt; i++) {
      num += len[i] / b;
    }
    int bns = 0;
    for (int i = 0; i < cnt; i++) {
      int x = len[i];
      int t = len[i] / b;
      int y = st[i];
      while (num >= a && t > 0) {
        ans[bns++] = y + b - 1;
        y += b;
        num--;
        t--;
      }
    }
    printf("%d\n", bns);
    for (int i = 0; i < bns; i++) {
      if (i) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
