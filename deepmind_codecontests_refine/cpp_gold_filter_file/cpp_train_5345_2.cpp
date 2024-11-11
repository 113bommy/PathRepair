#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, a[2], k = 0, n, m;
  char s1[100005], s2[100005], c;
  gets(s1);
  gets(s2);
  n = strlen(s1);
  m = strlen(s2);
  if (n == m) {
    for (i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        a[k++] = i;
      }
      if (k == 2) break;
    }
    if (k != 1) {
      c = s2[a[0]];
      s2[a[0]] = s2[a[1]];
      s2[a[1]] = c;
    }
    i = strcmp(s1, s2);
    if (i == 0)
      printf("YES");
    else
      printf("NO");
  } else
    printf("NO");
  return 0;
}
