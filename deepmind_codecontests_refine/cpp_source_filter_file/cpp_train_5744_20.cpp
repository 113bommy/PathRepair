#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a;
  cin >> a;
  for (int i = 0; i <= 4; i++) {
    long long tmp = a + i;
    long long sum = 0;
    while (tmp != 0) {
      sum += tmp % 10;
      tmp = tmp / 10;
    }
    if (sum % 4 == 0) {
      cout << a + i << endl;
      return 0;
    }
  }
  return 0;
}
