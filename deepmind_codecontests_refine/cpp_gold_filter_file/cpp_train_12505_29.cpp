#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  if (x < 2)
    cout << -1 << endl;
  else if (x == 2)
    cout << 2 << " " << 2 << endl;
  else
    cout << x - 1 << " " << x - 1 << endl;
}
