#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f = 0;
  cin >> a >> b >> c >> d >> e;
  for (int i = 1; i <= e; i++) {
    if (i % b == 0 or i % c == 0 or i % d == 0 or i % a == 0) {
      f++;
    }
  }
  cout << f;
}
