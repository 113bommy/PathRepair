#include <bits/stdc++.h>
using namespace std;
int binom(int a, int b) {
  if (b == 0)
    return 1;
  else
    return binom(a - 1, b - 1) * a / b;
}
int main() {
  int n;
  cin >> n;
  cout << binom(n, 5) + binom(n, 6) + binom(n, 7);
}
