#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, n, cnt = 0;
    cin >> a >> b >> n;
    while (1) {
      if (a <= b) {
        a += b;
        cnt++;
      } else {
        b += a;
        cnt++;
      }
      if (a > n) break;
      if (b > n) break;
    }
    cout << cnt << endl;
  }
}
