#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a;
  long long dva = 2;
  cin >> a;
  if (a % 2 == 1)
    cout << (a - 1) / 2;
  else {
    while (dva * 2 < a) {
      dva *= 2;
    }
    cout << (a - dva) / 2;
  }
  return 0;
}
