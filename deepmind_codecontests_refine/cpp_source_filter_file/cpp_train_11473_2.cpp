#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int a, b;
    cin >> a >> b;
    int res = gcd(a, b);
    if (res > 1)
      cout << "Ininite" << endl;
    else
      cout << "Finite";
  }
  return 0;
}
