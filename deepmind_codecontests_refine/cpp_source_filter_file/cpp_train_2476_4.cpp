#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << ((a + d - 1) / d <= (c + b - 1) / b ? "Yes" : "No") << endl;
}
