#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if ((a - b == 1 || b - a == 1 || a == b) && (a != 0 || b != 0))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
