#include <bits/stdc++.h>
const int N = 100005;
char s[N];
bool u[20];
int main() {
  scanf("%s", s);
  int n = strlen(s), i, t0 = 0, t1 = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == '?')
      t0++;
    else if (s[i] >= 'A' && s[i] <= 'Z') {
      int d = s[i] - 'A';
      if (!u[d]) t1++, u[d] = true;
    }
  }
  int r = 1;
  if (s[0] == '?') {
    r = 9;
    t0--;
  }
  if (s[0] >= 'A' && s[0] <= 'Z') {
    r *= 9;
    for (i = 0; i < t1 - 1; i++) r *= (9 - i);
  } else {
    for (i = 0; i < t1; i++) {
      r *= (10 - i);
    }
  }
  printf("%d", r);
  while (t0--) putchar('0');
  return 0;
}
