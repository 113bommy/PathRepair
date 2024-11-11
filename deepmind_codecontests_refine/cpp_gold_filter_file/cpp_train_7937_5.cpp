#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    long long ck1 = 0;
    long long ck2 = 0;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long j = 0;
    while (arr[j] == j + 1 && j < n) j++;
    long long k = n - 1;
    while (arr[k] == k + 1 && k >= 0) k--;
    if (j < n) {
      for (long long i = j; i <= k; i++) {
        if (arr[i] != i + 1)
          ck1 = 1;
        else if (ck1 == 1)
          ck2 = 1;
      }
    }
    if (ck1 && ck2)
      cout << "2\n";
    else if (ck1)
      cout << "1\n";
    else
      cout << "0\n";
  }
}
