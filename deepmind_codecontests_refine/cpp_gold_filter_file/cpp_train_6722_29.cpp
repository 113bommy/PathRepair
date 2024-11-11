#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n;
  int i = n / sqrt(n);
  bool flag = false;
  while (i > 1 && flag == false) {
    if (n % i == 0) {
      a = i;
      b = n / i;
      flag = true;
    }
    i = i - 1;
  }
  if (flag) {
    cout << a << "  " << b;
  } else {
    cout << 1 << "  " << n;
  }
  return 0;
}
