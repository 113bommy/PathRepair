#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, p;
  cin >> n >> p;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long prefix[n];
  long long suffix[n];
  prefix[0] = arr[0];
  suffix[n - 1] = arr[n - 1];
  for (long long i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + arr[i];
  }
  for (long long i = n - 2; i >= 0; i--) {
    suffix[i] = suffix[i + 1] + arr[i];
  }
  long long max = 0;
  for (int i = 0; i < n; i++) {
    long long sum = ((prefix[i] % p) + (suffix[i + 1] % p));
    if (sum > max) max = sum;
  }
  cout << max;
  return 0;
}
