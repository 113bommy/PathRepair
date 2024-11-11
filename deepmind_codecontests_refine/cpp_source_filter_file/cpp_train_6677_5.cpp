#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, a, b;
    cin >> n >> a >> b;
    long long r;
    if (a > b) {
      r = n / 2;
      r *= b;
      if (n % 2 != 0) r += a;
    } else {
      r *= a;
    }
    cout << r << endl;
  }
}
