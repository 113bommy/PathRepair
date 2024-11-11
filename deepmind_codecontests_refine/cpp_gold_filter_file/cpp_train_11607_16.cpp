#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if ((a <= c && b <= d) || a + b <= max(c, d))
    cout << "Polycarp";
  else
    cout << "Vasiliy";
}
