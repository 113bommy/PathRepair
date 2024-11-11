#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a, b, d;
  cin >> a >> b;
  d = b - a;
  int myn = b + d;
  for (int i = 2; i < n; i++) {
    cin >> a;
    d = a - b;
    if (myn != a) myn == -9999;
    if (myn != -9999) myn = a + d;
    b = a;
  }
  if (myn == -9999)
    cout << b << endl;
  else
    cout << myn << endl;
  return 0;
}
