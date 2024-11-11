#include <bits/stdc++.h>
int main() {
  char a[1000], b[1000];
  scanf("%s", a);
  scanf("%s", b);
  int na = strlen(a), nb = strlen(b);
  int ka = 0, kb = 0;
  for (int i = 0; i < na; i++)
    if (a[i] == '1') ka++;
  for (int i = 0; i < nb; i++)
    if (b[i] == '1') kb++;
  if (ka % 2 == 1) ka++;
  if (kb <= ka)
    printf("YES");
  else
    printf("NO");
  return 0;
}
