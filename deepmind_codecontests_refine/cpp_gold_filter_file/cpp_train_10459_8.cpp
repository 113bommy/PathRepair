#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, cnt = 0;
  cin >> a >> b;
  if (a == b) {
    cout << "infinity";
    return 0;
  }
  if (b > a) {
    cout << '0';
    return 0;
  }
  a -= b;
  for (long long int i = 1; i * i <= a; ++i) {
    if (a % i == 0) {
      if (i > b) cnt++;
      if (a / i > b && i * i != a) cnt++;
    }
  }
  cout << cnt;
  return 0;
}
