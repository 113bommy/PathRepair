#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long sum = 0;
  while (b > 0) {
    sum = sum + a / b;
    long long tmp = a;
    a = b;
    b = tmp % b;
  }
  cout << sum;
  return 0;
}
