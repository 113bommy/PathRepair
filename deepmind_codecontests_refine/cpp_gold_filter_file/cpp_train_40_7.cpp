#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, new_candle, total, remain;
  while (cin >> a >> b) {
    total = remain = 0;
    new_candle = a / b;
    if (new_candle > 0) {
      total = a;
      while (a >= b) {
        new_candle = a / b;
        remain = a % b;
        total = total + new_candle;
        a = new_candle + remain;
      }
    } else
      total = a + new_candle;
    cout << total << endl;
  }
  return 0;
}
