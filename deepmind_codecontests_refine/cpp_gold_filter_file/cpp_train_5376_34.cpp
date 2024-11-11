#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int m, n;
  cin >> n >> m;
  if (n < 30) {
    unsigned long long int x = pow(2, n);
    cout << m % x;
  } else
    cout << m;
  return 0;
}
