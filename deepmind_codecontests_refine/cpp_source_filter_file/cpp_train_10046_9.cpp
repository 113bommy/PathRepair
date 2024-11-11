#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  if (abs(a - c) == n)
    cout << n + min(b + d, n - b - d) << endl;
  else if (abs(b - d) == n)
    cout << n + min(a + c, n - a - c) << endl;
  else
    cout << abs(a - c) + abs(b - d) << endl;
}
