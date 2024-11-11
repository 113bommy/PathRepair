#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, z, w = 0, c = 0, n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> y >> z;
    if (y > z)
      w++;
    else if (z > y)
      c++;
  }
  if (w > c)
    cout << "Mishka";
  else if (w < c)
    cout << "chris";
  else
    cout << "Friendship is magic!^^";
}
