#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long a, b, tag = 0;
  int ans;
  scanf("%lld%lld", &a, &b);
  if (a > b) {
    long long s = a;
    a = b;
    b = s;
    tag = 1;
  }
  long long g = gcd(b, a);
  long long sum = (g + a) * a / g;
  g = a / g;
  g *= b;
  if (sum == g) {
    printf("Equal\n");
  } else if (sum > g) {
    if (tag) {
      printf("Dasha\n");
    } else {
      printf("Masha\n");
    }
  } else {
    if (tag) {
      printf("Masha\n");
    } else {
      printf("Dasha\n");
    }
  }
  return 0;
}
