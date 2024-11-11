#include <bits/stdc++.h>
using namespace std;
long long p = 1000000007;
long long inv(long long x, long long y) {
  if (y == 0) return 1;
  long long temp = inv(x, y / 2);
  temp *= temp;
  temp %= p;
  if (y & 1) return (temp * x) % p;
  return temp;
}
long long power[15];
long long ans[10] = {0};
long long C(long long n, long long r) {
  long long ret = 1;
  if (r > n) return 0;
  if (n == 0 || r == 0) return 1;
  for (int i = 0; i < r; i++) ret *= (n - i);
  for (int i = 0; i < r; i++) ret /= (i + 1);
  return ret;
}
long long cal(long long len, long long dig) {
  long long ret = 1;
  if (dig > len || dig < 0) return 0;
  ret = pow(2, dig) * C(len, dig);
  if (len > dig) ret *= pow(8, (int)len - dig);
  return ret;
}
long long fun(long long num, long long dig) {
  long long Num = num;
  int i = 0;
  if (num == 0 && dig == 0) return 1;
  if (num == 0) return 0;
  for (i = 0; i < 10; i++) {
    if (!Num) break;
    Num /= 10;
  }
  int last = num / power[i - 1];
  long long ret = 0;
  if (last > 7) {
    ret += (last - 2) * cal(i - 1, dig) + 2 * cal(i - 1, dig - 1);
  } else if (last > 4) {
    ret += (last - 1) * cal(i - 1, dig) + cal(i - 1, dig - 1);
  } else {
    ret += cal(i - 1, dig);
    if (last > 0) ret *= last;
  }
  long long ten = power[i - 1];
  long long rem = num % ten;
  dig = dig - (last == 4 || last == 7);
  if (i - 1 >= dig && dig >= 0) ret += fun(rem, dig);
  return ret;
}
long long actual(int ind, int per, int total) {
  long long temp = 1;
  long long ret = 0;
  if (total <= 0) return 0;
  if (per == 0 && total > 0) return 1;
  if (ind == -1) {
    if (per == 0 && total > 0)
      return 1;
    else
      return 0;
  }
  for (int i = 0; i < per + 1; i++) {
    ret += temp * actual(ind - 1, per - i, total - ind * i);
    ret %= p;
    temp *= (ans[ind] - i);
    temp %= p;
    temp *= inv(i + 1, p - 2);
    temp %= p;
  }
  return ret;
}
int main() {
  power[0] = 1;
  for (int i = 0; i < 12; i++) power[i + 1] = power[i] * 10;
  long long number;
  cin >> number;
  int dig;
  for (int i = 0; i < 11; i++)
    if (power[i] > number) {
      dig = i;
      break;
    }
  for (int i = 0; i < dig + 1; i++) {
    ans[i] = fun(number, i);
  }
  ans[0]--;
  long long sum = 0;
  for (int i = 0; i < dig; i++) {
    sum += (actual(i, 6, i + 1) * ans[i + 1] % p) * 720;
    sum %= p;
  }
  cout << sum << endl;
}
