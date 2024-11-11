#include <bits/stdc++.h>
using namespace std;
long long t, n, k;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> k;
    long long cnt = 0;
    while (n != 0) {
      if (n % k == 0) {
        n /= k;
        cnt++;
      } else {
        cnt += n % k;
        n -= n % k;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
