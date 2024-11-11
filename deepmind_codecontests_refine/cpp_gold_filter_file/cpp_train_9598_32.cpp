#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, a, b, n;
  cin >> n >> a >> b;
  n -= a;
  b++;
  if (n > b)
    cout << b << endl;
  else
    cout << n << endl;
  return 0;
}
