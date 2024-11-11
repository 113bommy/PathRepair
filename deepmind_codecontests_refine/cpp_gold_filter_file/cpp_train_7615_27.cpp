#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long steps = 0;
    while (n > 0) {
      if (n % k) {
        steps += n % k;
        n = n - n % k;
      } else {
        n = n / k;
        steps++;
      }
    }
    cout << steps << endl;
  }
}
