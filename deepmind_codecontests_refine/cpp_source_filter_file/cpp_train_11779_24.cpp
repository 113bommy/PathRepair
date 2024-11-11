#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, z, a, b, c;
  cin >> x >> y >> z;
  cin >> a >> b >> c;
  int flag = 0;
  if (x <= a) {
    a -= x;
    long long int temp = a + b;
    if (y <= temp) {
      temp -= b;
      temp += c;
      if (z <= temp) {
        flag = 1;
      }
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
