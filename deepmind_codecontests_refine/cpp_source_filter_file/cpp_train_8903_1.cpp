#include <bits/stdc++.h>
using namespace std;
int ar[1000010];
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  long long int c = 0, c2 = 0;
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int a;
      scanf("%d", &a);
      c += a;
      c2 += a;
    } else {
      if (c % 2 == 0) {
        c += 1;
        c2 -= 1;
      } else {
        c -= 1;
        c2 += 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int md;
    if (i % 2 != 0)
      md = c % n;
    else
      md = c2 % n;
    int j = i + md - 1;
    if (j >= n)
      j -= n;
    else if (j < 0)
      j = n - j;
    ar[j] = i;
  }
  printf("%d", ar[0]);
  for (int i = 1; i < n; i++) printf(" %d", ar[i]);
  printf("\n");
  return 0;
}
