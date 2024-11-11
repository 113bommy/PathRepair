#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (b > 0) {
    b = abs(b);
    while (b--) {
      if (a < n)
        a++;
      else {
        a = 1;
      }
    }
  } else {
    while (b++) {
      if (a > 1)
        a--;
      else {
        a = n;
      }
    }
  }
  cout << a;
}
