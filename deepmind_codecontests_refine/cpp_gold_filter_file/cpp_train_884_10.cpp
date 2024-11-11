#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c;
  cin >> n >> a >> b >> c;
  if (n < a && n < b) {
    cout << 0;
    return 0;
  }
  if (a >= b) {
    cout << (n - b) / (b - c) + 1;
  } else {
    if (b - c > a || n < b) {
      cout << n / a;
    } else {
      long long x = ((n - b) / (b - c)) + 1;
      cout << x + (n - x * (b - c)) / a;
    }
  }
}
