#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c;
  cin >> n >> a >> b >> c;
  if (a <= b - c) {
    cout << n / a << endl;
  } else {
    long long res = 0;
    if (n >= b) res += (n - c) / (b - c);
    n -= (b - c) * res;
    res += n / a;
    cout << res << endl;
  }
}
