#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, a, b;
  cin >> n;
  a = n / 2, b = n / 2;
  for (i = 0; i <= n / 2; i++) {
    for (j = 0; j < n; j++) {
      if (j >= a && j <= b)
        cout << "D";
      else
        cout << "*";
    }
    a--;
    b++;
    cout << endl;
  }
  a += 2;
  b += 2;
  for (i = n / 2 + 1; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (j >= a && j <= b)
        cout << "D";
      else
        cout << "*";
    }
    a++;
    b--;
    cout << endl;
  }
  return 0;
}
