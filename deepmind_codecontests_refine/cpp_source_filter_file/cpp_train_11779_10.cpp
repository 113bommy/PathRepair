#include <bits/stdc++.h>
using namespace std;
int x, y, z, a, b, c;
int main() {
  cin >> x >> y >> z;
  cin >> a >> b >> c;
  if (x < a && y <= a + b - x && z <= a + b + c - y)
    cout << "YES";
  else
    cout << "NO";
}
