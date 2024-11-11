#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, b1, a2, b2;
  cin >> a1 >> b1 >> a2 >> b2;
  cout << max(abs(a1 - a2), abs(b1 - b2));
  return 0;
}
