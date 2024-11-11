#include <bits/stdc++.h>
using namespace std;
inline long long input(void) {
  char t;
  long long x = 0;
  int neg = 0;
  t = getchar();
  while ((t < 48 || t > 57) && t != '-') t = getchar();
  if (t == '-') {
    neg = 1;
    t = getchar();
  }
  while (t >= 48 && t <= 57) {
    x = (x << 3) + (x << 1) + t - 48;
    t = getchar();
  }
  if (neg) x = -x;
  return x;
}
inline void output(long long x) {
  char a[20];
  int i = 0, j;
  a[0] = '0';
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x == 0) putchar('0');
  while (x) {
    a[i++] = x % 10 + 48;
    x /= 10;
  }
  for (j = i - 1; j >= 0; j--) {
    putchar(a[j]);
  }
  putchar('\n');
}
int main() {
  long long len, i, cnt[10], j, x,
      ans[7] = {1869, 6819, 6918, 6891, 1698, 9861, 1896};
  char s[1000010];
  scanf("%s", s);
  len = strlen(s);
  for (i = 0; i < len; i++) cnt[s[i] - '0']++;
  if (cnt[0] + 4 == len) {
    s[0] = '1';
    s[1] = '8';
    s[2] = '6';
    s[3] = '9';
    for (i = 4; i < len; i++) s[i] = '0';
    printf("%s\n", s);
  } else {
    cnt[1]--;
    cnt[8]--;
    cnt[6]--;
    cnt[9]--;
    j = 0;
    x = 0;
    for (i = 9; i >= 0; i--) {
      while (cnt[i]) {
        s[j] = i + '0';
        x = 10 * x + i;
        x %= 7;
        j++;
        cnt[i]--;
      }
    }
    s[len - 4] = '\0';
    x *= 10000;
    x %= 7;
    printf("%s", s);
    if (x != 0)
      output(ans[7 - x]);
    else
      output(ans[0]);
  }
  return 0;
}
