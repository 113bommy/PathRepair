#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 9;
int N;
int main() {
  scanf("%d", &N);
  long long a = 2, b = 2, c = 4;
  while (N -= 2) {
    a = (a * 2) % mod;
    c = c * (a - 3) % mod;
    b = (b + c) % mod;
  }
  printf("%I64d\n", (b * b % mod + 1) * 2 % mod);
  return 0;
}
