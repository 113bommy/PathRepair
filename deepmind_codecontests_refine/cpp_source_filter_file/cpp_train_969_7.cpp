#include <bits/stdc++.h>
int s[1000];
int main() {
  int a, b, c, result;
  result = 0;
  scanf("%d", &a);
  for (int i = 0; i < a; ++i) {
    scanf("%d", &s[i]);
  }
  b = s[1];
  c = s[1];
  for (int i = 0; i < a; i++) {
    if (s[i] > b) {
      b = s[i];
      result++;
    }
    if (s[i] < c) {
      c = s[i];
      result++;
    }
  }
  printf("%d", result);
}
