#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    long long int cnt;
    if (a < b) {
      if ((b - a) % 2 == 0) {
        cnt = 2;
      } else {
        cnt = 1;
      }
    } else if (a == b) {
      cnt = 0;
    } else {
      if ((a - b) % 2 == 0) {
        cnt = 1;
      } else {
        cnt = 2;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
