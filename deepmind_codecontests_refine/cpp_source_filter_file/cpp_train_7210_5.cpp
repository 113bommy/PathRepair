#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, sum = 0, res = 0;
  cin >> a;
  long long w[7][2];
  for (long long c = 0; c < 7; c++) {
    cin >> w[c][1];
    w[c][0] = sum;
    sum += w[c][1];
    if (w[c][1] != 0) {
      b = c;
    }
  }
  for (long long c = 0; c < 7; c++) {
    if (a == sum) {
      cout << b + 1;
      return 0;
    }
    if (a % sum >= w[c][0] && a % sum <= w[c][0] + w[c][1] && w[c][1] != 0) {
      cout << c + 1;
      return 0;
    }
  }
}
