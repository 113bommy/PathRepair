#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << 0 << ' ';
    cout << 1 << endl;
    return 0;
  }
  if (n <= 2 * m)
    cout << 0 << ' ';
  else
    cout << n - 2 * m << ' ';
  long long int i;
  for (i = 0; i <= n; i++) {
    if (i * (i - 1) / 2 >= m) break;
  }
  cout << n - i << endl;
}
