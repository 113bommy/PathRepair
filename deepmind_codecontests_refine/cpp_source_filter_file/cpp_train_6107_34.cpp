#include <bits/stdc++.h>
int main() {
  char a[100];
  scanf("%s", a);
  int i, len = strlen(a);
  for (i = 0; i < len; i++) {
    int count = 0;
    for (int j = i + 1; j < len; j++) {
      if (a[i] != a[j])
        break;
      else
        count++;
    }
    if (count >= 7) {
      printf("YES");
      break;
    }
  }
  if (i == len) printf("NO");
}
