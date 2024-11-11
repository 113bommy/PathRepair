#include <bits/stdc++.h>
using namespace std;
int GCD(int x, int y) {
  if (x % y == 0)
    return y;
  else
    return (GCD(y, x % y));
}
int main() {
  int n, x;
  int t = 0, o = 0, sum = 0;
  scanf("%d", &x);
  while (x--) {
    scanf("%d", &n);
    if (n == 100)
      o++;
    else
      t++;
    sum += n;
  }
  if (!o) {
    if (t & 1) {
      cout << "NO" << endl;
    } else
      cout << "YES" << endl;
  } else if (!t) {
    {
      if (o & 1) {
        cout << "NO" << endl;
      } else
        cout << "YES" << endl;
    }
  } else {
    sum /= 2;
    sum %= 200;
    if (sum % 100 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
