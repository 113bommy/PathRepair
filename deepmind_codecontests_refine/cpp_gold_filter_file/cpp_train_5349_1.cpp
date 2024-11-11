#include <bits/stdc++.h>
int main() {
  char input[1000];
  scanf("%s", input);
  if ((input[0] >= 'a') && (input[0] <= 'z')) input[0] += 'A' - 'a';
  printf("%s", input);
}
