#include <bits/stdc++.h>
using namespace std;
void io() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
}
bool deb = false;
const int N = 111;
char a[N];
char b[N];
char c[N];
char a1[N];
char a2[N];
char a3[N];
char a4[N];
char a5[N];
char a6[N];
int main() {
  int i, j, n;
  scanf("%s", a), scanf("%s", b), scanf("%s", c);
  int l;
  j = 0;
  l = strlen(a);
  for (i = 0; i < l; i++) {
    if (a[i] != ';' && a[i] != '-' && a[i] != ',' && a[i] != '_')
      if (a[i] >= 'A' && a[i] <= 'Z')
        a[j++] = (a[i] + 32);
      else
        a[j++] = a[i];
  }
  a[j] = '\0';
  j = 0;
  l = strlen(b);
  for (i = 0; i < l; i++)
    if (b[i] != ';' && b[i] != '-' && b[i] != ',' && b[i] != '_')
      if (b[i] >= 'A' && b[i] <= 'Z')
        b[j++] = (b[i] + 32);
      else
        b[j++] = b[i];
  b[j] = '\0';
  j = 0;
  l = strlen(c);
  for (i = 0; i < l; i++)
    if (c[i] != ';' && c[i] != '-' && c[i] != ',' && c[i] != '_')
      if (c[i] >= 'A' && c[i] <= 'Z')
        c[j++] = (c[i] + 32);
      else
        c[j++] = c[i];
  c[j] = '\0';
  strcat(a1, a);
  strcat(a1, b);
  strcat(a1, c);
  strcat(a2, a);
  strcat(a2, c);
  strcat(a2, b);
  strcat(a3, b);
  strcat(a3, c);
  strcat(a3, a);
  strcat(a4, b);
  strcat(a4, a);
  strcat(a4, c);
  strcat(a5, c);
  strcat(a5, b);
  strcat(a5, a);
  strcat(a6, c);
  strcat(a6, a);
  strcat(a6, b);
  scanf("%d", &n);
  while (n--) {
    char aa[811] = {'\0'};
    scanf("\n%s", aa);
    l = strlen(aa);
    j = 0;
    for (i = 0; i < l; i++) {
      if (aa[i] != ';' && aa[i] != '-' && aa[i] != ',' && aa[i] != '_')
        if (aa[i] >= 'a' && aa[i] <= 'z')
          aa[j++] = (aa[i]);
        else if (aa[i] >= 'A' && aa[i] <= 'Z')
          aa[j++] = aa[i] + 32;
    }
    aa[j] = '\0';
    if (strcmp(a1, aa) == 0)
      printf("ACC\n");
    else if (strcmp(a2, aa) == 0)
      printf("ACC\n");
    else if (strcmp(a3, aa) == 0)
      printf("ACC\n");
    else if (strcmp(a4, aa) == 0)
      printf("ACC\n");
    else if (strcmp(a5, aa) == 0)
      printf("ACC\n");
    else if (strcmp(a6, aa) == 0)
      printf("ACC\n");
    else
      printf("WA\n");
  }
  return 0;
}
