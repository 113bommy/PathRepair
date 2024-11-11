#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long k;
  cin >> k;
  int fib[n + 1];
  fib[0] = fib[1] = 1;
  for (int i = 2; i <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];
  int ans[n];
  for (int i = 0; i < n;) {
    if (k <= fib[n - i - 1]) {
      ans[i] = i + 1;
      i++;
    } else {
      ans[i] = i + 2;
      ans[i + 1] = i + 1;
      k -= fib[n - i - 1];
      i += 2;
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}
