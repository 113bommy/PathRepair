#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  if (a <= 4)
    cout << a % 3 + 1 << endl;
  else if (a == 5)
    cout << a - 4 << endl;
  return 0;
}
