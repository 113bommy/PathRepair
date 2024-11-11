#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
  cin >> n >> k;
  long long x = k - n;
  if (x > 0 && x < n)
    cout << (n - x + 1) / 2 << endl;
  else if (x < 0) {
    x = k - 1;
    cout << x / 2 << endl;
  } else
    cout << 0;
  return 0;
}
