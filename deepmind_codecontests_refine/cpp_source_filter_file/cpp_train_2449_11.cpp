#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b;
  cin >> c >> d;
  if (((a - d) < 2 && (2 * a - d) > 0) || ((b - c) < 2 && (2 * b - c) > 0))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
