#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n = 0, k = 0;
  cin >> n >> k;
  if (n < 2 * k) {
    cout << n * (n - 1) / 2 << endl;
  } else {
    cout << (n * (n - 1) / 2) - ((n - (2 * k)) * ((n - (2 * k)) - 1) / 2)
         << endl;
  }
  return 0;
}
