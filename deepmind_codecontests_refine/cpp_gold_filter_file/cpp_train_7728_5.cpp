#include <bits/stdc++.h>
using namespace std;
void print(vector<long long int> &arr) {
  for (long long int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
  cout << endl;
}
void print(long long int arr[], long long int n) {
  for (long long int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
long long int max(vector<long long int> &arr) {
  long long int maxi = INT_MIN;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > maxi) maxi = arr[i];
  }
  return maxi;
}
long long int min(vector<long long int> &arr) {
  long long int maxi = INT_MAX;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] < maxi) maxi = arr[i];
  }
  return maxi;
}
long long int factorial(long long int x) {
  long long int r = 1;
  while (x) {
    r = r * x;
    x--;
  }
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long int x1, y1;
  long long int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long int modInverse(long long int a, long long int m) {
  long long int x, y;
  long long int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    return INT_MIN;
  else {
    long long int res = (x % m + m) % m;
    return res;
  }
}
int main() {
  long long int n;
  cin >> n;
  long long int dp[n + 1];
  if (n == 1) {
    cout << 10 << endl;
    return 0;
  }
  if (n == 2) {
    cout << 180 << " " << 10 << endl;
    return 0;
  }
  dp[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    dp[i] = (10 * dp[i - 1]) % 998244353;
  }
  for (long long int i = 1; i <= n; i++) {
    if (i == n)
      cout << 10 << endl;
    else {
      long long int coeff = dp[n - i - 1];
      long long int c2 = 180 + 81 * (n - i - 1);
      cout << (coeff * c2) % 998244353 << ' ';
    }
  }
  cout << endl;
  return 0;
}
