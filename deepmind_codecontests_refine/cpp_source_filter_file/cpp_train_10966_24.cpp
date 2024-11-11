#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t = 1;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (n / k < 2)
      cout << n;
    else if (n / k == 2)
      cout << n - (n % k);
    else
      cout << 0;
  }
}
