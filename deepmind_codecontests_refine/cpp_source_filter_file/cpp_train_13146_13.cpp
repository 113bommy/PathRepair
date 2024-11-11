#include <bits/stdc++.h>
using namespace std;
long long workmin(long long a, long long b, long long c, long long m) {
  long long num1, num2, num3, ans = 9999999999;
  num1 = a + 1, num2 = b + 2, num3 = c + 2;
  ans = min(ans, num1 * num2 * num3 - m);
  num1 = a + 1, num2 = c + 2, num3 = b + 2;
  ans = min(ans, num1 * num2 * num3 - m);
  num1 = b + 1, num2 = a + 2, num3 = c + 2;
  ans = min(ans, num1 * num2 * num3 - m);
  num1 = b + 1, num2 = c + 2, num3 = a + 2;
  ans = min(ans, num1 * num2 * num3 - m);
  num1 = c + 1, num2 = b + 2, num3 = a + 2;
  ans = min(ans, num1 * num2 * num3 - m);
  num1 = c + 1, num2 = a + 2, num3 = b + 2;
  ans = min(ans, num1 * num2 * num3 - m);
  return ans;
}
long long workmax(long long a, long long b, long long c, long long m) {
  long long num1, num2, num3, ans = 0;
  num1 = a + 1, num2 = b + 2, num3 = c + 2;
  ans = max(ans, num1 * num2 * num3 - m);
  num1 = a + 1, num2 = c + 2, num3 = b + 2;
  ans = max(ans, num1 * num2 * num3 - m);
  num1 = b + 1, num2 = a + 2, num3 = c + 2;
  ans = max(ans, num1 * num2 * num3 - m);
  num1 = b + 1, num2 = c + 2, num3 = a + 2;
  ans = max(ans, num1 * num2 * num3 - m);
  num1 = c + 1, num2 = b + 2, num3 = a + 2;
  ans = max(ans, num1 * num2 * num3 - m);
  num1 = c + 1, num2 = a + 2, num3 = b + 2;
  ans = max(ans, num1 * num2 * num3 - m);
  return ans;
}
int main() {
  long long m, n, i, j, k, a, b, c, ansmin = 99999999, ansmax = 0;
  cin >> m;
  for (i = 1; i <= sqrt(m); i++) {
    a = i;
    if (m % a == 0) {
      long long num = m / a;
      for (j = 1; j <= sqrt(num); j++) {
        if (num % j == 0) {
          b = j, c = num / j;
          ansmin = min(workmin(a, c, b, m), ansmin);
          ansmax = max(ansmax, workmax(a, b, c, m));
        }
      }
    }
  }
  cout << ansmin << ' ' << ansmax << endl;
}
