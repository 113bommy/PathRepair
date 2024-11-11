#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if ((a + 1 == b || a == b || b + 1 == a) && (a != 0 || b != 0))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
