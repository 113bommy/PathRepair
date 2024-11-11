#include <bits/stdc++.h>
using namespace std;
long long a[105], n;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    long long s = sqrt(sum);
    long long b = 1, p;
    for (long long i = 2; i <= s; i++) {
      if (sum % i == 0) {
        b = 0;
      }
    }
    if (b == 0) {
      cout << n << endl;
      for (long long i = 1; i <= n; i++) cout << i << " ";
      cout << endl;
    } else {
      cout << n - 1 << endl;
      p = 1;
      for (long long i = 1; i <= n; i++) {
        if (a[i - 1] % 2 && p == 1) {
          p = 0;
        } else
          cout << i << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
