#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n == 0) {
    printf("0\n");
    return 0;
  }
  if (n % 2 == 1) {
    printf("%lld\n", (long long)((n + 1) / 2));
  } else {
    printf("%lld\n", (long long)(n + 1));
  }
  return 0;
}
