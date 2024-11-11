#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int b, p, f;
    int h, c;
    cin >> b >> p >> f >> h >> c;
    if (b >= p * 2 + f * 2)
      cout << p * h + f * c << endl;
    else {
      if (c >= h) {
        cout << min(b / 2, f) * c + min((b - min(b / 2, f) * 2) / 2, p) * h
             << endl;
      } else
        cout << min(b / 2, p) * h + min((b - min(b / 2, p) * 2) / 2, f) * c
             << endl;
    }
  }
  return 0;
}
