#include <bits/stdc++.h>
using namespace std;
double s;
double a, b, c;
int main() {
  while (cin >> s) {
    cin >> a >> b >> c;
    if (a + b + c == 0) {
      cout << 1.0 * s << " " << 0 << " " << 0 << endl;
      continue;
    }
    cout << setiosflags(ios::fixed) << setprecision(8) << s / (a + b + c) * a
         << " " << s / (a + b + c) * b << " " << s / (a + b + c) * c << endl;
  }
}
