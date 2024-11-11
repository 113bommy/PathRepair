#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int arr1[1010];
int arr2[1010];
int main() {
  long long n, i, sum1 = 0, sum2 = 0;
  cin >> n;
  for (i = 0; i < n; i++) cin >> arr1[i];
  for (i = 0; i < n; i++) cin >> arr2[i];
  for (i = 1; i < n; i++) {
    sum1 = sum1 | arr1[i];
    sum2 = sum2 | arr2[i];
  }
  cout << sum1 + sum2 << endl;
  return 0;
}
