#include <bits/stdc++.h>
int main() {
  char n[100], m[100];
  scanf("%s", n);
  scanf("%s", m);
  for (int i = 0; n[i] != '\0' && m[i] != '\0'; i++) {
    if (n[i] != m[i])
      printf("1");
    else
      printf("0");
  }
}
