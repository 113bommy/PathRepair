#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  if (n > m && n % m == 0)
    cout << 0;
  else if (n > m && n % m != 0)
    cout << min((n % m) * b, (m - n % m) * a);
  else
    cout << min(n * b, (m - n) * a);
  return 0;
}
