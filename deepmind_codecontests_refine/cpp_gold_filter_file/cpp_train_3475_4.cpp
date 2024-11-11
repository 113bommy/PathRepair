#include <bits/stdc++.h>
using namespace std;
int s[1000006], st[10000006];
bool t[1000006];
int n, m, i, j, k, sn;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &s[i]);
    t[i] = 0;
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &j);
    t[j - 1] = 1;
  }
  sn = 0;
  for (i = n - 1; i >= 0; i--) {
    if (t[i]) {
      st[sn++] = s[i];
    } else if ((sn > 0) && (st[sn - 1] == s[i]))
      sn--;
    else {
      t[i] = 1;
      st[sn++] = s[i];
    }
  }
  if (sn == 0) {
    printf("YES\n");
    printf("%d", s[0]);
    for (i = 1; i < n; i++)
      if (t[i])
        printf(" %d", -s[i]);
      else
        printf(" %d", s[i]);
  } else
    printf("NO");
  printf("\n");
  return 0;
}
