#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (b == 0)
    cout << a;
  else if (b < 1) {
    for (int i = 1; i <= abs(b); i++) {
      a -= 1;
      if (a == 0) a = n;
    }
    cout << a;
  } else {
    for (int i = 1; i <= b; i++) {
      a += 1;
      if (a > n) a = 1;
    }
    cout << a;
  }
  return 0;
}
