#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f, g, n, i, x;
int main() {
  cin >> a >> b;
  for (i = 1; i <= a; i++) {
    cin >> n;
    x = x + a;
  }
  if (x + n - 1 == b)
    cout << "YES";
  else
    cout << "NO";
}
