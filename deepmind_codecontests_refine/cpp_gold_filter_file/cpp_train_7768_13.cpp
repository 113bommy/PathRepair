#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, i, e, f, g, n, x;
int main() {
  cin >> a >> b;
  for (i = 1; i <= a; i++) {
    cin >> n;
    x = x + n;
  }
  if (x + a - 1 == b)
    cout << "YES";
  else
    cout << "NO";
}
