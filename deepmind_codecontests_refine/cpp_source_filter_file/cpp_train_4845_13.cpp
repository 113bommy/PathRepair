#include <bits/stdc++.h>
using namespace std;
char s[42];
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf(" %s", s);
    int k = strlen(s + 4), y = atoi(s + 4), f = 0, ten = 10;
    for (int i = 1; i < k; i++) {
      f += ten;
      ten *= 10;
    }
    while (y < 1989 + f) y += ten;
    printf("%d\\n", y);
  }
  return 0;
}
