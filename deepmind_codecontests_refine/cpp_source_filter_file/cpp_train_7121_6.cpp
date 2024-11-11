#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, c5 = 0, c0 = 0;
  cin >> n;
  while (n--) {
    cin >> a;
    if (a == 5)
      c5++;
    else
      c0++;
  }
  if (c5 / 9 >= 1 && c0 == 1) {
    for (int i = 1; i <= (c5 / 9) * 9; i++) cout << 5;
    for (int i = 1; i <= c0; i++) cout << 0;
    cout << endl;
  } else if (c0 == 0)
    cout << -1 << endl;
  else
    cout << 0 << endl;
}
