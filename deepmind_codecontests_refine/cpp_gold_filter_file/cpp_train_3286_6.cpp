#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long double pi = acos(-1.0);
const string debug_line = "yolo";
const long double PI = acos((long double)-1.0);
bool isPrime(long long n) {
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  long long n;
  scanf("%lld", &n);
  long long answer1 = 3;
  if (isPrime(n)) {
    answer1 = 1;
  } else {
    for (long long i = 2; i <= 4000; i++) {
      if (isPrime(i) && isPrime(n - i) && i >= 2 && n - i >= 2) {
        answer1 = 2;
      }
    }
  }
  printf("%lld\n", answer1);
  return 0;
}
