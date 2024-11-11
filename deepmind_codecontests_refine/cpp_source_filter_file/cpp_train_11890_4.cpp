#include <bits/stdc++.h>
using namespace std;
bool lt(int a, int b) {
  cout << a << ' ' << b << endl;
  char c;
  cin >> c;
  return c == '<';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = 1, b = 2, c = 3;
    if (lt(b, a)) swap(a, b);
    for (int i = 4; i <= 2 * n; i++) {
      int d = i;
      if (lt(c, d)) swap(d, c);
      if (lt(a, d)) {
        swap(a, d);
        swap(b, c);
      }
    }
    for (int i = 1; i <= 2 * n; i++)
      if (i != a && i != b && i != c)
        for (int j = i + 1; j <= 2 * n; j++)
          if (j != a && j != b && j != c) lt(i, j);
    cout << '!' << endl;
  }
}
