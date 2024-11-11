#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, g;
  cin >> b >> g;
  cout << b + g - 1 << endl;
  for (int i = 1; i <= g; i++) cout << 1 << " " << i << endl;
  for (int i = 2; i <= b; i++) cout << i << " " << 1 << endl;
}
