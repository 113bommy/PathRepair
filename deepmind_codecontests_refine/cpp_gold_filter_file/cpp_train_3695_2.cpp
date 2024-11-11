#include <bits/stdc++.h>
using namespace std;
char s[200001];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int i, count, r = 0;
  char first;
  first = s[0];
  count = 1;
  i = 1;
  while (first == s[i] && i < n) {
    count++;
    i++;
  }
  for (i = count; i <= n - 1; i++) {
    if (count == 0) {
      first = s[i];
      count = 1;
    } else if (first != s[i]) {
      count--;
      r++;
    } else
      count++;
  }
  printf("%d\n", n - 2 * r);
  return 0;
}
