#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int main() {
  int s, k;
  long long n;
  scanf("%d", &s);
  for (int i = 0; i < s; i++) {
    scanf("%d", &k);
    n = k;
    if ((n + 1) % 2 == 1)
      printf("%I64d\n", 4 * n + 1);
    else if ((n + 1) / 2 % 2 == 1)
      printf("%I64d\n", 2 * n + 1);
    else
      printf("%I64d\n", n + 1);
  }
}
