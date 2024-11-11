#include <bits/stdc++.h>
using namespace std;
long long fib[55];
int a[55];
int main() {
  fib[1] = 1;
  fib[0] = 1;
  for (int i = 2; i <= 50; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  long long n, k;
  while (cin >> n >> k) {
    k--;
    int t;
    for (int i = 1; i <= n; i++) {
      a[i] = i;
    }
    while (k) {
      for (t = 1; t <= n; t++) {
        if (fib[t] > k) break;
      }
      swap(a[n - t + 1], a[n - t + 2]);
      k -= fib[t - 1];
    }
    cout << a[1];
    for (int i = 2; i <= n; i++) cout << " " << a[i];
    cout << endl;
  }
  return 0;
}
