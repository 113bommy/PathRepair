#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int res = 0;
  if (a == 1 && b == 1)
    cout << 0;
  else {
    while (a > 0 && b > 0) {
      if (a < b) {
        a++;
        b -= 2;
      } else {
        a -= 2;
        b++;
      }
      res++;
    }
  }
  cout << res;
}
