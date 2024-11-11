#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  while (~scanf("%I64d", &n)) {
    if (n & 1)
      printf("1\n");
    else
      printf("2\n");
  }
  return 0;
}
