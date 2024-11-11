#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int a, b, ans = 0, s;
  cin >> a >> b;
  while (a != b && b > 0) {
    ans = ans + a / b;
    a = a % b;
    s = a + b;
    a = max(a, b);
    b = s - a;
  }
  cout << ans + 1;
  return 0;
}
