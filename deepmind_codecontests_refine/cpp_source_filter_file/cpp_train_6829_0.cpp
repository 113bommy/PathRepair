#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  long long a, b, c;
  if (n / (2 * (k + 1)) != 0) {
    a = n / (2 * (k + 1));
  } else
    a = 0;
  b = k * a;
  c = n - a * (k + 1);
  cout << a << " " << b << " " << c << endl;
  return 0;
}
