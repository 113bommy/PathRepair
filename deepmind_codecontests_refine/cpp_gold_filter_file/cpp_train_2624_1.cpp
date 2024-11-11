#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, s, b, c, d;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    d = 0;
    cin >> s;
    b = s / a;
    c = s % a;
    for (int j = 1; j <= a; j++) {
      if (j <= c)
        d = d + pow(b + 1, 2);
      else
        d = d + pow(b, 2);
    }
    cout << d << endl;
  }
}
