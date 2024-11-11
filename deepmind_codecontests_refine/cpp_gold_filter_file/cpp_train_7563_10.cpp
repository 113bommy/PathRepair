#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  cin >> n;
  if (n & 1)
    printf("%lld\n", (n + 1) / 2);
  else if (n == 0)
    printf("%lld\n", n);
  else
    printf("%lld\n", n + 1);
  return 0;
}
