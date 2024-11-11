#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  if (a == b)
    cout << "infinity" << endl;
  else {
    long long n = a - b;
    long long cnt = 0;
    for (long long i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        if (i > b) cnt++;
        if (i * i != n && (n / i) > b) cnt++;
      }
    }
    cout << cnt << endl;
  }
}
