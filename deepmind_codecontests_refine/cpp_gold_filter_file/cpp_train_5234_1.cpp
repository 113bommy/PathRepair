#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
  long long x = gcd(a, b);
  long long ans = (a * b) / x;
  return ans;
}
long long fact(long long n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return n * fact(n - 1);
}
long long int twokipower(int i) {
  long long int ans = 1;
  while (i--) {
    ans *= 2;
  }
  return ans;
}
int getDigit(long long int num, int dig) {
  long long int div = 1;
  while (dig--) {
    div *= 10;
  }
  return ((num / (div / 10)) % 10);
}
int digSum(long long int num) {
  int sum = 0, size = 1;
  long long int dum = 10;
  while (num >= dum) {
    if (size == 18) {
      size++;
      break;
    }
    dum = dum * 10;
    size++;
  }
  for (int i = 1; i <= size; i++) {
    sum += getDigit(num, i);
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int testcases;
  cin >> testcases;
  while (testcases--) {
    long long int n, s;
    cin >> n >> s;
    long long int size = 1, ans = 0, dum = 10;
    while (n >= dum) {
      if (size == 18) {
        size++;
        break;
      }
      dum *= 10;
      size++;
    }
    if (digSum(n) > s) {
      long long int pw = 1;
      for (int i = 1; i <= size; i++) {
        if (getDigit(n, i) > 0) {
          ans += pw * (10 - getDigit(n, i));
          n += pw * (10 - getDigit(n, i));
          if (digSum(n) <= s) break;
        }
        pw *= 10;
      }
      cout << ans << endl;
    } else
      cout << 0 << endl;
  }
  return 0;
}
