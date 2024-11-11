#include <bits/stdc++.h>
int main() {
  int n, m;
  char ch[51];
  scanf("%s", &ch);
  n = strlen(ch);
  if (n == 1)
    printf("%c", ch[0]);
  else {
    if (n % 2 == 0)
      m = (n / 2) - 1;
    else
      m = (n / 2) - 1;
    printf("%c", ch[m]);
    int j = 1;
    for (int i = 1; i <= n / 2; i++) {
      if (j < n) printf("%c", ch[m + i]);
      j++;
      if (j < n) printf("%c", ch[m - i]);
      j++;
    }
  }
  return 0;
}
