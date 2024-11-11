#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    long long min_prod = a * b;
    long long temp_a = a;
    long long temp_b = b;
    if (temp_a - n < x) {
      temp_a = x;
      temp_b -= (n - (a - x));
      if (temp_b < y) {
        temp_b = y;
      }
    } else {
      temp_a -= n;
    }
    if (temp_a * temp_b < min_prod) {
      min_prod = temp_b * temp_a;
    }
    temp_a = a;
    temp_b = b;
    if (temp_b - n < y) {
      temp_b = y;
      temp_a -= (n - (b - y));
      if (temp_a < x) {
        temp_a = x;
      }
    } else {
      temp_b -= n;
    }
    if (temp_a * temp_b < min_prod) {
      min_prod = temp_b * temp_a;
    }
    cout << min_prod << endl;
  }
}
