#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int main() {
  int n, a, b, c, j;
  bool t = false;
  cin >> n;
  for (int i = 0; i < (4); ++i) {
    cin >> a >> b;
    if (a < 1 || b < 1)
      c = n + 1;
    else
      c = min(a, b);
    cin >> a >> b;
    if (a < 1 || b < 1)
      j = n + 1;
    else
      j = min(a, b);
    if (n >= c + j) {
      t = true;
      a = i + 1;
      break;
    }
  }
  if (t)
    cout << a << " " << c << " " << n - c;
  else
    cout << -1;
}
