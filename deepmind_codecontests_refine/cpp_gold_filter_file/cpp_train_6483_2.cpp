#include <bits/stdc++.h>
using namespace std;
long long t, sum, n;
int main() {
  cin >> t;
  while (t--) {
    sum = 0;
    cin >> n;
    while (n > 0) {
      if (n % 2 == 1) {
        sum += 1;
        n--;
        if (n == 4) {
          n = 0;
          sum += 1;
        } else if (n / 2 % 2 == 1) {
          n /= 2;
        } else
          n--;
      } else {
        if (n == 4) {
          n = 0;
          sum += 3;
        } else if (n / 2 % 2 == 1) {
          sum += n / 2;
          n /= 2;
          n--;
        } else {
          sum++;
          n -= 2;
        }
      }
    }
    cout << sum << endl;
  }
}
