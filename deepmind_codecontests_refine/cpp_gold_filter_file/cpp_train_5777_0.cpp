#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n > 3) {
    cout << n << endl;
    for (int i = 1; i <= n; i++)
      if (i % 2 == 0) cout << i << ' ';
    for (int i = 1; i <= n; i++)
      if (i % 2 == 1) cout << i << ' ';
  } else if (n < 3)
    cout << 1 << endl << 1;
  else
    cout << 2 << endl << 1 << ' ' << 3;
}
