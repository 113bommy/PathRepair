#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d = -99999999, e, f, mas[105];
  cin >> a >> b;
  for (c = 0; c < a; c++) {
    cin >> mas[c];
  }
  for (c = 0; c < a; c++) {
    if (d < mas[c] - mas[c + 1]) {
      d = mas[c] - mas[c + 1];
    }
  }
  if (d - b < 0)
    cout << 0;
  else
    cout << d - b;
}
