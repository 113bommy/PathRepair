#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, k;
  scanf("%d%d", &n, &m);
  char s[200009], s1[200009];
  scanf("%s%s", s, s1);
  if (n - m > 1) {
    printf("NO\n");
    return 0;
  }
  for (i = 0; i < m; i++) {
    if ((s1[i] < 'a') || (s1[i] > 'z')) break;
  }
  if (i != m) {
    printf("NO\n");
  } else {
    for (i = 0; (i < n) && (i < m); i++) {
      if (s[i] != s1[i]) break;
    }
    if ((i == n) && (i == m))
      printf("YES\n");
    else if (s[i] != '*')
      printf("NO\n");
    else {
      for (j = n - 1, k = m - 1; k >= i; j--, k--) {
        if (s[j] != s1[k]) break;
      }
      if (s[j] == '*')
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
