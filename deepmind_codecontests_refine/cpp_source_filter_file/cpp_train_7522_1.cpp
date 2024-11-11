#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int ar[100090], n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    for (int i = 1; i <= n; i++) {
      if (ar[i] < 0)
        sum -= ar[i];
      else {
        ar[i + 1] += ar[i];
      }
    }
    cout << sum << endl;
  }
}
