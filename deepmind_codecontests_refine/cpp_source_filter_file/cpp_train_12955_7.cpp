#include <bits/stdc++.h>
using namespace std;
long long int a[] = {0,
                     1,
                     11,
                     111,
                     1111,
                     11111,
                     111111,
                     1111111,
                     11111111,
                     111111111,
                     1111111111,
                     11111111111,
                     111111111111,
                     1111111111111,
                     11111111111111,
                     111111111111111,
                     1111111111111111};
long long int size_of(long long int n) {
  long long int count = 0;
  while (n) {
    count++;
    n /= 10;
  }
  return count;
}
long long int f(long long int n, string s) {
  int x;
  long long int size_n = size_of(n), ans, mul;
  if (n == a[size_n]) {
    return a[size_n];
  }
  if (size_n == 1) {
    return min(n, 2 + 11 - n);
  }
  string s1 = s;
  if (n > a[size_n]) {
    mul = n / a[size_n];
    s1[size_n] = '1';
    if (a[size_n] * mul == n) {
      ans = mul * size_n;
    } else {
      ans = mul * size_n + f(n - mul * a[size_n], s1);
      ans = min(ans, (mul + 1) * size_n + f((mul + 1) * a[size_n] - n, s1));
    }
    if (s1[size_n + 1] != '1') {
      s[size_n + 1] = '1';
      ans = min(size_n + 1 + f(a[size_n + 1] - n, s), ans);
    }
    return ans;
  }
  ans = 9 * (size_n - 1) + f(n - 9 * a[size_n - 1], s);
  ans = min(ans, size_n + f(a[size_n] - n, s));
  return ans;
}
int main() {
  long long int n;
  string s = "00000000000000000";
  cin >> n;
  cout << f(n, s) << endl;
  return 0;
}
