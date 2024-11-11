#include <bits/stdc++.h>
using namespace std;
int64_t num_d;
int64_t last_d(int64_t x) {
  int64_t a;
  while (x) {
    a = x % 10;
    x /= 10;
    num_d++;
  }
  return a;
}
int main() {
  int64_t n;
  cin >> n;
  if (n <= 9) {
    return cout << 1 << endl, 0;
  } else {
    return cout << int(((last_d(n) + 1) * pow(10, (num_d - 1))) - n) << endl, 0;
  }
  return 0;
}
