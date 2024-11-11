#include <bits/stdc++.h>
using namespace std;
long a[1000005];
int main() {
  long n, i, j, k = 0;
  char ch;
  scanf("%ld", &n);
  long ctr = 0, echr = 0, x;
  while (n--) {
    scanf(" %c", &ch);
    scanf("%ld", &x);
    if (ch == '+') {
      if (a[x] <= 0) {
        if (echr == 0)
          ctr++;
        else
          echr--;
        a[x] = 1;
      }
    }
    if (ch == '-') {
      if (a[x] == 0) {
        echr++;
        ctr++;
      } else if (a[x] == 1) {
        echr++;
      }
      a[x]--;
    }
  }
  printf("%ld\n", ctr);
  return 0;
}
