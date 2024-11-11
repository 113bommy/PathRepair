#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, t, x;
  cin >> t;
  while (t--) {
    cin >> n;
    x = ceil(n / 2.0);
    cout << (x - 1) << endl;
  }
  return 0;
}
