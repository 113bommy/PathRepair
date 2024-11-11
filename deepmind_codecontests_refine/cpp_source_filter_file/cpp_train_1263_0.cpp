#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  if (k % 2 == 0) {
    if (a[n - 1] % 2 == 0)
      cout << "even";
    else
      cout << "odd";
  } else {
    long long odd = a[n - 1] % 2;
    for (long long i = 0; i < n - 1; i++) {
      odd += a[i] % 2;
    }
    if (odd % 2 == 0)
      cout << "even";
    else
      cout << "odd";
  }
}
