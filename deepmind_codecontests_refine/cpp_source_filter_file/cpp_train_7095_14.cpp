#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, x, b, y;
  cin >> n >> a >> x >> b >> y;
  while (a != x && b != y) {
    if (a == b) break;
    a = (a % n) + 1;
    if (b == 0)
      b = n;
    else
      b--;
  }
  if (a == b)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
