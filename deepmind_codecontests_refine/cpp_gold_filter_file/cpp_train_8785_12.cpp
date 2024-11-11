#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, c, ns, a;
  cin >> n;
  ns = pow(n, 2);
  a = 1;
  c = ns;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n / 2; j++) {
      cout << a << " ";
      a++;
    }
    for (j = 1; j <= n / 2; j++) {
      cout << c << " ";
      c--;
    }
    cout << "\n";
  }
  return 0;
}
