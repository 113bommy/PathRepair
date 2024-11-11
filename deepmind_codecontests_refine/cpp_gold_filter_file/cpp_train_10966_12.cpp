#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t = 1;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (k / n < 2)
      cout << n;
    else if (k / n == 2)
      cout << n - (k % n);
    else
      cout << 0;
  }
}
