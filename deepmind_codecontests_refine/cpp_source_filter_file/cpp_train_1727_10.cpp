#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long e, long long m) {
  long long p = 1;
  while (e > 0) {
    if (e & 1) p = (p * b) % m;
    e = e >> 1;
    b = (b * b) % m;
  }
  return p;
}
char a[11];
long long br[10] = {8, -1, -1, 3, 6, 9, 4, 7, 0, 5};
int main() {
  long long n, i = 100, j, m, h, h1, h2, q, k, l, r, ans;
  scanf("%s", a);
  n = strlen(a);
  for (i = 0, j = n - 1; i < j; i++, j--) {
    if (br[a[i] - '0'] != a[j] - '0') {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
