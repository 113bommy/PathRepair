#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  while (scanf("%I64d", &n) == 1) {
    if (n / 2)
      printf("1\n");
    else
      printf("2\n");
  }
  return 0;
}
