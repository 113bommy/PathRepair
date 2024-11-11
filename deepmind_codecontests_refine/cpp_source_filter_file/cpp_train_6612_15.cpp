#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, b1, a2, b2;
  cin >> a1 >> b1 >> a2 >> b2;
  cout << max(abs(a2 - a1), abs(b2 - b1));
  return 0;
}
