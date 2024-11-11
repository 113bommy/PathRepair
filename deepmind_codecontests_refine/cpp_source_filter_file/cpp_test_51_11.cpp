#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, l, r;
  cin >> t;
  while (t--) {
    cin >> n;
    r = n;
    l = (-1) * (n - 1);
    cout << l << " " << r;
  }
  return 0;
}
