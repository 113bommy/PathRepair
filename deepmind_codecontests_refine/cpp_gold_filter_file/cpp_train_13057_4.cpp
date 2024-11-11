#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a[8], cnt;
  char s[30];
  scanf("%d", &t);
  while (t--) {
    memset(s, 0, sizeof(s));
    memset(a, 0, sizeof(a));
    cnt = 0;
    scanf("%s", s);
    for (int i = 0; i < 12; i++) {
      if (s[i] == 'X') a[0]++;
      if (s[i] == 'X' && s[i + 6] == 'X') a[1]++;
      if (s[i] == 'X' && s[i + 4] == 'X' && s[i + 8] == 'X') a[2]++;
      if (s[i] == 'X' && s[i + 3] == 'X' && s[i + 6] == 'X' && s[i + 9] == 'X')
        a[3]++;
      if (s[i] == 'X' && s[i + 2] == 'X' && s[i + 4] == 'X' &&
          s[i + 6] == 'X' && s[i + 8] == 'X' && s[i + 10] == 'X')
        a[4]++;
    }
    for (int i = 0; i < 5; i++)
      if (a[i]) cnt++;
    if (a[0] == 12) cnt++;
    printf("%d ", cnt);
    if (a[0]) printf("1x12 ");
    if (a[1]) printf("2x6 ");
    if (a[2]) printf("3x4 ");
    if (a[3]) printf("4x3 ");
    if (a[4]) printf("6x2 ");
    if (a[0] == 12) printf("12x1 ");
    printf("\n");
  }
  return 0;
}
