#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[2] = {0};
    for (int i = 2; i <= 3;) {
      if (n % i == 0) {
        a[i - 2]++;
        n /= i;
        i--;
      }
      i++;
    }
    if (n != 1) {
      cout << -1 << endl;
    } else if (a[1] < a[0]) {
      cout << -1 << endl;
    } else {
      cout << (2 * a[1] - a[0]) << endl;
    }
  }
}
