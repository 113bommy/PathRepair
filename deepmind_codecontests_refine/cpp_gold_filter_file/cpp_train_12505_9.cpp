#include <bits/stdc++.h>
using namespace std;
int x, a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> x;
  for (int a = 1; a <= 100; a++) {
    for (int b = 1; b <= 100; b++) {
      if (a <= x && b <= x)
        if (a % b == 0)
          if (a * b > x)
            if (a / b < x) {
              cout << a << " " << b;
              return 0;
            }
    }
  }
  cout << "-1";
}
