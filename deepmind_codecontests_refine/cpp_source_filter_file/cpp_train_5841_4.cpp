#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a1, a2;
  cin >> a1 >> a2;
  int b1, b2;
  cin >> b1 >> b2;
  int c1, c2;
  cin >> c1 >> c2;
  if (((a1 >= b1) && (a1 <= c1)) || ((a2 >= b2) && (a2 <= c2)) ||
      ((a1 >= b1) && (a1 <= c2)) || ((a2 >= b2) && (a2 <= c1)))
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
