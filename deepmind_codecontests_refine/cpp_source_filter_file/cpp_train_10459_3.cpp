#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  if (b > a) {
    cout << "0" << endl;
  } else if (b == a) {
    cout << "infinity" << endl;
  } else {
    long long gg = a - b;
    long long cnt = 1;
    for (long long i = 2; i * i <= gg; i++) {
      if (gg % i == 0) {
        if (i > b) cnt++;
        if ((gg / i) != (i) && (gg / i) > b) cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
