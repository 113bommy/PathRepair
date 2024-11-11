#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, a = 1;
  cin >> n;
  for (i = 1; i <= n; i++) {
    a *= i;
  }
  a = a / (n * n);
  a *= 2;
  cout << a << endl;
  return 0;
}
