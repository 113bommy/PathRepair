#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  long long int t, a, b, c, value;
  value = 0;
  bool flag;
  scanf("%lld %lld %lld", &a, &b, &c);
  for (int i = 0; i < 1000; i++) {
    value = c - i * b;
    if (value < 0) {
      flag = false;
      break;
    }
    if (value % c == 0) {
      flag = true;
      break;
    }
  }
  if (flag)
    printf("Yes\n");
  else
    printf("No\n");
}
