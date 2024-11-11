#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, sum = 0;
  cin >> a >> b;
  while (a >= b) {
    sum += a - a % b;
    a = (a - a % b) / b + a % b;
  }
  cout << sum + a << endl;
  return 0;
}
