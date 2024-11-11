#include <bits/stdc++.h>
int main() {
  char a[150], b[150], c[300];
  gets(a);
  gets(b);
  gets(c);
  int p[26], q[26], i, j, count;
  for (i = 0; i < 26; i++) {
    p[i] = 0;
    q[i] = 0;
  }
  for (i = 0; a[i] != '\0'; i++) {
    j = a[i];
    p[j - 65]++;
  }
  for (i = 0; b[i] != '\0'; i++) {
    j = b[i];
    p[j - 65]++;
  }
  for (i = 0; c[i] != '\0'; i++) {
    j = c[i];
    q[j - 65]++;
  }
  count = 0;
  for (i = 0; i < 26; i++) {
    if (p[i] == q[i]) count++;
  }
  if (count == 26)
    printf("YES");
  else
    printf("N0");
  return 0;
}
