#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[1010];
  int n;
  int fivechar = 0, bigchar = 0, smallchar = 0, num = 0;
  int flag = 0;
  scanf("%s", a);
  n = strlen(a);
  if (n < 5) flag = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] >= 65 && a[i] <= 90)
      bigchar = 1;
    else if (a[i] >= 97 && a[i] <= 122)
      smallchar = 1;
    else if (a[i] >= 48 && a[i] <= 57)
      num = 1;
    else if (a[i] == '!' || a[i] == '?' || a[i] == '.' || a[i] == ',' ||
             a[i] == '_')
      continue;
    else
      flag = 1;
  }
  if (bigchar == 1 && smallchar == 1 && num == 1 && flag == 0)
    printf("Correct");
  else
    printf("Too weak\n");
  return 0;
}
