#include <bits/stdc++.h>
using namespace std;
int main() {
  char str1[100], str2[100];
  int len1, len2, i;
  gets(str1);
  gets(str2);
  len1 = strlen(str1);
  len2 = strlen(str2);
  if (len1 != len2)
    printf("NO");
  else {
    int k = 1;
    for (i = 0; i < len1 && k; i++) {
      if (str1[i] != str2[len1 - 1 - i]) {
        k = 0;
      }
    }
    if (k == 0)
      printf("NO");
    else
      printf("YES");
  }
  return 0;
}
