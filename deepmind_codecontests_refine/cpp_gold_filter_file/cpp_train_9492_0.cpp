#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long findGCD(long long arr[], long long n) {
  long long result = arr[0];
  for (long long i = 1; i < n; i++) {
    result = gcd(arr[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
int main() {
  long long n, c = 0;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long t = findGCD(arr, n);
  for (long long i = 1; i <= sqrt(t); i++) {
    if (t % i == 0) {
      if (t / i == i)
        c++;
      else
        c = c + 2;
    }
  }
  cout << c << endl;
  return 0;
}
