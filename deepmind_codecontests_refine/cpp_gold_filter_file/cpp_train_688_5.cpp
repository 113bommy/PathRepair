#include <bits/stdc++.h>
using namespace std;
bool p(int n) {
  int a = sqrt(n);
  return (a * a == n);
}
int main() {
  int f1, f2, n, i, j, f3;
  while (cin >> n) {
    f1 = 0;
    f2 = 1;
    f3 = 0;
    int a[1001];
    for (i = 0; i < n; i++) {
      f3 = f1 + f2;
      a[i] = f3;
      f1 = f2;
      f2 = f3;
    }
    for (i = 1; i <= n; i++) {
      if (p(5 * i * i + 4) || p(5 * i * i - 4))
        cout << "O";
      else
        cout << "o";
    }
    cout << endl;
  }
}
