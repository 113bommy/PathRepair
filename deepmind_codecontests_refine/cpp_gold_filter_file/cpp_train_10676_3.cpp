#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long x = 2;
  for (long long i = 1; i <= n; ++i) {
    long long z = x / i;
    long long a = (i + 1) * (i + 1) * i;
    long long tmp = a - z;
    printf("%I64d\n", tmp);
    x = (i + 1) * i;
  }
  return 0;
}
