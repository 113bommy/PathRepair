#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 100;
const int b[] = {0, 2, 3, 1};
long long get_num1(long long x) {
  long long base = 1;
  while (base < x) {
    x -= base;
    base <<= 2;
  }
  return base + x - 1;
}
long long get_num2(long long x) {
  long long num1 = get_num1(x);
  long long ans = 0;
  for (int i = 0; i <= 60; i += 2) {
    ans += (1LL << i) * b[num1 % 4];
    num1 >>= 2;
  }
  return ans;
}
int main() {
  int w;
  cin >> w;
  while (w--) {
    long long n;
    scanf("%lld", &n);
    long long row = (n - 1) / 3 + 1;
    int col = (n - 1) % 3;
    long long num1 = get_num1(row);
    long long num2 = get_num2(row);
    long long num3 = num1 ^ num2;
    if (col == 0)
      printf("%lld\n", num1);
    else if (col == 1)
      printf("%lld\n", num2);
    else
      printf("%lld\n", num3);
  }
  return 0;
}
