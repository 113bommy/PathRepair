#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char c[N];
bool flag;
int a[N];
int main() {
  while (~scanf("%s", c)) {
    int cnt = 1, m = 0;
    for (int i = 1; i < strlen(c); i++) {
      if (c[i] == c[i - 1])
        cnt++;
      else
        a[++m] = cnt, cnt = 1;
    }
    a[++m] = cnt;
    if (m & 1) a[1] += a[m--];
    flag = 0;
    for (int i = 1; i <= m; ++i) {
      if (a[i] >= 2) {
        flag = 1;
        break;
      }
    }
    int p = 1;
    if (flag)
      while (a[p] == 1) a[++m] = a[p++];
    int ans = 0;
    cnt = 0;
    for (int i = p; i <= m; ++i) {
      if (a[i] >= 2)
        ans += cnt / 2 + 1, cnt = 0;
      else
        ++cnt;
    }
    printf("%d\n", ans + (cnt >> 1));
  }
  return 0;
}
