#include <bits/stdc++.h>
int main() {
  char b[26];
  char c;
  int n;
  scanf("%i", &n);
  getchar();
  for (int i = 0; i < 26; i++) {
    b[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    c = getchar();
    b[(int)c - 97]++;
  }
  int wrong = 0;
  int kind = 0;
  for (int i = 0; i < 26; i++) {
    if (b[i] == 1) {
      wrong++;
    }
    if (b[i] > 0) {
      kind++;
    }
  }
  if ((kind > 1) && (wrong == kind)) {
    printf("No");
  } else {
    printf("Yes");
  }
  return 0;
}
