#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  char s[300005];
  scanf("%s", s);
  if (count(s, s + n, '1') == n) {
    printf("0");
    return 0;
  }
  int foo = 0;
  for (int i = 0; i < n;) {
    int j = i;
    while (j < n and s[j] == '0') j++;
    int k = j;
    while (j < n and s[j] == '1') j++;
    foo += k != i and j != k;
    i = j;
  }
  long long an = 0;
  if (x <= y) {
    an += (foo - (s[n - 1] == '1')) * x * 1LL;
    an += y;
  } else {
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n and s[j] == '0') j++;
      if (j != i)
        an += y;
      else
        j++;
      i = j;
    }
  }
  printf("%I64d", an);
  return 0;
}
