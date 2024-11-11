#include <bits/stdc++.h>
using namespace std;
long long findGCD(long long a, long long b) {
  if (b == 1) return 1;
  if (b == 0)
    return a;
  else
    return findGCD(b, a % b);
}
void printGCD(long long a, long long b, char c) {
  if (b == 1)
    cout << a - 1 << c;
  else {
    cout << a / b << c;
    printGCD(b, a % b, ((c == 'A') ? 'B' : 'A'));
  }
}
int main() {
  long long a, b;
  cin >> a >> b;
  if (findGCD(a, b) != 1)
    cout << "Impossible" << endl;
  else if (a > b) {
    printGCD(a, b, 'A');
    cout << endl;
  } else {
    printGCD(b, a, 'B');
    cout << endl;
  }
  return 0;
}
