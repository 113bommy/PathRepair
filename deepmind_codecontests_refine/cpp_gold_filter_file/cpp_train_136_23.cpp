#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a{};
  long long int b{};
  long long int c{};
  double z{};
  long long int s{};
  long long int e{};
  double d{};
  cin >> a >> b >> c;
  if (a - b == c * b)
    cout << a - b;
  else {
    z = (static_cast<double>((a * c) - (b * c))) / (static_cast<double>(b));
    s = ((a * c) - (b * c)) / b;
    d = static_cast<double>(s);
    if (z > d) {
      e = static_cast<int>(z);
      cout << s + 1;
    } else {
      cout << s;
    }
  }
  return 0;
}
