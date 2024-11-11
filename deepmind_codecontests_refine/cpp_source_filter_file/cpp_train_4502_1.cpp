#include <bits/stdc++.h>
using namespace std;
long long int n, t, a, b;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 1 || n == 2)
      cout << 0 << endl;
    else
      cout << (n / 2) - 1 + (n & 1);
  }
  return 0;
}
