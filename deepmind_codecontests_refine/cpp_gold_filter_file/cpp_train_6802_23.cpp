#include <bits/stdc++.h>
using namespace std;
long double S;
int a, b, c;
int main() {
  cin >> S >> a >> b >> c;
  if (a + b + c == 0)
    cout << 0 << " " << 0 << " " << S << endl;
  else {
    cout << fixed << setprecision(11) << S * a / (a + b + c) << " "
         << S * b / (a + b + c) << " " << S * c / (a + b + c) << endl;
  }
}
