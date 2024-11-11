#include <bits/stdc++.h>
using namespace std;
int a[27], c[27], d[27];
int main() {
  int count, i, n, max, co, t, index, k;
  char str[1010], ch, b[1010];
  ch = getchar();
  while (ch != '\n') {
    a[ch - 'a' + 1]++;
    ch = getchar();
  }
  count = 0;
  for (i = 1; i <= 26; i++)
    if (a[i] != 0) count++;
  scanf("%d", &n);
  if (n < count)
    printf("-1\n");
  else if (n == count) {
    max = 0;
    for (i = 1; i <= 26; i++)
      if (a[i] > max) max = a[i];
    printf("%d\n", max);
    for (i = 1; i <= 26; i++)
      if (a[i] != 0) printf("%c", i + 'a' - 1);
    printf("\n");
  } else {
    t = 0;
    for (i = 1; i <= 26; i++) {
      if (a[i] != 0) b[t++] = i + 'a' - 1;
      c[i] = 1;
    }
    copy(a, a + 27, d);
    for (k = n - count; k > 0; k--) {
      max = 0;
      index = 0;
      for (i = 1; i <= 26; i++)
        if (d[i] > max) {
          max = d[i];
          index = i;
        }
      c[index]++;
      b[t++] = index + 'a' - 1;
      if (a[index] % c[index] != 0)
        d[index] = a[index] / c[index] + 1;
      else
        d[index] = a[index] / c[index];
    }
    max = 0;
    for (i = 1; i <= 26; i++) {
      if (d[i] > max) max = d[i];
    }
    printf("%d\n", max);
    b[t] = 0;
    puts(b);
  }
  return 0;
}
