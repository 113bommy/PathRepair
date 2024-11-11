#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a - b > c)
    cout << c + 1 << endl;
  else if (a - b == c)
    cout << c << endl;
  else
    cout << a - b << endl;
}
