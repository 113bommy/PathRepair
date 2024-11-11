#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int p, q, r, s;
    p = a * d;
    q = b * c;
    r = (a - c + 1) * b;
    s = (b - d + 1) * a;
    int x = max(max(p, q), max(r, s));
    cout << x << endl;
  }
}
