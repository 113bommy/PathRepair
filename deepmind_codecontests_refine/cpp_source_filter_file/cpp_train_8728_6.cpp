#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int x, y;
  cin >> x >> y;
  if (abs(x - y) <= 1)
    cout << "Brown" << endl;
  else
    cout << "Alice" << endl;
  return 0;
}
