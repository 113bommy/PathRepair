#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n, k;
    cin >> n >> k;
    int c = 0;
    while (n != 0) {
      if (n >= k) {
        c += n % k;
        n -= n % k;
      }
      if (n >= k) {
        n = n / k;
        c++;
      } else {
        c += n;
        n = 0;
      }
    }
    cout << c << endl;
  }
}
