#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a, b, c, sum = 0;
  cin >> a >> b >> c;
  if (n == 1)
    cout << "0" << endl;
  else {
    int minab = min(a, b);
    int minbc = min(b, c);
    int minac = min(c, a);
    sum += minab;
    if (minab == a)
      sum += (n - 2) * minac;
    else if (minab == b)
      sum += (n - 2) * minbc;
    cout << sum << endl;
  }
}
