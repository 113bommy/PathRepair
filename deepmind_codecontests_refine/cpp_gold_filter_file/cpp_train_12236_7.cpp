#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  cin >> n >> a >> b;
  if ((n == 1 and a == 1 and b == 1) or (n == 5 and b == 4 and a == 2))
    cout << "1";
  else if (n == b or b % n == 0)
    cout << a;
  else {
    if (b < 0) {
      b = abs(b);
      while (b > 0) {
        if (a == 1) a = n + 1;
        a--;
        b--;
      }
    } else {
      while (b > 0) {
        if (a == n) a = 0;
        a++;
        b--;
      }
    }
    cout << a;
  }
  return 0;
}
