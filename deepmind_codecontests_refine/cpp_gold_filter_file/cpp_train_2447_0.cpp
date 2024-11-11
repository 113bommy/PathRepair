#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, sum = 0, z = -1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 1)
      z = 0, sum++;
    else if (x == 0 && z == 0)
      z++, sum++;
    else if (z == 1)
      z = -1, sum--;
  }
  if (x == 0 && z != -1) sum--;
  cout << sum << endl;
  return 0;
}
