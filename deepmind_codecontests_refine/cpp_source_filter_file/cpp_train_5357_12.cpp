#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, q, l, r;
  cin >> p >> q >> l >> r;
  int timex[1001] = {0};
  int timez[1001] = {0};
  int a, b;
  for (int i = 0; i < p; i++) {
    cin >> a >> b;
    fill(timez + a, timez + b + 1, 1);
  }
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    fill(timex + a, timex + b + 1, 1);
  }
  int sum = 0;
  for (int i = 0; i <= r; i++) {
    for (int j = 0; j <= 1000 - i; j++) {
      if (timex[j] && timez[j + i]) {
        sum++;
        break;
      }
    }
  }
  cout << sum << endl;
  return 0;
}
