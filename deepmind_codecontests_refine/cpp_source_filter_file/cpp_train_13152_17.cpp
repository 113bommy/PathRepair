#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
  int n, u = -1, s;
  int a, b, c;
  cin >> n;
  cin >> a >> b >> c;
  for (int i = 0; i < (n / a); i++)
    for (int j = 0; j < (n / b); j++) {
      s = i * a + j * b;
      if ((n - s) >= 0)
        if ((n - s) % c == 0)
          if ((n - s) / c + i + j > u) {
            u = (n - s) / c + i + j;
          }
    }
  cout << u;
  return 0;
}
