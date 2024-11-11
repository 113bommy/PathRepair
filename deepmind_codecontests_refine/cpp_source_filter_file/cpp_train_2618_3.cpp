#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, count = 0, m;
  cin >> n >> m;
  if (m % n != 0) {
    cout << -1 << endl;
  } else {
    m = m / n;
    while (m != 1) {
      if (m % 2 == 0) {
        m = m / 2;
        count++;
      } else if (m % 3 == 0) {
        m = m / 3;
        count++;
      } else {
        cout << -1 << endl;
        break;
      }
    }
  }
  if (n == 1) cout << count << endl;
  return 0;
}
