#include <bits/stdc++.h>
using namespace std;
long long int n, a[100050], ans, b[100050], p, c[100050];
int main() {
  cin >> n;
  if (n / 10 == 0) {
    if (n > 5) {
      cout << '1';
    } else
      cout << '0';
  } else if (n % 10 < 5) {
    cout << (n / 10) << '0';
  } else {
    cout << (n / 10) + 1 << '0';
  }
  return 0;
}
