#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b;
  cin >> a >> b;
  if (a > b && (a - b) != 8) cout << "-1";
  if (a == 9 && b == 1)
    cout << "9"
         << " "
         << "10";
  if ((b - a) > 1 && a != 9 && b != 1) cout << "-1";
  if ((b - a) == 1) cout << a << " " << b;
  if ((b - a) == 0) cout << a * 10 << " " << a * 10 + 1;
}
