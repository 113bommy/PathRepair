#include <bits/stdc++.h>
using namespace std;
int a[100010][3];
char s[100010];
int main() {
  scanf("%s", s + 1);
  int len = strlen(s);
  memset(a, 0, sizeof(a));
  for (int i = 1; i < len; i++) {
    for (int j = 0; j < 3; j++) a[i][j] = a[i - 1][j];
    a[i][s[i] - 'x']++;
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int l, r;
    scanf("%d %d", &l, &r);
    if (r - l + 1 <= 2) {
      puts("YES");
      continue;
    }
    int temp[3];
    for (int i = 0; i <= 2; i++) temp[i] = a[r][i] - a[l - 1][i];
    int maxx = 0, minn = 0x7fffffff;
    for (int i = 0; i <= 2; i++) {
      maxx = max(maxx, temp[i]);
      minn = min(minn, temp[i]);
    }
    if (maxx - minn >= 2)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
