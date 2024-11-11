#include <bits/stdc++.h>
int main() {
  int n = 0;
  scanf("%d", &n);
  getchar();
  int number[n];
  for (int i = 0; i < n; i++) {
    number[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%c", &(number[i]));
  }
  for (int i = 0; i < n; i++) {
    (number[i]) -= 48;
  }
  int hod = (n - 11) / 2;
  int duble = hod;
  for (int i = 0; i < n - 11 + 1; i++) {
    if (number[i] == 8 && duble > 0) {
      number[i] = 10;
      duble--;
    }
  }
  for (int i = 0; i < n - 11 + 1; i++) {
    if (number[i] == 8) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
}
