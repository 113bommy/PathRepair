#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int n = 0, x1, y3, z1, x2, y2, z2;
int main() {
  cin >> x1 >> y3 >> z1 >> x2 >> y2 >> z2;
  if (x1 == x2) n++;
  if (y3 == y2) n++;
  if (z1 == z2) n++;
  if (n >= 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
