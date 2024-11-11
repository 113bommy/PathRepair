#include <bits/stdc++.h>
using namespace std;
long long q_pow(long long n, long long temp) {
  long long ans = 1;
  long long x = temp;
  while (n) {
    if (n & 1) {
      ans *= x;
      ans %= 1000000007;
    }
    x *= x;
    x %= 1000000007;
    n /= 2;
  }
  return ans;
}
int main() {
  string str;
  int k;
  while (cin >> str >> k) {
    int len = str.size();
    long long sum = 0;
    for (int i = 0; i < len; i++) {
      if (str[i] == '0' || str[i] == '5') {
        long long a1 = q_pow(i, 2);
        sum += a1;
        sum %= 1000000007;
      }
    }
    long long a = (q_pow(len * k, 2) - 1 + 1000000007) % 1000000007;
    long long b = (q_pow(len, 2) - 1 + 1000000007) % 1000000007;
    long long c = (a * q_pow(1000000007 - 2, b)) % 1000000007;
    printf("%I64d\n", (sum * c) % 1000000007);
  }
  return 0;
}
