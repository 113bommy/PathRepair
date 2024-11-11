#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    long long tmp = a * b;
    long long bb = pow((long double)tmp, (long double)1.0 / 3) + 0.5;
    if (a % bb != 0 || b % bb != 0 || bb * bb * bb != tmp) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  }
  return 0;
}
