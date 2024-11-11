#include <bits/stdc++.h>
int main() {
  int n;
  long long int sum = 0;
  scanf("%d", &n);
  char s[n];
  scanf("%s", s);
  for (int i = 0; s[i] != NULL; ++i) {
    if (s[i] == 'B') {
      sum += pow(2, i);
    }
  }
  printf("%d", sum);
  return 0;
}
