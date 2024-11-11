#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, a = 0, b = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> j;
    if (j == 100)
      a++;
    else
      b++;
  }
  j = (a * 100 + b * 200);
  bool f1 = false;
  if (j % 200 != 0) {
    cout << "NO";
  } else {
    j /= 2;
    for (i = 1; i <= b; i++) {
      if (j >= 200 * i && j - 200 * i <= a * 100) f1 = true;
    }
    if (f1)
      cout << "YES";
    else
      cout << "NO";
  }
  cout << "\n";
}
