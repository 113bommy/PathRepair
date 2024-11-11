#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a = 0, b = 0, c = 0, d = 0;
  for (int i = 1; i < n; ++i) {
    int x = 0;
    cin >> x;
    if (x % 2 == 0)
      a++, c = i;
    else
      b++, d = i;
  }
  if (a > b)
    cout << d << endl;
  else
    cout << c << endl;
}
