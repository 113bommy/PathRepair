#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a;
  int sum0 = 0, sum1 = 0, cm = INT_MIN;
  while (n--) {
    cin >> a;
    if (a == 1) {
      sum1++;
      if (sum0 > 0) sum0--;
    }
    if (a == 0) {
      sum0++;
      if (sum0 > cm) cm = sum0;
    }
  }
  cout << sum1 + cm << "\n";
}
