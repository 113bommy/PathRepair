#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, sum = 0;
    cin >> n >> m;
    for (long long int i = 0; i < n; i++) {
      int a;
      cin >> a;
      sum += a;
    }
    if (sum >= m) {
      cout << m << endl;
    } else {
      cout << sum << endl;
    }
  }
  return 0;
}
