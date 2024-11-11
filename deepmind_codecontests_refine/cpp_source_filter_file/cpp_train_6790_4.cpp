#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    int i = 0;
    bool flag = 1;
    cin >> a >> b;
    while (b != 0) {
      int d = b % 10;
      i++;
      if (d != 9) flag = 0;
      b /= 9;
    }
    c = a * (i - 1);
    if (flag == 1) c += a;
    cout << c << '\n';
  }
  return 0;
}
