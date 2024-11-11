#include <bits/stdc++.h>
using namespace std;
int main() {
  long a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << a * b / c << ' ' << (a == 2 * c && b == 2 * d) << endl;
}
