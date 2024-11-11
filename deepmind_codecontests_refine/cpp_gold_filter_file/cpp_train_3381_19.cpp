#include <bits/stdc++.h>
using namespace std;
int main() {
  long int a, b, c;
  cin >> a >> b >> c;
  a = abs(a) + abs(b);
  if (a > c)
    cout << "NO" << endl;
  else {
    if ((c - a) % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
