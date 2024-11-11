#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  scanf("%I64d", &n);
  while (!n % 3) n = n / 3;
  printf("%I64d\n", n / 3 + 1);
  return 0;
}
