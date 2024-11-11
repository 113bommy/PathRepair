#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, s, odd = 0, even = 0;
  scanf("%lld", &n);
  for (long long i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    if (x % 2 == 0)
      even++;
    else
      odd++;
    s += x;
  }
  if (s & 1) {
    puts("First");
  } else {
    if (odd % 2 == 0)
      puts("Second");
    else
      puts("First");
  }
  return 0;
}
