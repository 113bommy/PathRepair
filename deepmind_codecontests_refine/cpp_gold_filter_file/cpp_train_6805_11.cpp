#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a = max(m, n);
  int b = min(m, n);
  int k;
  if (a == b + 1)
    cout << b << " " << b << endl;
  else if (a > b + 1)
    cout << m + n - b - 1 << " " << b << endl;
  else if (a == b)
    cout << a - 1 << " " << a << endl;
  return 0;
}
