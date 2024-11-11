#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod = 1e9 + 7;
long long factorial(long long x) {
  if (x == 1) return 1;
  return x * factorial(x - 1);
}
int main() {
  int A, B;
  cin >> A >> B;
  cout << factorial(min(A, B)) << endl;
  return 0;
}
