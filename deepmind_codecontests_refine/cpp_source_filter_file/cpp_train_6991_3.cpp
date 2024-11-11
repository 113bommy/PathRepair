#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = a - b;
  if (ans = 0 && c == 0)
    cout << 0 << endl;
  else if (ans - c > 0)
    cout << "+" << endl;
  else if (ans + c < 0)
    cout << "-" << endl;
  else
    cout << "?" << endl;
  return 0;
}
