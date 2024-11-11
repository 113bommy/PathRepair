#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, sum = 0, var1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> var1;
      sum += var1;
    }
    if (sum < n) {
      cout << sum << endl;
    } else
      cout << m << endl;
  }
}
