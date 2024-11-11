#include <bits/stdc++.h>
using namespace std;
long long l, r, k;
int main() {
  cin >> l >> r >> k;
  if (k >= 4) {
    for (long long i = l; i + 3 <= r; i++) {
      if (i % 2 == 0) {
        printf("0\n4\n%I64d %I64d %I64d %I64d\n", i, i + 1, i + 2, i + 3);
        return 0;
      }
    }
  }
  if (k >= 3) {
    int i = 0;
    while (l >> i > 0) i++;
    long long h = 3LL << (i - 1);
    if (h <= r) {
      printf("0\n3\n%I64d %I64d %I64d %I64\n", h, h ^ l, l);
      return 0;
    }
  }
  if (k >= 2) {
    for (long long i = l; i + 1 <= r; i++) {
      if (i % 2 == 0) {
        printf("1\n2\n%I64d %I64d\n", i, i + 1);
        return 0;
      }
    }
    if ((l ^ r) < l) {
      printf("%I64d\n2\n%I64d %I64d\n", l ^ r, l, r);
      return 0;
    }
  }
  printf("%I64d\n1\n%I64d\n", l, l);
  return 0;
}
