#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int gcd(int, int);
int main() {
  int n;
  scanf("%d", &n);
  register int i;
  if (n & 1 == 0) {
    printf("-1");
    return 0;
  }
  for (i = 0; i < n; ++i) printf("%d ", i);
  printf("\n");
  for (i = 0; i < n; ++i) printf("%d ", i);
  printf("\n");
  for (i = 0; i < n; ++i) printf("%d ", (i * 2) % n);
  return 0;
}
