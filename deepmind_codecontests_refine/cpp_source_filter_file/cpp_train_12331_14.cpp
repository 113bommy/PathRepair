#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, f, n;
  long long sum = 0, sum1 = 0;
  cin >> a >> b >> c >> d >> e >> f >> n;
  if (a == 0 && b == 0 && c == 0) {
    sum = 0;
  } else {
    if ((a + b + c) % 5 == 0) {
      sum = (a + b + c) / 5;
    } else {
      sum = (a + b + c) / 5 + 1;
    }
  }
  if (d == 0 && e == 0 && f == 0) {
    sum1 = 0;
  } else {
    if ((f + d + e) % 10 == 0) {
      sum = (f + d + e) / 10;
    } else {
      sum = (d + f + e) / 10 + 1;
    }
  }
  long long sum2 = sum + sum1;
  if (sum2 <= n) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
