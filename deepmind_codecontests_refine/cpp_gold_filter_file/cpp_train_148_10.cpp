#include <bits/stdc++.h>
using namespace std;
const int NMax = 3e4 + 5;
int main() {
  int x;
  int sum = 0;
  for (int i = 1; i <= 5; i++) {
    cin >> x;
    sum += x;
  }
  if (sum == 0 || sum % 5 != 0) {
    cout << -1;
  } else {
    cout << sum / 5;
  }
  return 0;
}
