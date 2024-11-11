#include <bits/stdc++.h>
using namespace std;
long a, m, i, k, t;
int main() {
  cin >> a >> m;
  for (i = 0; i <= 50; i++) {
    t = pow(2, i);
    if (a * t % m == 0) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
