#include <bits/stdc++.h>
char a1[101], b1[101], c1[101], a2[101], b2[101], c2[101], ans[601], fin[601],
    test[601];
int flag;
void fun(char a[], char b[]) {
  int k = 0, i;
  int len = strlen(a);
  for (i = 0; i < len;) {
    if (a[i] == '-' || a[i] == ';' || a[i] == '_')
      i++;
    else
      b[k++] = a[i++];
  }
  b[k] = 0;
}
void fun2(char a[], char b[], char c[], char test[]) {
  int i, k = 0;
  for (i = 0; i < strlen(a); i++) {
    if (a[i] >= 'A' && a[i] <= 'Z')
      test[k++] = a[i] + 32;
    else
      test[k++] = a[i];
  }
  for (i = 0; i < strlen(b); i++) {
    if (b[i] >= 'A' && b[i] <= 'Z')
      test[k++] = b[i] + 32;
    else
      test[k++] = b[i];
  }
  for (i = 0; i < strlen(c); i++) {
    if (c[i] >= 'A' && c[i] <= 'Z')
      test[k++] = c[i] + 32;
    else
      test[k++] = c[i];
  }
  test[k] = 0;
  if (strcmp(test, fin) == 0) {
    flag = 1;
  }
  for (i = 0; i < strlen(test); i++) test[i] = 0;
}
int main() {
  int n, i, k;
  scanf("%s %s %s", a1, b1, c1);
  scanf("%d", &n);
  while (n--) {
    k = 0;
    scanf("%s", ans);
    fun(a1, a2);
    fun(b1, b2);
    fun(c1, c2);
    fun(ans, fin);
    for (i = 0; i < strlen(fin); i++)
      if (fin[i] >= 'A' && fin[i] <= 'Z') fin[i] = fin[i] + 32;
    fun2(a2, b2, c2, test);
    fun2(a2, c2, b2, test);
    fun2(b2, a2, c2, test);
    fun2(b2, c2, a2, test);
    fun2(c2, a2, b2, test);
    fun2(c2, b2, a2, test);
    if (flag == 1)
      printf("ACC\n");
    else
      printf("WA\n");
    flag = 0;
    for (i = 0; i < strlen(fin); i++) fin[i] = 0;
  }
  return 0;
}
