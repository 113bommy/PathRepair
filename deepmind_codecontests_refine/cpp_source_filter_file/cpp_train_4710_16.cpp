#include <bits/stdc++.h>
using namespace std;
unsigned long long next(unsigned long long n) {
  unsigned long long mask = 3;
  int k = 0;
  unsigned long long ret = 0;
  while (mask <= n || (mask & n) != 0) {
    unsigned long long cur_ret = n & mask;
    if (cur_ret != 0) {
      cur_ret += (1LL << k);
      cur_ret &= mask;
      if (cur_ret == 0) cur_ret = (1 << k);
    }
    ret |= cur_ret;
    mask <<= 2;
    k += 2;
  }
  return ret;
}
unsigned long long get_num_1(unsigned long long n) {
  unsigned long long base = 1;
  while ((base << 2) <= n) {
    base <<= 2;
  }
  n -= (base - 1);
  return base + n / 3;
}
unsigned long long get_num_2(unsigned long long n) {
  unsigned long long base = get_num_1(n - 1);
  return next(base);
}
unsigned long long get_num_0(unsigned long long n) {
  unsigned long long base = get_num_2(n - 1);
  return next(base);
}
unsigned long long get_num(unsigned long long n) {
  switch (n % 3) {
    case 0:
      return get_num_0(n);
    case 1:
      return get_num_1(n);
    case 2:
      return get_num_2(n);
    default:
      return 0;
  }
}
int main() {
  int num;
  cin >> num;
  for (int i = 0; i < num; ++i) {
    unsigned long long n;
    cin >> n;
    unsigned long long num1 = get_num(n);
    cout << num1 << endl;
  }
  return 0;
}
