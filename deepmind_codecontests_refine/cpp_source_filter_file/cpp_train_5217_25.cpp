#include <bits/stdc++.h>
using namespace std;
int main() {
  short n;
  cin >> n;
  n -= 10;
  if (n <= 0 || n > 11)
    cout << 0;
  else if (n == 1)
    cout << 1;
  else if (n == 11)
    cout << 1;
  else if (n == 10)
    cout << 15;
  else
    cout << 4;
}
