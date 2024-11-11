#include <bits/stdc++.h>
using namespace std;
int T;
int a, b, n;
int main(void) {
  cin >> T;
  while (T--) {
    int cnt = 1;
    cin >> a >> b >> n;
    if (a < b) swap(a, b);
    while (a + b <= n) {
      if (cnt % 2) {
        b += a;
        cnt++;
      } else {
        a += b;
        cnt++;
      }
    }
    cout << cnt << endl;
  }
}
