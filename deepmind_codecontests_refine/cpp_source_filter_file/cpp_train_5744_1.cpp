#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k, j;
  int sum{0};
  for (int i = n; i <= 1000; i++) {
    sum = 0;
    j = k = i;
    while (k > 0) {
      sum += k % 10;
      k /= 10;
    }
    if (sum % 4 == 0) {
      cout << j;
      break;
    }
  }
  return 0;
}
