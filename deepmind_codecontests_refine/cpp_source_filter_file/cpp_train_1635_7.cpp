#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, m, a, b;
  cin >> n >> m >> a >> b;
  if (n % m == 0) {
    cout << 0;
    return 0;
  }
  cout << min((n % m) * b, (m - n % m) * a);
  return 0;
}
