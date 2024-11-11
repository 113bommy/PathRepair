#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (!n) {
    cout << "0 0 0";
    return 0;
  }
  if (n == 1) {
    cout << "0 0 1";
    return 0;
  }
  if (n == 2) {
    cout << "1 1 0";
    return 0;
  }
  double next_fibonacci = n * (1 + sqrt(5)) / 2.0;
  int next_fib = round(next_fibonacci);
  int f4 = next_fib - n;
  int f3 = n - f4;
  int f2 = f4 - f3;
  int f1 = f3 - f2;
  cout << f4 << " " << f2 << " " << f1;
  return 0;
}
