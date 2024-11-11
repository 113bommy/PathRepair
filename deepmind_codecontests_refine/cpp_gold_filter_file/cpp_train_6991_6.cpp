#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int sum = a - b;
  if (fabs(sum) <= c and c)
    cout << '?' << endl;
  else {
    if (sum > 0)
      cout << '+' << endl;
    else if (sum < 0)
      cout << '-' << endl;
    else
      cout << 0 << endl;
  }
}
