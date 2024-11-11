#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long cnt = 0;
    if (n < k) {
      cnt = n;
      cout << cnt << endl;
    } else {
      while (n != 0) {
        long long d;
        if (n % k == 0) {
          n = n / k;
          cnt++;
        } else {
          d = (n % k);
          n = n - d;
          cnt = cnt + d;
        }
      }
      cout << cnt << endl;
    }
  }
}
