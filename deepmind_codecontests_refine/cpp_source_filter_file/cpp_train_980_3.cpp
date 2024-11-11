#include <bits/stdc++.h>
char a[25], b[25];
int main() {
  int i, A = 0, B = 0;
  scanf("%s%s", a, b);
  for (i = 0; i < strlen(a); i = i + 2) {
    if (a[i] == '8' && b[i] == '[') A++;
    if (a[i] == '[' && b[i] == '8') B++;
    if (a[i] == '[' && b[i] == '(') A++;
    if (a[i] == '(' && b[i] == '[') B++;
    if (a[i] == '(' && b[i] == '8') A++;
    if (a[i] == '8' && b[i] == '(') B++;
  }
  if (A > B) printf("TEAM 1 WINS\n");
  if (B > A)
    printf("TEAM 2 WINS\n");
  else
    printf("TIE\n");
  return 0;
}
