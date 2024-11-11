#include <bits/stdc++.h>
using namespace std;
long long power(long long base, long long p) {
  long long ret = 1;
  while (p) {
    if (p % 2) {
      ret = ret * base;
    }
    p = p / 2;
    base = base * base;
  }
  return ret;
}
int main() {
  long long x, y;
  cin >> x >> y;
  --x;
  vector<long long> sum(20, 0);
  sum[0] = 1;
  sum[1] = 1;
  sum[2] = 1;
  for (long long i = 3; i < 20; ++i) sum[i] = sum[i - 1] * ((long long)10);
  long long dig_x = 0, dig_y = 0;
  long long first_x = 0, first_y = 0;
  long long num = 0;
  num = x;
  while (num) {
    ++dig_x;
    if ((num / 10) == 0) {
      first_x = num;
    }
    num = num / 10;
  }
  num = y;
  while (num) {
    ++dig_y;
    if ((num / 10) == 0) {
      first_y = num;
    }
    num = num / 10;
  }
  long long ans = 0;
  if (dig_y == 1) {
    ans = y;
  } else if (dig_y == 2) {
    ans = (y / 11) + 9;
  } else {
    for (int i = 1; i <= dig_y - 1; ++i) ans += sum[i] * ((long long)(9));
    if (first_y) {
      ans += (first_y - 1) * (power(10, dig_y - 2));
      ans += (y - first_y * power(10, dig_y - 1) - (y % 10)) / 10;
      if (first_y <= (y % 10)) {
        ++ans;
      }
    }
  }
  if (dig_x == 1) {
    ans -= x;
  } else if (dig_x == 2) {
    ans -= (x / 11) + 9;
  } else {
    for (int i = 1; i <= dig_x - 1; ++i) ans -= sum[i] * ((long long)(9));
    if (first_x) {
      ans -= (first_x - 1) * (power(10, dig_x - 2));
      ans -= (x - first_x * power(10, dig_x - 1) - (x % 10)) / 10;
      if (first_x <= (x % 10)) {
        --ans;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
