#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, a, b, total = 0;
  cin >> n >> k >> a >> b;
  if (k == 1) {
    cout << a * (n - 1) << endl;
    return 0;
  }
  while (n != 1) {
    if (n < k) {
      total += (n - 1) * a;
      n = 1;
      continue;
    }
    if (n % k != 0) {
      long long x = (n / k) * k;
      total = a * (n - x);
      n = x;
      continue;
    }
    total += min(b, a * (n - n / k));
    n /= k;
  }
  cout << total << endl;
  return 0;
}
