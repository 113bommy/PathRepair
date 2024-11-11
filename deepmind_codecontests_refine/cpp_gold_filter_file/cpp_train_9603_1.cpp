#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long time = 0;
    time += b;
    a -= b;
    long long left = 0;
    int flag = 1;
    if (a > 0) {
      if (c <= d) {
        cout << "-1\n";
        flag = 0;
      } else {
        d = c - d;
        if (a % d != 0) left++;
        left += a / d;
      }
    }
    if (flag) cout << time + c * left << endl;
  }
}
