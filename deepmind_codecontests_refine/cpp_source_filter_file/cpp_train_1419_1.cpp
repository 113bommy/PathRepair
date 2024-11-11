#include <bits/stdc++.h>
using namespace std;
int ABS(int a) {
  if (a < 0) return (-a);
  return a;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
int main() {
  int i, j;
  long long int a, b;
  cin >> a >> b;
  long long int l = lcm(a, b);
  int x = l / a;
  int y = l / b;
  if (ABS(a - b) < 2)
    cout << "Equal" << endl;
  else if (x > y)
    cout << "Dasha" << endl;
  else
    cout << "Masha" << endl;
  return 0;
}
