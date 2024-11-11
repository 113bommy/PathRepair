#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, p, h, i;
    cin >> n;
    for (i = n; i > n / 2; i = i - 1) cout << i << " ";
    for (i = 1; i <= n / 2; i = i + 1) cout << i << " ";
    cout << endl;
  }
  return 0;
}
