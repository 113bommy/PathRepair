#include <bits/stdc++.h>
int main() {
  char x[100], y[100], i, counter = 0, j;
  scanf("%s", x);
  scanf("%s", y);
  j = strlen(x);
  for (i = 0; x[i] != NULL; i++) {
    if (x[i] == y[j - i - 1]) {
      counter++;
    }
  }
  if (counter == j) {
    printf("YES");
  } else {
    printf("NO");
  }
  return 0;
}
