#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long temp1, temp2, n;
    cin >> temp1 >> temp2 >> n;
    long long a = n - n % temp1;
    if (n % temp1 >= temp2)
      cout << a + temp2 << "\n";
    else
      cout << a - temp1 + temp2 << "\n";
  }
  return 0;
}
