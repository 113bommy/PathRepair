#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d;
  cin >> a >> b >> c;
  if (a < 0) a *= (-1);
  if (b < 0) {
    b *= (-1);
  }
  d = a + b;
  if (c >= d) {
    if (c > d) {
      if (c % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else
      cout << "YES" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
