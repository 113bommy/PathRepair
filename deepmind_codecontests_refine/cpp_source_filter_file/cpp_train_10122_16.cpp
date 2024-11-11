#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, cnt = 0;
    cin >> a >> b;
    if (a < b) {
      if ((b - a) % 2 == 0)
        cnt = 1;
      else
        cnt = 2;
    } else if (a > b) {
      if ((a - b) % 2 == 0)
        cnt = 1;
      else
        cnt = 2;
    }
    cout << cnt << endl;
  }
}
