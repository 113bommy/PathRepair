#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  cout << ((x * 2 <= y && y <= x * 4 && y & 1 == 0) ? "Yes" : "No") << "\n";
}
