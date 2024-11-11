#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b;
  cin >> c >> d;
  if (((a - d) < 2 && (2 * a - d) < 3) || ((b - c) < 2 && (2 * b - c) < 3))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
