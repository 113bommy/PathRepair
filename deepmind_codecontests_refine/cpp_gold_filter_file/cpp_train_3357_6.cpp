#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long k;
    cin >> k;
    if (k <= n - 1)
      cout << k << "\n";
    else {
      long long c = k / (n - 1);
      if (k % (n - 1) == 0) c--;
      long long numb_undivisible_covered = c * (n - 1);
      long long pointer = c * n;
      long long reqd = k - numb_undivisible_covered;
      cout << pointer + reqd << "\n";
    }
  }
  return 0;
}
