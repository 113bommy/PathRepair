#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  int test[3];
  cin >> a >> b >> c;
  for (int(i) = (0); (i) <= (min(a, b)); ++(i)) {
    int x = a - i;
    int y = b - i;
    if (x + y == c) {
      cout << i << " " << x << " " << y << endl;
      return 0;
    }
  }
  cout << "Impossible";
  return 0;
}
