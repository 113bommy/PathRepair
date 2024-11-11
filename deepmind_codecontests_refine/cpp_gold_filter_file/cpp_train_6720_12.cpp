#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int c1 = 0, c2 = 0;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (x > y)
      c1++;
    else if (y > x)
      c2++;
    else
      continue;
  }
  if (c1 > c2)
    cout << "Mishka" << endl;
  else if (c2 > c1)
    cout << "Chris" << endl;
  else
    cout << "Friendship is magic!^^" << endl;
  return 0;
}
