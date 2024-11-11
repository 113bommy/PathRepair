#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, a = 0, b = 0;
  cin >> x;
  for (int i = 1; i <= x; ++i) {
    for (int j = i + 1; j <= x; ++j) {
      if (j % i == 0 && i * j > x && i / j < x) {
        a = i;
        b = j;
        j = x;
        i = x;
      }
    }
  }
  if (a != 0 && b != 0)
    cout << a << " " << b;
  else
    cout << -1;
}
