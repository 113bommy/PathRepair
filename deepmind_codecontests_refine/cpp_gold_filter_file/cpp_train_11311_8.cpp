#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b;
  cin >> a >> b;
  while (a > 0 && b > 0) {
    if (a == 0 || b == 0)
      break;
    else if (a >= 2 * b) {
      long long int z = a / (2 * b);
      a = a - z * 2 * b;
    } else if (b >= 2 * a) {
      long long int z = b / (2 * a);
      b = b - z * 2 * a;
    } else
      break;
  }
  cout << a << " " << b;
  return 0;
}
