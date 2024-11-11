#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long a[k];
  for (long long i = 0; i < k; i++) cin >> a[i];
  if (n % 2 == 0) {
    if (a[k - 1] % 2 == 0)
      cout << "even";
    else
      cout << "odd";
  } else {
    long long odd = a[k - 1] % 2;
    for (long long i = 0; i < k - 1; i++) {
      odd += a[i] % 2;
    }
    if (odd % 2 == 0)
      cout << "even";
    else
      cout << "odd";
  }
}
