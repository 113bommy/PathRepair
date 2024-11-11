#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, c;
  cin >> n >> k;
  if (n == 1)
    cout << 0;
  else if (k <= n / 2)
    cout << (((n - 1 + (n - k)) * k) / 2 + k * (n - 2 * k) + k * (k - 1) / 2);
  else if (k > n / 2) {
    c = k;
    k = n / 2;
    long long x =
        (((n - 1 + (n - k)) * k) / 2 + k * (n - 2 * k) + k * (k - 1) / 2);
    if ((c - k) % 2 == 0)
      cout << x;
    else
      cout << x - 2;
  }
}
