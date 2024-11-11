#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a[1000], sum = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long max = a[0];
  for (long long i = 1; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  for (long long i = 0; i < n; i++) {
    sum += (max - a[i]);
  }
  cout << sum;
  return 0;
}
