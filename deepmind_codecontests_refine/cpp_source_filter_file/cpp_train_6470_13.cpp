#include <bits/stdc++.h>
int main() {
  int n, count = 0, i;
  scanf("%d\n", &n);
  char str[n];
  gets(str);
  for (i = 0; i < n; i++) {
    if (str[i] == '8') {
      count++;
    }
  }
  if (count > ((n - 11) / 2)) {
    printf("YES");
  } else {
    printf("NO");
  }
}
