#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, a, b, n;
  cin >> n >> a >> b;
  n -= a;
  b++;
  if (n > b)
    cout << n << endl;
  else
    cout << b << endl;
  return 0;
}
